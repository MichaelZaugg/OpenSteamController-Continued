# Steam Controller Open Firmware

This is an open-source firmware for the Valve Steam Controller, implemented in Rust. It supports both USB HID and Bluetooth HID functionality.

## Features

- Full support for all Steam Controller inputs:
  - Buttons (A, B, X, Y, Start, Back, Steam, Grips, etc.)
  - Analog triggers
  - Joystick
  - Left and right touchpads
  - Gyroscope and accelerometer

- Output interfaces:
  - USB HID (Mouse and Keyboard)
  - Bluetooth HID (Mouse and Keyboard)
  - Haptic feedback for trackpads

## Hardware Architecture

The Steam Controller uses:
- **LPC11U37F** as the main microcontroller
- **nRF51822** for wireless communication
- **MPU-6500** for motion sensing
- Two trackpads with haptic feedback
- Various buttons and analog inputs

## Firmware Architecture

The firmware is split into two main components:

1. **Main Firmware (this project)**: Runs on the LPC11U37F, handles all inputs, and provides USB HID functionality
2. **Bluetooth Firmware** (in `../nRF51822_Firmware/`): Runs on the nRF51822, implements Bluetooth HID services

### Main Firmware Structure

- `src/main.rs`: Entry point and main loop
- `src/hal/`: Hardware abstraction layer for peripherals
- `src/drivers/`: Drivers for external components (MPU-6500, nRF51822)
- `src/controller/`: Controller state and input processing
- `src/utils/`: Utility functions and types

## Building and Flashing

To build the firmware:

```bash
cargo build --release
```

To flash to the LPC11U37F (requires OpenOCD):

```bash
arm-none-eabi-objcopy -O binary target/thumbv6m-none-eabi/release/steamcontroller-firmware firmware.bin
openocd -f interface/cmsis-dap.cfg -f target/lpc11xx.cfg -c "program firmware.bin verify reset exit 0x0"
```

## Dual Mode: USB and Bluetooth

The controller supports both USB HID and Bluetooth HID:

- When connected via USB, the LPC11U37F handles USB HID directly
- When wireless, the nRF51822 handles Bluetooth HID communication

To use Bluetooth functionality, you'll need to flash both the main firmware and the Bluetooth firmware to their respective microcontrollers.

## License

This project is open source under the MIT License. See the LICENSE file for details.
