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
if ! cargo objcopy --release -- -O binary firmware.bin; then
    echo "ERROR: Failed to create binary file. Make sure cargo-binutils is installed."
    exit 1
fi

# Get current size
current_size=$(stat -c%s firmware.bin)
target_size=131072  # 128KB exactly

echo "Padding binary to exactly 128KB..."

# Pad the binary to exactly 128KB to replace all chip memory
if [ $current_size -lt $target_size ]; then
    padding_needed=$((target_size - current_size))
    dd if=/dev/zero bs=1 count=$padding_needed >> firmware.bin 2>/dev/null
    echo "Padded binary by $padding_needed bytes"
elif [ $current_size -gt $target_size ]; then
    echo "ERROR: Binary is too large ($current_size bytes > $target_size bytes)"
    exit 1
fi

final_size=$(stat -c%s firmware.bin)
echo "Final binary size: $final_size bytes (exactly 128KB)"

echo ""
echo "Firmware binary created: firmware.bin"
echo "Ready for flashing to Steam Controller!"
echo ""
echo "To flash the firmware:"
echo "  openocd -f interface/stlink-v2.cfg -f target/lpc11xx.cfg \\"
echo "    -c \"program firmware.bin 0x00000000 verify reset exit\""
echo ""
echo "Or with probe-rs:"
echo "  probe-rs flash --chip LPC1114FN28 firmware.bin"
