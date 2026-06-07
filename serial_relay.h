/*******************************************************************************
 * serial_relay.h
 *
 * Transparent serial-to-USB relay for FX2G3.
 * Receives raw bytes from UART or SPI and forwards them over USB without
 * any interpretation of the data. The active interface is selected at
 * runtime by the host via USB vendor commands.
 *
 * USB vendor commands:
 *   0xA0  REQ_START              — begin forwarding to USB
 *   0xA1  REQ_STOP               — stop forwarding
 *   0xA2  REQ_SET_BUF_THRESHOLD  wValue: bytes (1..USB_PACKET_SIZE), UART only
 *   0xA3  REQ_SET_BAUD           wValue: baud[15:0], wIndex: baud[31:16], UART only
 *   0xA4  REQ_SET_INTERFACE      wValue: 0=UART, 1=SPI
 ******************************************************************************/

#ifndef SERIAL_RELAY_H_
#define SERIAL_RELAY_H_

#include <stdint.h>
#include "cy_usb_usbd.h"

/* CS pin used as the SPI end-of-transaction signal (rising edge ISR).
 * Override these three defines before including this header if your board
 * uses a different pin — no other code changes required. */
#ifndef SR_CS_PORT
#define SR_CS_PORT  LED1_PORT
#endif
#ifndef SR_CS_PIN
#define SR_CS_PIN   LED1_PIN
#endif
#ifndef SR_CS_IRQ
/* LED1_IRQ expands to ioss_interrupts_gpio_4_IRQn which does not exist on
 * CYUSB2318. The correct FX2G3 enumerator uses the _dpslp_ infix. */
//#define SR_CS_IRQ   ioss_interrupts_gpio_dpslp_4_IRQn
#define SR_CS_IRQ   ioss_interrupts_gpio_dpslp_4_IRQn
#endif



/* Initialize the relay and register the USB vendor command callback.
 * Must be called after UART/SPI peripheral init and before USB_Stream_Init(). */
void SerialRelay_Init(void);

/* Call repeatedly from the main loop to drain the RX FIFO and forward data. */
void SerialRelay_Run(void);

/* USB vendor command handler — registered with usb_stream internally.
 * Exposed here for documentation; do not call directly. */
void SerialRelay_VendorCmdHandler(cy_stc_usb_usbd_ctxt_t *pUsbdCtxt,
                                  uint8_t  bRequest,
                                  uint16_t wValue,
                                  uint16_t wIndex,
                                  uint16_t wLength);

#endif /* SERIAL_RELAY_H_ */
