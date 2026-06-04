# FX2G3 RTBox - Project Onboarding

## Project Overview

**FX2G3 RTBox** is a real-time data acquisition and streaming system built on Infineon's **EZ-USB FX2G3** microcontroller. The project implements:
- Custom USB endpoint for streaming UART and SPI data
- Firmware with bootloader support for OTA updates via PMODE button
- Host application (PowerScope) for data visualization and control

**This Repository:** [github.com/mwattenberg/PowerScope_FX2G3](https://github.com/mwattenberg/PowerScope_FX2G3) - Firmware for FX2G3 MCU

**Related Repository:** [PowerScope](https://github.com/mwattenberg/PowerScope) - Host application for Windows/C# that receives and processes streamed data.

---

## Architecture

### Firmware (This Repository)
- **MCU:** EZ-USB FX2G3 (Infineon ARM Cortex-M0+)
- **Toolchain:** ModusToolbox v3.5+, GNU Arm Embedded Compiler v14.2.1
- **Key Components:**
  - USB endpoint for bulk data streaming (custom protocol)
  - UART interface for serial communication
  - SPI interface for sensor/device communication
  - Bootloader functionality triggered by PMODE button during power-on

### Host Application
- **Framework:** C# / .NET (PowerScope)
- **Key File:** `Model/USBDataStream.cs` - Manages USB communication with device
- **Features:**
  - USB device enumeration and connection
  - Data streaming reception and parsing
  - Channel configuration and filtering
  - Sample rate calculation and monitoring

### USB Protocol (Design Required)
The USB endpoint must support:
1. **Control Transfers:** Start/Stop streaming commands
   - `REQ_START (0xA0)` - Begin UART/SPI data streaming
   - `REQ_STOP (0xA1)` - Stop data streaming

2. **Bulk IN Endpoint (0x81):** Data streaming
   - Continuous UART/SPI sample data from device to host
   - Format: TBD (likely timestamp + channel data)

3. **Device GUID:** `{8D2C9D52-5C6B-4F0B-9F1B-3EBE8C4F9A61}`

---

## Key Features

### 1. Bootloader / Firmware Update
- User presses **PMODE** button during power-on to enter bootloader mode
- Allows firmware reflash without external programmer
- Bootloader source included in `bootloader/` subfolder

### 2. Data Streaming
- Multi-channel support (UART and SPI data multiplexed)
- Real-time transmission to host application
- Sample rate configurable (USB update rate: 1000 Hz typical)

### 3. Host Integration
- Windows-only (via WinUSB driver)
- IDataStream interface for abstraction
- PropertyChanged events for UI binding

---

## File Structure

```
FX2G3_RTBox/
├── README.md                 (⚠️ Needs update - currently Infineon template)
├── CLAUDE.md                 (This file)
├── main.c                    (Entry point)
├── cm0_code.c                (Core firmware logic)
├── Makefile                  (Build configuration)
├── project_info.json         (Project metadata)
├── app_version.h             (Version info)
├── linker_scripts/           (Linker configuration)
├── bsps/                     (Board support packages)
├── libs/                     (External libraries)
├── docs/                     (Documentation)
├── images/                   (Diagrams/photos)
└── build/                    (Generated build artifacts)
```

---

## Development Workflow

### Build & Compile
```bash
make build          # Compile firmware
make clean          # Clean build artifacts
```

### Programming Device
```bash
make program        # Flash firmware to device via OpenOCD
```

### Bootloader Entry
1. Press and hold **PMODE** button on FX2G3 DVK
2. Power cycle device (press RESET or cycle power)
3. Device enters bootloader mode, ready for firmware update
4. Use Infineon FX Control Center or custom tool to upload new firmware

### Debugging
- **OpenOCD Configuration:** `openocd.tcl`
- **Terminal Emulation:** Tera Term (recommended)
- **USB Debug Interface:** Native FX2G3 FS debug port

---

## Design Decisions

### Removed Features
To keep the codebase clean and focused on core functionality:

1. **USB FS Debug Logging (CDC Interface)**
   - Removed: Infineon example included USB CDC debug interface
   - Reason: Cortex-M4 debugger provides superior debugging; USB CDC interface adds unnecessary complexity
   - Result: Cleaner codebase, faster development
   - **Note:** `USBFS_LOGS_ENABLE` build flag disabled

2. **ADC Functionality**
   - Removed: Infineon example included ADC sampling code
   - Reason: Hardware requirements don't include analog measurements; UART/SPI data streaming is the focus
   - Result: Simplified peripheral initialization, reduced power consumption
   - **Note:** ADC clock initialization disabled

### Retained Features
- **Dual-Core Architecture:** Both M0+ and M4 cores functional (enables real-time processing)
- **USB Bulk Endpoints:** For streaming UART/SPI data to host
- **UART Interface:** SCB[1] configured for serial communication input
- **SPI Interface:** SCB[4] configured as Master for serial device communication

### Peripheral Configuration

| Peripheral | Instance | Mode | Purpose |
|-----------|----------|------|---------|
| UART | SCB[1] | Standard UART | Serial data input from external UART devices |
| SPI | SCB[4] | Master (Motorola) | Serial data input from SPI devices |

See `bsps/TARGET_APP_KIT_FX2G3_104LGA/config/design.modus` for detailed GPIO and clock configuration.

---

## Implementation Tasks

### Phase 1: USB Endpoint Implementation (Firmware)
- [ ] Define USB descriptor for bulk endpoint (0x81)
- [ ] Implement control transfer handlers (REQ_START, REQ_STOP)
- [ ] Implement bulk IN data streaming
- [ ] Test with PowerScope host application
- [ ] Document USB protocol specification

### Phase 2: Host Application Integration
- [ ] Complete `USBDataStream.cs` implementation
- [ ] Add device detection and connection logic
- [ ] Implement data parsing and channel routing
- [ ] Add sample rate monitoring
- [ ] Test end-to-end UART/SPI data acquisition

### Phase 3: Bootloader & Documentation
- [ ] Verify bootloader functionality (PMODE button trigger)
- [ ] Document firmware update process
- [ ] Create user guide for PMODE bootloader entry
- [ ] Update README.md with project-specific content

### Phase 4: Repository & Release
- [ ] Publish firmware source to this GitHub repo
- [ ] Set up CI/CD pipeline for builds
- [ ] Create release binaries
- [ ] Link firmware repo in PowerScope documentation

---

## Important Notes

### USB Device GUID
The host application expects device GUID: `{8D2C9D52-5C6B-4F0B-9F1B-3EBE8C4F9A61}`

This **must** be registered in the device's USB descriptor. Ensure FX2G3 firmware configures this GUID for WinUSB driver enumeration.

### Data Format
- TBD: Define exact packet structure for streaming data
- Consider: Timestamp, channel ID, raw sample value, metadata
- Align with PowerScope's `DataParser` expectations

### Sample Rate
- Host polls at **1000 Hz** by default (`UsbUpdateRateHz`)
- Firmware must buffer/pace data to match this cadence
- High-speed USB available for higher throughput if needed

---

## Links & References

- **Infineon FX2G3 Docs:** https://www.infineon.com/cms/en/product/promopages/ez-usb-fx2g3/
- **ModusToolbox:** https://www.infineon.com/modustoolbox
- **PowerScope Repository:** https://github.com/mwattenberg/PowerScope
- **PowerScope USBDataStream:** https://github.com/mwattenberg/PowerScope/blob/master/Model/USBDataStream.cs

---

## Build System

### ModusToolbox Make Build

This project uses **ModusToolbox** with a **GNU Make + Ninja** build system. All builds are executed through the `modus-shell` environment.

### Build Commands

From the project root directory (in ModusToolbox modus-shell):

```bash
# Build firmware (Debug configuration)
make build

# Build firmware (Release configuration)  
make build CONFIG=Release

# Program device via OpenOCD
make program

# Erase device flash
make erase

# Clean build artifacts
make clean
```

### Build Configuration

- **Default Toolchain:** GNU Arm Embedded Compiler v14.2.1 (`GCC_ARM`)
- **Default Configuration:** Debug
- **Default Target:** `APP_KIT_FX2G3_104LGA`

### Build Artifacts

Built files are located in: `build/Debug/` or `build/Release/`

Key output files:
- `mtb-example-fx2g3-hello-world.elf` - Executable firmware
- `mtb-example-fx2g3-hello-world.hex` - Intel HEX format (for bootloader)
- `mtb-example-fx2g3-hello-world.bin` - Binary firmware image

### Makefile Configuration

Key build variables in `Makefile`:

```makefile
USBFS_LOGS_ENABLE=0         # Disable USB CDC logging
BLOAD_ENABLE=0              # Bootloader disabled for normal operation
```

To enable bootloader support:
```bash
# Edit Makefile: BLOAD_ENABLE=1, then rebuild
make clean && make build
```

### ModusToolbox Setup

Required:
- [ModusToolbox 3.5+](https://www.infineon.com/modustoolbox)
- Run from **modus-shell** (Windows) or native bash (Linux/macOS)
- OpenOCD for device programming

---

## USB Interface Implementation (UsbInterface Branch)

### Overview

This section covers custom USB endpoint implementation using WinUSB driver on the FX2G3 chip. The FX2 has a built-in Configurator tool for defining USB descriptors.

### USB Descriptor Components (Using FX2 Configurator)

The FX2 Configurator tool allows configuring the following USB descriptors:

1. **Device Descriptor**
   - VID/PID (Vendor ID / Product ID)
   - Device class and version
   - Max packet size for EP0
   - Device GUID for WinUSB enumeration

2. **Configuration Descriptor**
   - Power requirements (bus-powered vs self-powered)
   - Number of interfaces and alternate settings

3. **Interface Descriptor**
   - Interface number and alternate settings
   - Class and subclass codes
   - String descriptors for human-readable names

4. **Endpoint Descriptors**
   - **Bulk IN (0x81):** Streaming data from device to host
     - Purpose: UART/SPI data transmission
     - Direction: IN (device → host)
     - Transfer Type: Bulk
     - Max packet size: 64 bytes (FS) or 512 bytes (HS)
   - **Bulk OUT (0x01):** Optional command endpoint (reserve for future use)

5. **String Descriptors**
   - Device manufacturer, product name, serial number
   - Interface description

### Debugging USB Descriptors

#### Method 1: Host Enumeration Tools (Recommended for initial debug)
- **Zadig Tool** (easiest): Shows raw USB descriptor info
  - Install WinUSB driver automatically
  - Displays Device GUID and all descriptor information
  - Free, Windows-only: https://zadig.akeo.ie/
  
- **USBTreeView**: Shows full USB device tree and descriptor breakdown
  - More detailed information than Zadig
  - http://www.usbdeview.com/usbdevice.html

- **Windows Device Manager**: 
  - Plug device and check `Hardware IDs` property
  - Verify device is detected correctly
  - Check for driver assignment (WinUSB)

#### Method 2: Firmware-side Verification
- Add simple test code to verify descriptor is loaded:
  ```c
  // Read descriptor from firmware (verify it was programmed)
  // Use debugger or serial output to confirm descriptor values
  ```

#### Method 3: PowerScope Host Application
- Once descriptors are correct, PowerScope should:
  1. Enumerate the device
  2. Find device by GUID
  3. Open bulk IN endpoint (0x81)
  4. Begin receiving data (initially test pattern from UART/SPI)

### Implementation Workflow

**Step 1: Define USB Descriptors (Using FX2 Configurator)**
- Open FX2 Configurator tool
- Configure Device Descriptor: VID 0x2B2D, PID 0x0001
- Set Device GUID: `{8D2C9D52-5C6B-4F0B-9F1B-3EBE8C4F9A61}` (WinUSB requirement)
- Configure Interface with Bulk IN endpoint (0x81, 64 bytes)
- Add string descriptors (optional but recommended)
- Export/generate descriptor code

**Step 2: Firmware Integration**
- Include generated descriptor code in USB stack initialization
- Implement USB control transfer handlers (optional, for future commands)
- Implement bulk IN endpoint interrupt/DMA handler
- Route UART/SPI data to bulk IN FIFO

**Step 3: Host-side Testing (PowerScope)**
- Enumerate USB device
- Verify GUID match
- Open endpoint 0x81
- Receive and display test data

**Step 4: Validation**
- Use Zadig to verify descriptor is recognized by host
- Verify Device GUID appears correctly
- Test with PowerScope enumeration code

### USB Descriptor Debugging Checklist

- [ ] Device is detected by Windows Device Manager
- [ ] Zadig/USBTreeView shows correct VID/PID
- [ ] Device GUID matches firmware descriptor and PowerScope code
- [ ] WinUSB driver successfully assigned by Zadig
- [ ] PowerScope can enumerate device by GUID
- [ ] PowerScope can open bulk IN endpoint (0x81)
- [ ] Test data flows from firmware to host (initial UART/SPI test pattern)

### Important: Device GUID for WinUSB

WinUSB drivers require an explicit GUID. The FX2G3 firmware must:

1. Include GUID in USB Device Descriptor (or descriptor extension)
2. Use: `{8D2C9D52-5C6B-4F0B-9F1B-3EBE8C4F9A61}`
3. Ensure PowerScope app searches for this exact GUID

### USB Protocol (Pending Detailed Design)

**Control Transfers (optional, for future enhancement):**
- `REQ_START (0xA0)` - Begin streaming
- `REQ_STOP (0xA1)` - Stop streaming

**Bulk IN (0x81) - Data Streaming Format (TBD):**
- Currently: Test pattern (UART test pattern + SPI test pattern)
- Future: Timestamp + Channel ID + Sample Data

**Expected Data Rate:**
- Host polls at ~1000 Hz
- Each packet: 64 bytes (FS USB)
- Theoretical bandwidth: ~65 KB/s (conservative for UART/SPI data)

---



```bash
# Build firmware
make build

# Program to device
make program

# Erase device
make erase

# Clean build artifacts
make clean

# Open workspace in VS Code (optional)
code FX2G3_RTBox.code-workspace
```

---

**Last Updated:** 2026-06-04  
**Maintained by:** mwattenberg  
**Status:** Active Development
