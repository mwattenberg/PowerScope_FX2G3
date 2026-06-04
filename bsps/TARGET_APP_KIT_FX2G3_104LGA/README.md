# KIT_FX2G3_104LGA BSP

## Overview

The Infineon Technologies EZ-USB™ FX2G3 family features USB 2.0 device  controllers suitable for both high-speed and low-speed applications.  The Development Kit (DVK) is specifically designed to help customers develop  a wide array of USB 2.0 applications, such as mobile add-on dental cameras,  thermal cameras, 3D cameras, logic analyzers, and various applications in  biometrics, scanning, video, and imaging.



To use code from the BSP, simply include a reference to `cybsp.h`.

## Features

### Kit Features:

* Base board: FX2G3 device, power supplies, CAN transceiver, Optiga             Trust M module, USB-C HS and FS connectors for data transmission              and debug respectively, GPIO interface connectors for add-on modules.
* FPGA add-on board: T20 FPGA from EFINIX, IFX PDM microphones, NOR flash,              I22-pin FPC interface connectors and GPIO interface connectors.
* Full-speed USB

### Kit Contents:

* EZ-USB™  Base Board and FPGA add-on board
* Quick Start Guide

## BSP Configuration

The BSP has a few hooks that allow its behavior to be configured. Some of these items are enabled by default while others must be explicitly enabled. Items enabled by default are specified in the KIT_FX2G3_104LGA.mk file. The items that are enabled can be changed by creating a custom BSP or by editing the application makefile.

Components:
* Device specific category reference (e.g.: CAT1) - This component, enabled by default, pulls in any device specific code for this board.

Defines:
* CYBSP_WIFI_CAPABLE - This define, disabled by default, causes the BSP to initialize the interface to an onboard wireless chip if it has one.
* CY_USING_HAL - This define, enabled by default, specifies that the HAL is intended to be used by the application. This will cause the BSP to include the applicable header file and to initialize the system level drivers.
* CYBSP_CUSTOM_SYSCLK_PM_CALLBACK - This define, disabled by default, causes the BSP to skip registering its default SysClk Power Management callback, if any, and instead to invoke the application-defined function `cybsp_register_custom_sysclk_pm_callback` to register an application-specific callback.

### Clock Configuration

| Clock    | Source    | Output Frequency |
|----------|-----------|------------------|
| FLL      | IMO       | 24.6 MHz         |
| PLL      | IMO       | 48.0 MHz         |
| CLK_HF0  | CLK_PATH1 | 150 MHz          |
| CLK_HF1  | CLK_PATH1 | 37 MHz           |
| CLK_HF2  | CLK_PATH2 | 48 MHz           |
| CLK_HF3  | CLK_PATH0 | 24 MHz           |
| CLK_HF4  | CLK_PATH1 | 150 MHz          |

See the [BSP Setttings][settings] for additional board specific configuration settings.

## API Reference Manual

The KIT_FX2G3_104LGA Board Support Package provides a set of APIs to configure, initialize and use the board resources.

See the [BSP API Reference Manual][api] for the complete list of the provided interfaces.

## More information
* [KIT_FX2G3_104LGA BSP API Reference Manual][api]
* [KIT_FX2G3_104LGA Documentation](https://www.infineon.com/cms/en/product/promopages/ez-usb-fx2g3)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

[api]: https://infineon.github.io/TARGET_KIT_FX2G3_104LGA/html/modules.html
[settings]: https://infineon.github.io/TARGET_KIT_FX2G3_104LGA/html/md_bsp_settings.html

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2019-2024.