# Steam Controller Bluetooth HID Firmware

This firmware allows the Steam Controller to function as a Bluetooth HID device, providing both mouse and keyboard functionality over Bluetooth Low Energy.

## Architecture

The Steam Controller uses two microcontrollers:

1. **LPC11U37F** (Main MCU): Handles controller inputs, analog readings, and main functionality
2. **nRF51822** (Wireless MCU): Handles wireless communication

The firmware is split into two parts:

1. **Main Firmware** (in `../Rust_Firmware/`): Runs on the LPC11U37F, handles inputs, and sends data to the nRF51822
2. **Bluetooth Firmware** (this project): Runs on the nRF51822, implements Bluetooth HID services

## Communication Protocol

The LPC11U37F and nRF51822 communicate over UART using a simple command-based protocol:

### Commands from LPC11U37F to nRF51822

- `0x01`: Initialize Bluetooth
- `0x02`: Set Device Name
- `0x03`: Start Advertising
- `0x04`: Connect (when triggered by a button)
- `0x05`: Disconnect (when triggered by a button)
- `0x10`: Mouse Report Data
- `0x11`: Keyboard Report Data
- `0x12`: Consumer Control Report Data

### Responses from nRF51822 to LPC11U37F

- `0x00`: Success
- `0x01`: Connected (when a host connects)
- `0x02`: Disconnected (when a host disconnects)
- `0xFF`: Error

## Bluetooth HID Implementation

The firmware implements three HID interfaces:

1. **Mouse Interface**: For trackpad control
2. **Keyboard Interface**: For button mappings
3. **Consumer Control Interface**: For media keys and system functions

## Building and Flashing

To build the firmware:

```bash
cargo build --release
```

To flash to the nRF51822 (requires J-Link tools):

```bash
arm-none-eabi-objcopy -O ihex target/thumbv6m-none-eabi/release/steamcontroller-nrf51822-firmware nrf51822-firmware.hex
nrfjprog -f nrf51 --program nrf51822-firmware.hex --sectorerase --verify
nrfjprog -f nrf51 --reset
```

## Integration with Main Firmware

The main LPC11U37F firmware automatically initializes the nRF51822 and sends controller state over UART using the protocol described above. To enable Bluetooth HID functionality, you'll need to flash both firmware images to their respective microcontrollers.

## Dual Mode: USB and Bluetooth

The controller supports both USB HID and Bluetooth HID:

- When connected via USB, the LPC11U37F handles USB HID directly
- When wireless, the nRF51822 handles Bluetooth HID communication

This allows the controller to work with both wired and wireless connections seamlessly.
