# FX2G3 RTBox - Project Onboarding

## Project Overview

**FX2G3 RTBox** is a real-time data acquisition and streaming system built on Infineon's **EZ-USB FX2G3** microcontroller. The project implements:
- Custom USB endpoint for streaming UART and SPI data
- Firmware with bootloader support for OTA updates via PMODE button
- Host application (PowerScope) for data visualization and control

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

## Key Files & Responsibilities

| File | Purpose | Status |
|------|---------|--------|
| `main.c` | Firmware entry point, initialization | ❓ TBD |
| `cm0_code.c` | Core Cortex-M0+ logic, USB handler | ❓ TBD |
| `UART/SPI drivers` | Interface to peripherals | ❓ TBD |
| `USB endpoint implementation` | Bulk streaming, control transfers | ⚠️ **To Implement** |

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

## Quick Commands

```bash
# Build firmware
make build

# Clean build
make clean

# Flash to device
make program

# Open workspace in VS Code (optional)
code FX2G3_RTBox.code-workspace
```

---

**Last Updated:** 2026-06-04  
**Maintained by:** mwattenberg  
**Status:** Active Development
