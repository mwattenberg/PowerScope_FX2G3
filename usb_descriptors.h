/****************###############################################################
* \file usb_descriptors.h
* \brief Declares the custom USB descriptors for the FX2G3 RTBox.
*
* Note: This file bypasses PSoC 6 standard usbdev middleware dependencies.
****************################################################***************/

#ifndef USB_DESCRIPTORS_H
#define USB_DESCRIPTORS_H

#include "cy_pdl.h"

#define MS_VENDOR_CODE      (0xF0)

/* External declarations of descriptors so they can be registered with the USBD stack */
extern const uint8_t CyFxUSB20DeviceDscr[];
extern const uint8_t CyFxUSBDeviceQualDscr[];
extern const uint8_t CyFxUSBBOSDscr[];
extern const uint8_t CyFxUSBHSConfigDscr[];
extern const uint8_t CyFxUSBFSConfigDscr[];
extern const uint8_t CyFxUSBStringLangIDDscr[];
extern const uint8_t CyFxUSBManufactureDscr[];
extern const uint8_t CyFxUSBProductDscr[];
extern const uint8_t CyFxUSBConfigDscrStr[];
extern const uint8_t CyFxUSBIntfDscrStr[];

/* WinUSB Microsoft OS descriptors */
extern const uint8_t glOsString[];
extern const uint8_t glOsCompatibilityId[];
extern const uint8_t glOsFeature[];

#endif /* USB_DESCRIPTORS_H */
