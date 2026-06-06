/****************###############################################################
* \file usb_descriptors.c
* \brief Defines the custom USB descriptors for the FX2G3 RTBox.
*
* Note: This file bypasses PSoC 6 standard usbdev middleware dependencies.
****************################################################***************/

#include "usb_descriptors.h"

/* Standard device descriptor for USB 2.0 */
const uint8_t CyFxUSB20DeviceDscr[] __attribute__ ((aligned (4))) =
{
    0x12,                           /* bLength: Descriptor size (18 bytes) */
    0x01,                           /* bDescriptorType: Device descriptor type */
    0x00,0x02,                      /* bcdUSB: USB 2.0 (little-endian) */
    0x00,                           /* bDeviceClass: Class defined in interface */
    0x00,                           /* bDeviceSubClass: Subclass defined in interface */
    0x00,                           /* bDeviceProtocol: Protocol defined in interface */
    0x40,                           /* bMaxPacketSize0: Max packet size for EP0 is 64 bytes */
    0xB4,0x04,                      /* idVendor: Vendor ID 0x04B4 (little-endian) */
    0x81,0x00,                      /* idProduct: Product ID 0x0081 (little-endian) */
    0x00,0x01,                      /* bcdDevice: Device release 1.00 (little-endian) */
    0x01,                           /* iManufacturer: Index of manufacturer string */
    0x02,                           /* iProduct: Index of product string */
    0x00,                           /* iSerialNumber: Index of serial number string (none) */
    0x01                            /* bNumConfigurations: Number of configurations */
};

/* Device qualifier descriptor. Required for High-Speed support */
const uint8_t CyFxUSBDeviceQualDscr[] __attribute__ ((aligned (4))) =
{
    0x0A,                           /* bLength: Descriptor size (10 bytes) */
    0x06,                           /* bDescriptorType: Device qualifier type */
    0x00,0x02,                      /* bcdUSB: USB 2.0 */
    0x00,                           /* bDeviceClass: Class defined in interface */
    0x00,                           /* bDeviceSubClass: Subclass defined in interface */
    0x00,                           /* bDeviceProtocol: Protocol defined in interface */
    0x40,                           /* bMaxPacketSize0: Max packet size for EP0 is 64 bytes */
    0x01,                           /* bNumConfigurations: Number of configurations */
    0x00                            /* Reserved: Must be zero */
};

/* Binary Object Store (BOS) Descriptor. */
const uint8_t CyFxUSBBOSDscr[] __attribute__ ((aligned (4))) =
{
    0x05,                           /* bLength: Descriptor size (5 bytes) */
    0x0F,                           /* bDescriptorType: BOS descriptor type */
    0x0C,0x00,                      /* wTotalLength: Length of BOS and sub descriptors (12 bytes) */
    0x01,                           /* bNumDeviceCaps: 1 device capability descriptor */

    /* USB 2.0 extension */
    0x07,                           /* bLength: Descriptor size (7 bytes) */
    0x10,                           /* bDescriptorType: Device capability type */
    0x02,                           /* bDevCapabilityType: USB 2.0 extension capability */
    0x1E,0x64,0x00,0x00,            /* bmAttributes: LPM support, BESL supported, etc. */
};

/* Standard High-Speed configuration descriptor (Bulk IN max packet 512 bytes) */
const uint8_t CyFxUSBHSConfigDscr[] __attribute__ ((aligned (4))) =
{
    /* Configuration descriptor */
    0x09,                           /* bLength: Descriptor size */
    0x02,                           /* bDescriptorType: Configuration descriptor type */
    0x22,0x00,                      /* wTotalLength: Total length of configuration block (34 bytes) */
    0x01,                           /* bNumInterfaces: 1 interface */
    0x01,                           /* bConfigurationValue: Configuration number 1 */
    0x03,                           /* iConfiguration: Index of configuration string */
    0xC0,                           /* bmAttributes: Self-powered, Remote wakeup disabled */
    0xFA,                           /* bMaxPower: Max power consumption (500mA) */

    /* Alternate Setting 0: Active interface setting with 1 endpoint */
    0x09,                           /* bLength: Descriptor size */
    0x04,                           /* bDescriptorType: Interface descriptor type */
    0x00,                           /* bInterfaceNumber: Interface number 0 */
    0x00,                           /* bAlternateSetting: Alternate setting 0 */
    0x01,                           /* bNumEndpoints: 1 endpoint */
    0xFF,                           /* bInterfaceClass: Vendor-Specific class */
    0x00,                           /* bInterfaceSubClass: Subclass code */
    0x00,                           /* bInterfaceProtocol: Protocol code */
    0x04,                           /* iInterface: Index of interface string */

    /* Endpoint Descriptor: Bulk IN 0x81 */
    0x07,                           /* bLength: Descriptor size */
    0x05,                           /* bDescriptorType: Endpoint descriptor type */
    0x81,                           /* bEndpointAddress: Endpoint Address (0x81, EP1 IN) */
    0x02,                           /* bmAttributes: Bulk Transfer */
    0x00,0x02,                      /* wMaxPacketSize: Max packet size 512 bytes (little-endian) */
    0x00,                           /* bInterval: Interval (0 for bulk) */

    /* Alternate Setting 1: Idle interface setting with 0 endpoints (stops streaming) */
    0x09,                           /* bLength: Descriptor size */
    0x04,                           /* bDescriptorType: Interface descriptor type */
    0x00,                           /* bInterfaceNumber: Interface number 0 */
    0x01,                           /* bAlternateSetting: Alternate setting 1 */
    0x00,                           /* bNumEndpoints: 0 endpoints */
    0x00,                           /* bInterfaceClass: Generic/unused */
    0x00,                           /* bInterfaceSubClass: Subclass code */
    0x00,                           /* bInterfaceProtocol: Protocol code */
    0x00                            /* iInterface: Index of interface string */
};

/* Standard Full-Speed configuration descriptor (Bulk IN max packet 64 bytes) */
const uint8_t CyFxUSBFSConfigDscr[] __attribute__ ((aligned (4))) =
{
    /* Configuration descriptor */
    0x09,                           /* bLength: Descriptor size */
    0x02,                           /* bDescriptorType: Configuration descriptor type */
    0x22,0x00,                      /* wTotalLength: Total length of configuration block (34 bytes) */
    0x01,                           /* bNumInterfaces: 1 interface */
    0x01,                           /* bConfigurationValue: Configuration number 1 */
    0x03,                           /* iConfiguration: Index of configuration string */
    0xC0,                           /* bmAttributes: Self-powered, Remote wakeup disabled */
    0xFA,                           /* bMaxPower: Max power consumption (500mA) */

    /* Alternate Setting 0: Active interface setting with 1 endpoint */
    0x09,                           /* bLength: Descriptor size */
    0x04,                           /* bDescriptorType: Interface descriptor type */
    0x00,                           /* bInterfaceNumber: Interface number 0 */
    0x00,                           /* bAlternateSetting: Alternate setting 0 */
    0x01,                           /* bNumEndpoints: 1 endpoint */
    0xFF,                           /* bInterfaceClass: Vendor-Specific class */
    0x00,                           /* bInterfaceSubClass: Subclass code */
    0x00,                           /* bInterfaceProtocol: Protocol code */
    0x04,                           /* iInterface: Index of interface string */

    /* Endpoint Descriptor: Bulk IN 0x81 */
    0x07,                           /* bLength: Descriptor size */
    0x05,                           /* bDescriptorType: Endpoint descriptor type */
    0x81,                           /* bEndpointAddress: Endpoint Address (0x81, EP1 IN) */
    0x02,                           /* bmAttributes: Bulk Transfer */
    0x40,0x00,                      /* wMaxPacketSize: Max packet size 64 bytes (little-endian) */
    0x00,                           /* bInterval: Interval (0 for bulk) */

    /* Alternate Setting 1: Idle interface setting with 0 endpoints (stops streaming) */
    0x09,                           /* bLength: Descriptor size */
    0x04,                           /* bDescriptorType: Interface descriptor type */
    0x00,                           /* bInterfaceNumber: Interface number 0 */
    0x01,                           /* bAlternateSetting: Alternate setting 1 */
    0x00,                           /* bNumEndpoints: 0 endpoints */
    0x00,                           /* bInterfaceClass: Generic/unused */
    0x00,                           /* bInterfaceSubClass: Subclass code */
    0x00,                           /* bInterfaceProtocol: Protocol code */
    0x00                            /* iInterface: Index of interface string */
};

/* Language ID String Descriptor (LangID 0x0409: US English) */
const uint8_t CyFxUSBStringLangIDDscr[] __attribute__ ((aligned (4))) =
{
    0x04,                           /* bLength: Descriptor size (4 bytes) */
    0x03,                           /* bDescriptorType: String descriptor type */
    0x09,0x04                       /* wLANGID: US English */
};

/* Manufacturer String Descriptor: "Infineon / mwattenberg" */
const uint8_t CyFxUSBManufactureDscr[] __attribute__ ((aligned (4))) =
{
    0x2E,                           /* bLength: Descriptor size */
    0x03,                           /* bDescriptorType: String descriptor type */
    'I',0x00, 'n',0x00, 'f',0x00, 'i',0x00, 'n',0x00, 'e',0x00, 'o',0x00, 'n',0x00,
    ' ',0x00, '/',0x00, ' ',0x00, 'm',0x00, 'w',0x00, 'a',0x00, 't',0x00, 't',0x00,
    'e',0x00, 'n',0x00, 'b',0x00, 'e',0x00, 'r',0x00, 'g',0x00
};

/* Product String Descriptor: "FX2G3 PowerScope" */
const uint8_t CyFxUSBProductDscr[] __attribute__ ((aligned (4))) =
{
    0x22,                           /* bLength: Descriptor size */
    0x03,                           /* bDescriptorType: String descriptor type */
    'F',0x00, 'X',0x00, '2',0x00, 'G',0x00, '3',0x00, ' ',0x00, 'P',0x00, 'o',0x00,
    'w',0x00, 'e',0x00, 'r',0x00, 'S',0x00, 'c',0x00, 'o',0x00, 'p',0x00, 'e',0x00
};

/* Configuration String Descriptor: "PowerScope Streaming Config" */
const uint8_t CyFxUSBConfigDscrStr[] __attribute__ ((aligned (4))) =
{
    0x38,                           /* bLength: Descriptor size */
    0x03,                           /* bDescriptorType: String descriptor type */
    'P',0x00, 'o',0x00, 'w',0x00, 'e',0x00, 'r',0x00, 'S',0x00, 'c',0x00, 'o',0x00,
    'p',0x00, 'e',0x00, ' ',0x00, 'S',0x00, 't',0x00, 'r',0x00, 'e',0x00, 'a',0x00,
    'm',0x00, 'i',0x00, 'n',0x00, 'g',0x00, ' ',0x00, 'C',0x00, 'o',0x00, 'n',0x00,
    'f',0x00, 'i',0x00, 'g',0x00
};

/* Interface String Descriptor: "PowerScope Data Stream" */
const uint8_t CyFxUSBIntfDscrStr[] __attribute__ ((aligned (4))) =
{
    0x2E,                           /* bLength: Descriptor size */
    0x03,                           /* bDescriptorType: String descriptor type */
    'P',0x00, 'o',0x00, 'w',0x00, 'e',0x00, 'r',0x00, 'S',0x00, 'c',0x00, 'o',0x00,
    'p',0x00, 'e',0x00, ' ',0x00, 'D',0x00, 'a',0x00, 't',0x00, 'a',0x00, ' ',0x00,
    'S',0x00, 't',0x00, 'r',0x00, 'e',0x00, 'a',0x00, 'm',0x00
};


/****************###############################################################
*               WinUSB Microsoft OS Descriptors (Auto WinUSB driver load)
****************################################################***************/

/* Microsoft OS String Descriptor (Get Descriptor, index 0xEE) */
const uint8_t glOsString[] __attribute__ ((aligned (4))) =
{
    0x12,                           /* bLength: Descriptor size (18 bytes) */
    0x03,                           /* bDescriptorType: String descriptor type */
    'M',0x00, 'S',0x00, 'F',0x00, 'T',0x00, '1',0x00, '0',0x00, '0',0x00, /* Signature: "MSFT100" */
    MS_VENDOR_CODE,                 /* bMS_VendorCode: Vendor specific request code */
    0x00                            /* bPad: Padding byte */
};

/* OS Compatible ID Feature Descriptor (Vendor request, Index 4) */
const uint8_t glOsCompatibilityId[] __attribute__ ((aligned (4))) =
{
    /* Header Section */
    0x28,0x00,0x00,0x00,            /* dwLength: Total length of descriptor (40 bytes) */
    0x00,0x01,                      /* bcdVersion: Version 1.00 */
    0x04,0x00,                      /* wIndex: Extended compatibility ID index (4) */
    0x01,                           /* bCount: 1 custom property section */
    0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* Reserved */

    /* Custom Section 1 (Interface 0) */
    0x00,                           /* bFirstInterfaceNumber: Interface number 0 */
    0x01,                           /* Reserved: Must be 1 */
    'W', 'I', 'N', 'U', 'S', 'B', 0x00, 0x00, /* bCompatibleID: "WINUSB" */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* bSubCompatibleID: none */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /* Reserved */
};

/* OS Extended Properties / Interface GUID Feature Descriptor (Vendor request, Index 5) */
const uint8_t glOsFeature[] __attribute__ ((aligned (4))) =
{
    /* Header Section */
    0x8E,0x00,0x00,0x00,            /* dwLength: Total length of descriptor (142 bytes) */
    0x00,0x01,                      /* bcdVersion: Version 1.00 */
    0x05,0x00,                      /* wIndex: Extended properties index (5) */
    0x01,0x00,                      /* wCount: 1 property section */

    /* Property Section */
    0x84,0x00,0x00,0x00,            /* dwSize: Property size (132 bytes) */
    0x01,0x00,0x00,0x00,            /* dwPropertyDataType: REG_SZ */
    0x28,0x00,                      /* wPropertyNameLength: Name size (40 bytes) */
    'D',0x00, 'e',0x00, 'v',0x00, 'i',0x00, 'c',0x00, 'e',0x00,
    'I',0x00, 'n',0x00, 't',0x00, 'e',0x00, 'r',0x00, 'f',0x00, 'a',0x00, 'c',0x00, 'e',0x00,
    'G',0x00, 'U',0x00, 'I',0x00, 'D',0x00, 0x00,0x00, /* bPropertyName: "DeviceInterfaceGUID" */
    0x4E,0x00,0x00,0x00,            /* dwPropertyDataLength: Data size (78 bytes) */
    /* bPropertyData: "{8D2C9D52-5C6B-4F0B-9F1B-3EBE8C4F9A61}" */
    '{',0x00, '8',0x00, 'D',0x00, '2',0x00, 'C',0x00, '9',0x00, 'D',0x00, '5',0x00,
    '2',0x00, '-',0x00, '5',0x00, 'C',0x00, '6',0x00, 'B',0x00, '-',0x00, '4',0x00,
    'F',0x00, '0',0x00, 'B',0x00, '-',0x00, '9',0x00, 'F',0x00, '1',0x00, 'B',0x00,
    '-',0x00, '3',0x00, 'E',0x00, 'B',0x00, 'E',0x00, '8',0x00, 'C',0x00, '4',0x00,
    'F',0x00, '9',0x00, 'A',0x00, '6',0x00, '1',0x00, '}',0x00, 0x00,0x00
};
