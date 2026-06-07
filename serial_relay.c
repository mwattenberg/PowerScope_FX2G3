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

/* SPI receive state — written by CS ISR, consumed by Run() */
static volatile bool     spiRxReady = false;
static volatile uint32_t spiRxLen   = 0;
static uint8_t spiStagingBuf[USB_PACKET_SIZE];
static uint8_t spiIsrBuf[USB_PACKET_SIZE];

/*******************************************************************************
 * CS rising-edge ISR — fires when the SPI master deasserts chip select,
 * signalling end of transmission. Drains whatever bytes landed in the SPI RX
 * FIFO and flags them ready for USB forwarding. No frame interpretation is done.
 ******************************************************************************/

static void CS_ISR(void)
{
    Cy_GPIO_ClearInterrupt(SR_CS_PORT, SR_CS_PIN);

    if (activeIface == SR_IFACE_SPI) {
        uint32_t n = Cy_SCB_SPI_GetNumInRxFifo(SPI_HW);
        if (n > USB_PACKET_SIZE) n = USB_PACKET_SIZE;
        if (n > 0U) {
            Cy_SCB_SPI_ReadArray(SPI_HW, spiIsrBuf, n);
            memcpy(spiStagingBuf, spiIsrBuf, n);
            spiRxLen   = n;
            spiRxReady = true;
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
    spiRxReady  = false;
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
                /* PERI_CLK = 75 MHz, oversample = 8x
                 * div_x32 = (75 000 000 * 32) / (baud * 8) = 300 000 000 / baud */
                uint32_t div_x32 = 300000000UL / newBaud;
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
    /* Register CS rising-edge ISR for SPI end-of-transaction detection.
     * The device configurator has already configured the pin for rising-edge
     * interrupts; we just wire the IRQ line to CS_ISR here. */
    cy_stc_sysint_t csIrqCfg = { .intrSrc = SR_CS_IRQ, .intrPriority = 5 };
    Cy_SysInt_Init(&csIrqCfg, CS_ISR);
    NVIC_ClearPendingIRQ(SR_CS_IRQ);
    NVIC_EnableIRQ(SR_CS_IRQ);

    USB_Stream_RegisterVendorCallback(SerialRelay_VendorCmdHandler);
}

void SerialRelay_Run(void)
{
    if (activeIface == SR_IFACE_UART) {
        uint32_t rxAvail = Cy_SCB_UART_GetNumInRxFifo(UART_HW);

        if (streamingEnabled && usbConfigured) {
            if (rxAvail > 0) {
                uint32_t space  = USB_PACKET_SIZE - uartRxCount;
                uint32_t toRead = (rxAvail < space) ? rxAvail : space;
                Cy_SCB_UART_GetArray(UART_HW, &uartRxBuf[uartRxCount], toRead);
                uartRxCount += toRead;
            }
            if (uartRxCount >= rxBufThreshold) {
                if (USB_Stream_Write(uartRxBuf, uartRxCount))
                    uartRxCount = 0;
            }
        } else {
            /* Not streaming — drain to prevent FIFO overflow */
            if (rxAvail > 0) {
                uint8_t  discard[16];
                uint32_t n = (rxAvail > 16U) ? 16U : rxAvail;
                Cy_SCB_UART_GetArray(UART_HW, discard, n);
            }
            uartRxCount = 0;
        }

    } else { /* SR_IFACE_SPI */

        if (streamingEnabled && usbConfigured) {
            if (spiRxReady) {
                uint32_t len = spiRxLen;
                spiRxReady = false;
                USB_Stream_Write(spiStagingBuf, len);
            }
        } else {
            spiRxReady = false;
        }
    }
}
