/*******************************************************************************
 * serial_relay.c
 *
 * Transparent serial-to-USB relay for FX2G3.
 * Receives raw bytes from UART or SPI and forwards them over USB without
 * any interpretation of the data.
 ******************************************************************************/

#include "serial_relay.h"
#include "usb_stream.h"
#include <string.h>
#include "cy_pdl.h"
#include "cy_debug.h"
#include "cy_scb_spi.h"
#include "cy_scb_uart.h"
#include "cy_sysint.h"
#include "cy_gpio.h"
#include "cycfg_peripherals.h"
#include "cycfg_pins.h"

typedef enum { SR_IFACE_UART = 0, SR_IFACE_SPI = 1 } sr_iface_t;

static volatile sr_iface_t activeIface     = SR_IFACE_UART;
static volatile bool       streamingEnabled = false;

/* UART accumulation state */
static volatile uint32_t rxBufThreshold = USB_PACKET_SIZE;
static uint8_t  uartRxBuf[USB_PACKET_SIZE];
static uint32_t uartRxCount = 0;

/* SPI receive ring buffer.
 * Producer / single-consumer (SerialRelay_Run) FIFO that decouples capture
 * from USB forwarding. Bytes are appended by the SPI RX-FIFO level ISR
 * (SPI_RX_ISR) and, for the sub-trigger-level tail, by SerialRelay_Run() with
 * SPI_IRQ masked — the two producers are mutually exclusive, so spiRingHead has
 * a single writer at any instant. Run() packs the accumulated bytes into full
 * USB_PACKET_SIZE transfers. Capture is append-only: every received byte is
 * forwarded in order and the host reassembles fixed-size frames from the byte
 * stream; resync after a fault is the FIFO flush in FlushRxState(), not per
 * frame. Each index is a naturally-aligned 32-bit store. */
#define SPI_RING_SIZE 4096U  /* power of two; ~2 ms of 1.8 MB/s SPI traffic */
static uint8_t           spiRing[SPI_RING_SIZE];
static volatile uint32_t spiRingHead = 0;   /* free-running, written by producer(s) */
static volatile uint32_t spiRingTail = 0;   /* free-running, written by Run()        */
static uint32_t          spiLastHead = 0;   /* Run()-private: detects producer idle  */
static volatile bool     spiOverflow = false;
static uint8_t spiIsrBuf[USB_PACKET_SIZE];  /* scratch: drains the RX FIFO       */
static uint8_t spiTxBuf[USB_PACKET_SIZE];   /* Run() scratch: linear USB payload */

/*******************************************************************************
 * SPI RX capture — drains the SCB RX FIFO into the ring buffer.
 *
 * Driven by the RX-FIFO level interrupt (configured trigger = 63, i.e. fires
 * once the FIFO holds >=64 bytes) instead of a per-transaction CS edge: at
 * ~1.8 MB/s that is ~one interrupt per 64 bytes (~28 kHz) rather than one per
 * 18-byte frame (~100 kHz) — roughly a 4x cut in ISR rate, and it drops the
 * 1 us/frame settling spin the CS ISR needed. The sub-threshold tail (last
 * <64 bytes of a burst, or low-rate streams that never reach the trigger) is
 * drained by SerialRelay_Run() with SPI_IRQ masked.
 ******************************************************************************/

/* Append all bytes currently in the SPI RX FIFO to the ring. The caller must
 * guarantee mutual exclusion with the other producer: the ISR runs atomically
 * with respect to the main loop, and Run() masks SPI_IRQ around its call, so
 * spiRingHead is only ever advanced from one context at a time. spiRingTail is
 * owned by Run(); a slightly stale read here only under-reports free space,
 * which is conservative and safe. */
static void SpiDrainFifoToRing(void)
{
    uint32_t n = Cy_SCB_SPI_GetNumInRxFifo(SPI_HW);
    if (n == 0U) return;
    if (n > USB_PACKET_SIZE) n = USB_PACKET_SIZE;
    Cy_SCB_SPI_ReadArray(SPI_HW, spiIsrBuf, n);

    uint32_t used      = spiRingHead - spiRingTail;
    uint32_t freeSpace = SPI_RING_SIZE - used;
    if (n > freeSpace) {
        /* Ring full: Run()/host not draining fast enough. Drop these bytes
         * rather than corrupt the byte stream, and latch it for logging. */
        spiOverflow = true;
        return;
    }

    uint32_t head       = spiRingHead & (SPI_RING_SIZE - 1U);
    uint32_t firstChunk = SPI_RING_SIZE - head;
    if (firstChunk > n) firstChunk = n;
    memcpy(&spiRing[head], spiIsrBuf, firstChunk);
    if (n > firstChunk)
        memcpy(&spiRing[0], &spiIsrBuf[firstChunk], n - firstChunk);
    spiRingHead += n;  /* publish after the data is in place */
}

/* SPI RX-FIFO level ISR (SCB5). Drains the FIFO, then clears the level cause;
 * because the FIFO is emptied first it drops below the trigger and the cause
 * does not immediately re-assert. */
static void SPI_RX_ISR(void)
{
    if (Cy_SCB_GetRxInterruptStatusMasked(SPI_HW) & CY_SCB_RX_INTR_LEVEL) {
        SpiDrainFifoToRing();
        Cy_SCB_ClearRxInterrupt(SPI_HW, CY_SCB_RX_INTR_LEVEL);
    }
}

/*******************************************************************************
 * Internal helpers
 ******************************************************************************/

static void FlushRxState(void)
{
    uartRxCount = 0;
    spiRingHead = 0;
    spiRingTail = 0;
    spiLastHead = 0;
    spiOverflow = false;

    /* Deliberate resync point (START/STOP/interface-switch only, never mid-
     * stream): discard any stale or partial bytes so the next frame starts
     * FIFO-aligned. Safe here because this runs from the priority-4 vendor/
     * switch context, not racing a live transaction. */
    if (activeIface == SR_IFACE_SPI) {
        Cy_SCB_SPI_ClearRxFifo(SPI_HW);
        Cy_SCB_ClearRxInterrupt(SPI_HW, CY_SCB_RX_INTR_LEVEL);
    }
}

static void SwitchInterface(sr_iface_t iface)
{
    FlushRxState();
    activeIface = iface;

    if (iface == SR_IFACE_SPI) {
        Cy_SCB_UART_Disable(UART_HW, NULL);
        Cy_SCB_SPI_Enable(SPI_HW);
    } else {
        Cy_SCB_SPI_Disable(SPI_HW, NULL);
        Cy_SCB_UART_Enable(UART_HW);
    }

    DBG_APP_INFO("[SR] Interface switched to %s\r\n",
                 (iface == SR_IFACE_SPI) ? "SPI" : "UART");
}

/*******************************************************************************
 * USB vendor command handler
 ******************************************************************************/

void SerialRelay_VendorCmdHandler(cy_stc_usb_usbd_ctxt_t *pUsbdCtxt,
                                  uint8_t  bRequest,
                                  uint16_t wValue,
                                  uint16_t wIndex,
                                  uint16_t wLength)
{
    (void)wLength;

    switch (bRequest)
    {
        case 0xA0: /* REQ_START */
            FlushRxState();
            streamingEnabled = true;
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            break;

        case 0xA1: /* REQ_STOP */
            streamingEnabled = false;
            FlushRxState();
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            break;

        case 0xA2: /* REQ_SET_BUF_THRESHOLD — UART only */
        {
            uint32_t threshold = (uint32_t)wValue;
            if (threshold < 1U)              threshold = 1U;
            if (threshold > USB_PACKET_SIZE) threshold = USB_PACKET_SIZE;
            rxBufThreshold = threshold;
            DBG_APP_INFO("[SR] BufThreshold set to %u\r\n", (unsigned)threshold);
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            break;
        }

        case 0xA3: /* REQ_SET_BAUD — UART only; SPI clock is driven by the master */
        {
            if (activeIface != SR_IFACE_UART) {
                DBG_APP_INFO("[SR] SET_BAUD ignored: SPI mode active\r\n");
                Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
                break;
            }

            uint32_t newBaud = (uint32_t)wValue | ((uint32_t)wIndex << 16);
            if (newBaud >= 300U && newBaud <= 6000000U) {
                /* div_x32 = (PERI_CLK * 32) / (baud * 8) = (PERI_CLK * 4) / baud */
                uint32_t div_x32 = (Cy_SysClk_ClkPeriGetFrequency() * 4U) / newBaud;
                uint32_t intDiv  = (div_x32 / 32U) - 1U;
                uint32_t fracDiv = div_x32 % 32U;

                Cy_SCB_UART_Disable(UART_HW, NULL);
                Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_5_BIT, 0U);
                Cy_SysClk_PeriphSetFracDivider(CY_SYSCLK_DIV_16_5_BIT, 0U, intDiv, fracDiv);
                Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_5_BIT, 0U);
                Cy_SysLib_DelayUs(10U);
                Cy_SCB_UART_Enable(UART_HW);

                DBG_APP_INFO("[SR] Baud=%u intDiv=%u fracDiv=%u\r\n",
                             (unsigned)newBaud, (unsigned)intDiv, (unsigned)fracDiv);
            } else {
                DBG_APP_INFO("[SR] SET_BAUD ignored: out of range (%u)\r\n", (unsigned)newBaud);
            }
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            break;
        }

        case 0xA4: /* REQ_SET_INTERFACE — wValue: 0=UART, 1=SPI */
            SwitchInterface((wValue == 1U) ? SR_IFACE_SPI : SR_IFACE_UART);
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            break;

        default:
            Cy_USB_USBD_EndpSetClearStall(pUsbdCtxt, 0, CY_USB_ENDP_DIR_IN, true);
            break;
    }
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

void SerialRelay_Init(void)
{
    /* SPI RX path is interrupt-driven off the SCB RX-FIFO level (trigger 63,
     * enabled in SPI_config.rxFifoIntEnableMask, applied by Cy_SCB_SPI_Init).
     * Here we only vector and enable the NVIC line. The interrupt cannot fire
     * until SPI is enabled (SwitchInterface), so enabling it unconditionally is
     * safe — UART mode never clocks the SPI RX FIFO. */
    cy_stc_sysint_t spiIrqCfg = { .intrSrc = SPI_IRQ, .intrPriority = 5 };
    Cy_SysInt_Init(&spiIrqCfg, SPI_RX_ISR);
    NVIC_ClearPendingIRQ(SPI_IRQ);
    NVIC_EnableIRQ(SPI_IRQ);

    USB_Stream_RegisterVendorCallback(SerialRelay_VendorCmdHandler);
}

void SerialRelay_Run(void)
{
    if (activeIface == SR_IFACE_UART) {
        /* Accumulate UART RX bytes and forward once the threshold is reached.
         * The FIFO is drained even when not streaming to prevent overflow. */
        uint32_t rxAvail = Cy_SCB_UART_GetNumInRxFifo(UART_HW);
        if (rxAvail > 0U) {
            uint32_t space = USB_PACKET_SIZE - uartRxCount;
            uint32_t n = (rxAvail > space) ? space : rxAvail;
            Cy_SCB_UART_GetArray(UART_HW, &uartRxBuf[uartRxCount], n);
            uartRxCount += n;
        }

        if (!streamingEnabled || !usbConfigured) {
            uartRxCount = 0;
        } else if (uartRxCount >= rxBufThreshold) {
            if (USB_Stream_Write(uartRxBuf, uartRxCount)) {
                uartRxCount = 0;
            }
            /* On failure (no free DMA buffer) keep the data and retry next
             * loop; further RX bytes accumulate until the buffer is full. */
        }
    } else { /* SR_IFACE_SPI */
        if (spiOverflow) {
            spiOverflow = false;
            DBG_APP_INFO("[SR] SPI ring overflow — frames dropped (not draining)\r\n");
        }

        if (!streamingEnabled || !usbConfigured) {
            /* Discard whatever was captured while not streaming. */
            spiRingTail = spiRingHead;
            spiLastHead = spiRingHead;
        } else {
            /* Drain the sub-trigger-level tail the level ISR leaves behind
             * (last <64 bytes of a burst, or low-rate streams that never reach
             * the trigger). Mask SPI_IRQ so this never races the ISR on the FIFO
             * or on spiRingHead; a level event raised while masked stays pending
             * and runs on re-enable. */
            NVIC_DisableIRQ(SPI_IRQ);
            SpiDrainFifoToRing();
            NVIC_EnableIRQ(SPI_IRQ);

            uint32_t head = spiRingHead;            /* single snapshot */
            uint32_t used = head - spiRingTail;

            /* Forward at most ONE USB buffer per loop iteration. Committing
             * several buffers back-to-back within a single iteration (the former
             * burst-drain) duplicated data on the wire under back-pressure: the
             * HBDMA consume path needs the per-iteration 100µs yield between
             * commits, and without it the channel re-transmits — inflating
             * throughput (~2.2x observed) until the host is overwhelmed and the
             * stream collapses. One 512 B commit per ~100µs still sustains
             * ~5 MB/s, far above the SPI input rate, so a single flush is both
             * clean and sufficient. Send a full packet when one is available;
             * otherwise flush a partial once the producer has gone quiet for a
             * loop iteration (bounds latency for low-rate streams). */
            bool flush = (used >= USB_PACKET_SIZE) ||
                         (used > 0U && head == spiLastHead);
            if (flush) {
                uint32_t toSend     = (used > USB_PACKET_SIZE) ? USB_PACKET_SIZE : used;
                uint32_t tailIdx    = spiRingTail & (SPI_RING_SIZE - 1U);
                uint32_t firstChunk = SPI_RING_SIZE - tailIdx;
                if (firstChunk > toSend) firstChunk = toSend;
                memcpy(spiTxBuf, &spiRing[tailIdx], firstChunk);
                if (toSend > firstChunk)
                    memcpy(&spiTxBuf[firstChunk], &spiRing[0], toSend - firstChunk);

                if (USB_Stream_Write(spiTxBuf, toSend)) {
                    spiRingTail += toSend;  /* release the slots */
                }
                /* On USB failure keep the bytes; the ring retains them and we
                 * retry next loop with no data loss. */
            }
            spiLastHead = head;
        }
    }

    /* Yield ~100µs per loop iteration. Without this the CM4 hammers SCB and
     * DMA registers at full speed, starving the USB stack and SWD debugger.
     * It also paces USB buffer commits: the HBDMA consume path duplicates data
     * if buffers are committed back-to-back without this gap (see SPI flush). */
    Cy_SysLib_DelayUs(100U);
}
