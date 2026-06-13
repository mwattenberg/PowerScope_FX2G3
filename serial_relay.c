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
 * Single-producer (CS ISR) / single-consumer (SerialRelay_Run) FIFO that
 * decouples frame capture from USB forwarding. The ISR appends each
 * CS-framed transaction; Run() packs the accumulated bytes into full
 * USB_PACKET_SIZE transfers. This replaces the previous single staging
 * buffer, whose one-frame depth silently dropped a sample whenever a new CS
 * edge arrived before the prior frame had been forwarded — the cause of the
 * ~15% loss seen at 5 kHz. SPSC correctness relies on the single Cortex-M4
 * core: the CS ISR (priority 5) runs atomically with respect to the main-loop
 * consumer, and each index is a naturally-aligned 32-bit store. */
#define SPI_RING_SIZE 4096U  /* power of two; ~50 ms of 5 kHz x 16-byte frames */
static uint8_t           spiRing[SPI_RING_SIZE];
static volatile uint32_t spiRingHead = 0;   /* free-running, written by CS ISR */
static volatile uint32_t spiRingTail = 0;   /* free-running, written by Run()  */
static uint32_t          spiLastHead = 0;   /* Run()-private: detects producer idle */
static volatile bool     spiOverflow = false;
static uint8_t spiIsrBuf[USB_PACKET_SIZE];  /* ISR scratch: drains the RX FIFO  */
static uint8_t spiTxBuf[USB_PACKET_SIZE];   /* Run() scratch: linear USB payload */

/*******************************************************************************
 * CS rising-edge ISR — fires when the SPI master deasserts chip select,
 * signalling end of transmission. Drains whatever bytes landed in the SPI RX
 * FIFO and flags them ready for USB forwarding. No frame interpretation is done.
 ******************************************************************************/

static void CS_ISR(void)
{
    Cy_GPIO_ClearInterrupt(SR_CS_PORT, SR_CS_PIN);

    /* Read the CS pin level to distinguish falling edge (CS asserted = transaction
     * start) from rising edge (CS deasserted = transaction end). The device
     * configurator fires this ISR on both edges so we handle both here. */
    bool csHigh = Cy_GPIO_Read(SR_CS_PORT, SR_CS_PIN);

    if (activeIface == SR_IFACE_SPI) {
        if (!csHigh) {
            /* Falling edge: new transaction starting. Do NOT clear the RX FIFO
             * here. The falling edge coincides with the master starting to clock
             * data, so a clear that is delayed (even a few µs, e.g. by the
             * priority-4 USB ISR) wipes the first byte(s) of the current frame —
             * the host then sees a short frame and drops the sample. Capture is
             * append-only: every byte the SCB receives is forwarded, and the
             * host reassembles fixed-size frames from the byte stream. A delayed
             * rising edge merely concatenates two frames in the FIFO, which
             * decode correctly downstream. Resync after a genuine fault is
             * handled by the explicit FIFO flush in FlushRxState() (START/STOP
             * /interface-switch), not per-frame. */
        } else {
            /* Rising edge: transaction complete.
             * The shift register needs a few peripheral clocks after the last SCLK
             * edge to latch the final byte into the RX FIFO.  A fixed NOP delay is
             * sufficient and avoids an unbounded spin that would block the main loop
             * if the SPI clock stopped (e.g. master enabled the SCB mid-transaction). */
            Cy_SysLib_DelayUs(1U);

            uint32_t n = Cy_SCB_SPI_GetNumInRxFifo(SPI_HW);
            if (n > USB_PACKET_SIZE) n = USB_PACKET_SIZE;
            if (n > 0U) {
                Cy_SCB_SPI_ReadArray(SPI_HW, spiIsrBuf, n);

                /* Append the frame to the ring. spiRingTail is owned by Run();
                 * reading a slightly stale value here only under-reports free
                 * space, which is safe (conservative). */
                uint32_t used      = spiRingHead - spiRingTail;
                uint32_t freeSpace = SPI_RING_SIZE - used;
                if (n > freeSpace) {
                    /* Ring full: Run()/host not draining fast enough. Drop this
                     * frame rather than corrupt the byte stream, and latch it. */
                    spiOverflow = true;
                } else {
                    uint32_t head       = spiRingHead & (SPI_RING_SIZE - 1U);
                    uint32_t firstChunk = SPI_RING_SIZE - head;
                    if (firstChunk > n) firstChunk = n;
                    memcpy(&spiRing[head], spiIsrBuf, firstChunk);
                    if (n > firstChunk)
                        memcpy(&spiRing[0], &spiIsrBuf[firstChunk], n - firstChunk);
                    spiRingHead += n;  /* publish after the data is in place */
                }
            }
        }
    } else {
        Cy_SCB_SPI_ClearRxFifo(SPI_HW);
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
    cy_stc_sysint_t csIrqCfg = { .intrSrc = SR_CS_IRQ, .intrPriority = 5 };
    Cy_SysInt_Init(&csIrqCfg, CS_ISR);
    NVIC_ClearPendingIRQ(SR_CS_IRQ);
    NVIC_EnableIRQ(SR_CS_IRQ);

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
            uint32_t head = spiRingHead;            /* single snapshot */

            /* Burst-drain every full packet available this iteration instead of
             * one-per-loop. After a host stall the ring holds several packets;
             * forwarding them back-to-back within a single 100µs tick clears the
             * backlog quickly rather than bleeding it off at 512 B / 100µs — the
             * slow drain that previously let the ring overflow and drop frames.
             * Stops on the first USB_Stream_Write failure (no free DMA buffer =
             * host back-pressure); those bytes stay in the ring, retried next loop. */
            while ((head - spiRingTail) >= USB_PACKET_SIZE) {
                uint32_t tailIdx    = spiRingTail & (SPI_RING_SIZE - 1U);
                uint32_t firstChunk = SPI_RING_SIZE - tailIdx;
                if (firstChunk > USB_PACKET_SIZE) firstChunk = USB_PACKET_SIZE;
                memcpy(spiTxBuf, &spiRing[tailIdx], firstChunk);
                if (USB_PACKET_SIZE > firstChunk)
                    memcpy(&spiTxBuf[firstChunk], &spiRing[0], USB_PACKET_SIZE - firstChunk);

                if (!USB_Stream_Write(spiTxBuf, USB_PACKET_SIZE))
                    break;
                spiRingTail += USB_PACKET_SIZE;  /* release the slots */
            }

            /* Forward a trailing partial packet once the producer has gone quiet
             * (head unchanged since last iteration) so low-rate streams aren't
             * stuck waiting for a full packet to accumulate. */
            uint32_t used = head - spiRingTail;
            if (used > 0U && head == spiLastHead) {
                uint32_t tailIdx    = spiRingTail & (SPI_RING_SIZE - 1U);
                uint32_t firstChunk = SPI_RING_SIZE - tailIdx;
                if (firstChunk > used) firstChunk = used;
                memcpy(spiTxBuf, &spiRing[tailIdx], firstChunk);
                if (used > firstChunk)
                    memcpy(&spiTxBuf[firstChunk], &spiRing[0], used - firstChunk);

                if (USB_Stream_Write(spiTxBuf, used)) {
                    spiRingTail += used;  /* release the slots */
                }
            }
            spiLastHead = head;
        }
    }

    /* Yield ~100µs per loop iteration. Without this the CM4 hammers SCB and
     * DMA registers at full speed, starving the USB stack and SWD debugger.
     * The burst-drain loop above already clears any SPI backlog within a single
     * tick, so a backlog no longer needs the loop to spin faster than this. */
    Cy_SysLib_DelayUs(100U);
}
