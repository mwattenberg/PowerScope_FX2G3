# FX2G3 RTBox – UART & SPI Data Streaming to PowerScope

Real-time data acquisition firmware for the **Infineon EZ-USB FX2G3** microcontroller, streaming UART and SPI data to the **PowerScope** host application via USB.

## Key Features

- **Real-time USB Data Streaming** – Multiplexed UART and SPI data streamed to PowerScope host application over bulk USB endpoints
- **Firmware Update via PMODE Button** – Press PMODE during power-on/reset to enter bootloader mode; no external programmer required
- **Host Application Integration** – Windows host software (C#/.NET) receives, parses, and visualizes streaming data
- **Multi-channel Support** – Simultaneous acquisition from multiple UART and SPI interfaces
- **Bare-Metal C Implementation** – Optimized firmware for low-latency USB streaming

### PowerScope Host Application

This firmware pairs with the **PowerScope** host application. See [github.com/mwattenberg/PowerScope](https://github.com/mwattenberg/PowerScope) for the Windows desktop application and USB protocol documentation.

---


## Getting Started

### Hardware

- **Target Board:** [EZ-USB&trade; FX2G3 DVK](https://www.infineon.com/cms/en/product/promopages/ez-usb-fx2g3/) (`KIT_FX2G3_104LGA`)
- **Default Configuration:** Uses board's standard configuration. See kit user guide for details.

### Bootloader / Firmware Update

1. **Press PMODE button** on the FX2G3 DVK
2. **Power-cycle** the device (press RESET or cycle power while PMODE is held)
3. Device enters **bootloader mode**
4. Use **EZ-USB FX Control Center** or custom bootloader tool to upload new firmware
5. **Release PMODE** and power-cycle to boot into application firmware

See the `bootloader/` subfolder for bootloader source code.

### Build & Program

```bash
# Build firmware
make build

# Program to device (requires OpenOCD)
make program

# Clean build artifacts
make clean
```

---

## Development Setup

### Software Requirements

- [ModusToolbox&trade;](https://www.infineon.com/modustoolbox) v3.5 or later (tested with v3.5)
- Board support package (BSP) minimum version: 4.3.3
- Programming language: C
- Terminal emulator (e.g., [Tera Term](https://teratermproject.github.io/index-en.html))

### Supported Toolchains

- GNU Arm&reg; Embedded Compiler v14.2.1 (`GCC_ARM`) – Default
- Arm&reg; Compiler v6.22 (`ARM`)

### Supported Products

- `CYUSB2318-BF104AXI`
- `CYUSB2317-BF104AXI`
- `CYUSB2316-BF104AXI`
- `CYUSB2315-BF104AXI`

### Software Setup

1. Install **ModusToolbox** – See [ModusToolbox Installation Guide](https://www.infineon.com/ModusToolboxInstallguide)
2. Install **Terminal Emulator** – [Tera Term](https://teratermproject.github.io/index-en.html) recommended
3. Install **EZ-USB FX Control Center** (Alpha) from [Infineon Developer Center](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.ezusbfxcontrolcenter) – Used for bootloader management

### Optional Tools

- [EZ-USB GPIF III Designer](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.ezusbgpifiiidesigner) – For GPIF protocol design

---


## Project Structure

| Directory | Purpose |
|-----------|---------|
| `bootloader/` | Bootloader source code for firmware update via PMODE |
| `docs/` | Documentation and user guides |
| `images/` | Diagrams and photographs |
| `libs/` | External libraries (USBFX Stack, etc.) |
| `bsps/` | Board support packages |
| `main.c` | Application entry point |
| `cm0_code.c` | Core Cortex-M0+ logic and USB handlers |

---

6. Launch the **Device Configurator** tool

   a. **Eclipse IDE:** Select your project in the project explorer, and launch the **Device Configurator** tool by navigating to **Quick Panel** > **Tools**

   b. **Visual Studio Code:** Select the ModusToolbox&trade; extension from the left menu bar, and launch the **Device Configurator** tool, available in the **BSP** menu of the **MODUSTOOLBOX TOOLS** section from the left pane

7. Correct the issues (if any) specified in the **Errors** section on the bottom

   a. For a switch from the `CYUSB2318-BF104AXI` product to any other, a new upper limit of 100 MHz is imposed on the desired frequency that can originate from the PLL. Select this issue and change the desired frequency from 150 MHz to 75 MHz

   b. The `CLK_PERI` clock, which is derived from this new source frequency, is also affected. To restore it to its original frequency, go to the **System Clocks** tab, select `CLK_PERI`, and set its divider to '1' (instead of '2')

> **Note:** For the `CYUSB2315-BF104AXI` product, to enable UART logging through SCB, follow the steps below:<br>
a. Set the `USBFS_LOGS_ENABLE` macro to `0` in the **Makefile**<br>
b. In **main.c**, modify the SCB configuration by changing `LOGGING_SCB` from `(SCB4)` to `(SCB0)`, `LOGGING_SCB_IDX` from `(4)` to `(0)` and the value of `dbgCfg.dbgIntfce` from `CY_DEBUG_INTFCE_UART_SCB4` to `CY_DEBUG_INTFCE_UART_SCB0`<br>
c. Launch the Device Configurator tool to disable `SCB4`, and enable `SCB0` for UART. Set `921600` baud, `9` Oversample, and use the `16 bit Divider 0 clk` clock


## Compile-time configurations

This application's functionality can be customized by setting variables in *Makefile* or by configuring them through `make` CLI arguments.

- Run the `make build` command or build the project in your IDE to compile the application and generate a USB bootloader-compatible binary. This binary can be programmed onto the EZ-USB&trade; FX2G3 device using the **EZ-USB&trade; FX Control Center** application

- Run the `make build CORE=CM0P` command or set the variable in *Makefile* to compile and generate the binary for the Cortex&reg; M0+ core. By default, `CORE` is set as `CM4` and the binary is compiled and generated for the Cortex&reg; M4 core

- Choose between the **Arm&reg; Compiler** or the **GNU Arm&reg; Embedded Compiler** build toolchains by setting the `TOOLCHAIN` variable in *Makefile* to `ARM` or `GCC_ARM` respectively. If you set it to `ARM`, ensure to set `CY_ARM_COMPILER_DIR` as a make variable or environment variable, pointing to the path of the compiler's root directory

- Run the `make build REV02=no` command or set the variable in *Makefile* to compile the application and generate the binary compatible with the REV01 version of the EZ-USB&trade; FX2G3 kit

Additional settings can be configured through macros specified by the `DEFINES` variable in *Makefile*:

**Table 2. Macro description**

 Macro name        |  Description                          |    Allowed values
 :--------         | :-------------                        | :------------
USBFS_LOGS_ENABLE | Enable debug logs through the USBFS port  | 1u for debug logs over USBFS <br> 0u for debug logs over UART (SCB4)
<br>


## Operation

**Note:** This code example currently supports Windows hosts. Support for Linux and macOS will be added in upcoming releases.

1. Connect the board (J2) to your PC using the provided USB cable

2. Connect the USBFS port (J7) on the board to the PC for debug logs

3. Open a terminal program and select the Serial COM port. Set the serial port parameters to 8N1 and 921600 baud

4. Follow these steps to program the board using the [**EZ-USB&trade; FX Control Center**](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.ezusbfxcontrolcenter) (Alpha) application
      
   1. Perform the following steps to enter into the **Bootloader** mode:

      a. Press and hold the **PMODE** (**SW1**) switch<br>
      b. Press and release the **RESET** switch<br>
      c. Release the **PMODE** switch<br>
      
   2. Open **EZ-USB&trade; FX Control Center** application

   The **EZ-USB&trade; FX2G3** device displays as **EZ-USB FX BOOTLOADER**
      
   3. Navigate to **Device Selection** > **Devices**, select **EZ-USB FX BOOTLOADER**, and then click the **Program** > **Internal Flash** option

   4. Navigate to the *<CE Title>/build/APP_KIT_FX2G3_104LGA/Release* folder within the CE directory and locate the *.hex* file and program
      
   5. Confirm if the programming is successful in the log window of the application

   6. After programming, the application starts automatically. Confirm that the following title is displayed on the UART terminal:


      **Figure 1. Terminal output on program startup**

      ![](images/terminal-fx2g3-hello-world.png)


5. Confirm that the GPIO1 and GPIO2 toggle at approximately 1 Hz


## Debugging

By default, the USBFS port is enabled for debug logs.

To enable debug logs on UART, set **USBFS_LOGS_ENABLE** compiler flag to '0u' in *Makefile*. SCB4 of the EZ-USB&trade; FX2G3 device is used as UART with a baud rate of 921,600 to send out log messages through the P11.0 pin.

Debug the code example by setting debug levels for the UART logs. Set the **DEBUG_LEVEL** macro in *main.c* file with the following values for debugging:

**Table 1. Debug values**

 Macro value  | Description
 :--------    | :-------------
 1u           | Enable only error messages
 2u           | Enable error and warning messages
 3u           | Enable info messages as well
 4u           | Enable all message types
<br>


## Resources

| Resource | Link |
|----------|------|
| EZ-USB FX2G3 SDK User Guide | [docs/EZ-USB-FX2G3-SDK-User-Guide.pdf](./docs/EZ-USB-FX2G3-SDK-User-Guide.pdf) |
| EZ-USB FX2G3 Datasheets | [Infineon Product Page](https://www.infineon.com/cms/en/product/promopages/ez-usb-fx2g3/#!?fileId=8ac78c8c90530b3a01909c03f29537e0) |
| ModusToolbox | [Infineon ModusToolbox](https://www.infineon.com/modustoolbox) |
| USBFX Stack Middleware | [GitHub: usbfxstack](https://github.com/Infineon/usbfxstack) |
| Peripheral Driver Library (PDL) | [GitHub: mtb-pdl-cat1](https://github.com/Infineon/mtb-pdl-cat1) |
| PowerScope Host Application | [GitHub: mwattenberg/PowerScope](https://github.com/mwattenberg/PowerScope) |

---

## License

This project is based on Infineon's EZ-USB FX2G3 examples. See LICENSE file for details.

**Copyright © 2026** – MIT License
