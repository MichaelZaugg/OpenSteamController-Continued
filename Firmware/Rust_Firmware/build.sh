#!/bin/bash

# Build script for Steam Controller firmware
# This script builds the firmware and prepares it for flashing

echo "Building Steam Controller firmware..."

# Build the firmware in release mode
if ! cargo build --release; then
    echo "ERROR: Failed to build firmware"
    exit 1
fi

echo "Build successful! Creating binary file for flashing..."

# Create the binary file suitable for flashing
if ! arm-none-eabi-objcopy -O binary target/thumbv6m-none-eabi/release/steamcontroller-firmware firmware.bin; then
    echo "ERROR: Failed to create binary file. Make sure arm-none-eabi-objcopy is installed."
    exit 1
fi

echo "Firmware binary created: firmware.bin"
echo "Size: $(stat -c%s firmware.bin) bytes"

echo ""
echo "To flash the firmware to the Steam Controller:"
echo "1. Connect your Steam Controller with a debug probe (like ST-Link, J-Link, or OpenOCD compatible)"
echo "2. Run: openocd -f interface/cmsis-dap.cfg -f target/lpc11xx.cfg -c \"program firmware.bin verify reset exit 0x0\""
echo ""
echo "Or use probe-rs if you have it installed:"
echo "cargo run --release"
echo ""
echo "The firmware is now ready for flashing!"
