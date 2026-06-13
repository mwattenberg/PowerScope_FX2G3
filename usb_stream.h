/*******************************************************************************
 * usb_stream.h
 *
 * USB high-speed bulk streaming layer for FX2G3.
 * Owns: USB stack init, HBDMA channel for EP1 IN, USB event callbacks.
 * Does not know about UART, SPI, or application data format.
 *
 * Usage:
 *   1. Optionally call USB_Stream_RegisterVendorCallback() to handle
 *      application-specific vendor control requests before USB_Stream_Init().
 *   2. Call USB_Stream_Init() once at startup.
 *   3. Call USB_Stream_Write() from the application loop to send data.
 ******************************************************************************/

#ifndef USB_STREAM_H_
#define USB_STREAM_H_

#include <stdint.h>
#include <stdbool.h>
#include "cy_usb_common.h"
#include "cy_usb_usbd.h"

/* Size of each EP1-IN DMA buffer / relay commit chunk. A multiple of the 512 B
 * HS bulk wire packet (the wire packet is set separately as usbMaxPktSize /
 * endpoint maxPktSize in usb_stream.c): the USB block fragments one buffer into
 * that many wire packets. Larger buffers amortise the HBDMA GetBuffer/
 * CommitBuffer cost over more bytes, raising drain throughput WITHOUT committing
 * buffers back-to-back (which the HBDMA path duplicates — see serial_relay.c).
 * 2048 = 4 wire packets. With count=8 the pool use is 16 KB of the 64 KB. */
#define USB_PACKET_SIZE  2048U

/* Callback type for unhandled vendor control requests.
 * The USB layer calls this for any vendor bRequest not handled internally.
 * The handler must call Cy_USBD_SendAckSetupDataStatusStage() or stall EP0. */
typedef void (*USB_VendorCmdCallback_t)(cy_stc_usb_usbd_ctxt_t *pUsbdCtxt,
                                        uint8_t  bRequest,
                                        uint16_t wValue,
                                        uint16_t wIndex,
                                        uint16_t wLength);

/* Register a callback for unhandled vendor requests. Call before USB_Stream_Init(). */
void USB_Stream_RegisterVendorCallback(USB_VendorCmdCallback_t cb);

/* Initialize the USB stack, HBDMA, and EP1 IN. */
void USB_Stream_Init(void);

/* Send data over EP1 IN. Returns true on success, false if DMA is busy.
 * Caller retains ownership of data[] and may retry on false. */
bool USB_Stream_Write(const uint8_t *data, uint32_t length);

/* True once the host has selected a configuration. Cleared on bus reset. */
extern volatile bool usbConfigured;

#endif /* USB_STREAM_H_ */
