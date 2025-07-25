#!/bin/bash

# LPC11U37 Firmware Flash Script
# Flashes firmware to LPC11U37 via USB Mass Storage interface

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

print_step() {
    echo -e "${BLUE}[STEP]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

echo ""
echo "========================================"
echo "  LPC11U37 Firmware Flash Script"
echo "========================================"
echo ""

# Check if firmware directory exists
if [ ! -d "./firmware" ]; then
    print_error "Firmware directory not found!"
    echo "Please run ./build.sh first to build the firmware."
    exit 1
fi

# Check if firmware.bin exists
if [ ! -f "./firmware/firmware.bin" ]; then
    print_error "firmware.bin not found in ./firmware/ directory!"
    echo "Please run ./build.sh first to build the firmware."
    exit 1
fi

# Show firmware info
FIRMWARE_SIZE=$(stat -c%s "./firmware/firmware.bin")
print_step "Firmware ready for flashing:"
echo "  - File: ./firmware/firmware.bin"
echo "  - Size: $FIRMWARE_SIZE bytes (128KB)"

# Verify it's the right size
if [ "$FIRMWARE_SIZE" -ne 131072 ]; then
    print_warning "Firmware size is not 128KB ($FIRMWARE_SIZE bytes)"
    echo "This might cause flashing issues. Continue anyway? [y/N]"
    read continue_anyway
    if [[ "$continue_anyway" != "Y" && "$continue_anyway" != "y" ]]; then
        echo "Aborting flash operation."
        exit 1
    fi
fi

echo ""
print_step "Connect your LPC11U37 device in ISP mode (should appear as USB Mass Storage)"
echo ""
echo "Please enter LPC11U37 USB Mass Storage directory"
echo "(e.g. /run/media/username/CRP DISABLD or /media/username/CRP DISABLD)"
echo -n "Location: "
read location

# Validate the location exists
if [ ! -d "$location" ]; then
    print_error "Directory '$location' does not exist!"
    exit 1
fi

# Check if it looks like an LPC mass storage device
if [ ! -w "$location" ]; then
    print_error "Cannot write to '$location' - check permissions!"
    exit 1
fi

echo ""
echo "Selected location: $location"
echo "Are you sure this is the correct LPC11U37 mass storage location? [Y/n]"
read confirmationLoc

if [[ "$confirmationLoc" == "N" || "$confirmationLoc" == "n" ]]; then
    echo "Aborting flash operation."
    exit 1
elif [[ "$confirmationLoc" != "Y" && "$confirmationLoc" != "y" && "$confirmationLoc" != "" ]]; then
    print_error "Invalid input: $confirmationLoc"
    exit 1
fi

echo ""
echo "Flash Options:"
echo "1. Flash custom Rust firmware (recommended)"
echo "2. Flash as OEM backup firmware"
echo ""
echo "Choose option [1/2]: "
read flash_option

case $flash_option in
    1|"")
        DEST_FILE="firmware.bin"
        FLASH_TYPE="custom Rust firmware"
        ;;
    2)
        DEST_FILE="oem_firmware.bin"
        FLASH_TYPE="OEM backup firmware"
        ;;
    *)
        print_error "Invalid option: $flash_option"
        exit 1
        ;;
esac

echo ""
print_step "Flashing $FLASH_TYPE..."
print_warning "DO NOT disconnect the device during flashing!"

# Perform the flash operation
echo ""
if dd conv=notrunc oflag=direct bs=512 if=./firmware/firmware.bin of="$location/$DEST_FILE" 2>/dev/null; then
    print_success "Firmware successfully written to $location/$DEST_FILE"
else
    print_error "Flash operation failed!"
    echo "Possible causes:"
    echo "  - Insufficient permissions"
    echo "  - Device disconnected"
    echo "  - Mass storage device full"
    exit 1
fi

# Verify the file was written
if [ -f "$location/$DEST_FILE" ]; then
    WRITTEN_SIZE=$(stat -c%s "$location/$DEST_FILE")
    print_success "Verification: File written successfully ($WRITTEN_SIZE bytes)"
else
    print_error "Verification failed: File not found at destination!"
    exit 1
fi

echo ""
echo "========================================"
print_success "FIRMWARE FLASH COMPLETED!"
echo "========================================"
echo ""
echo "Next steps:"
echo "1. Safely eject the USB Mass Storage device"
echo "2. Power cycle your LPC11U37 device (disconnect and reconnect power)"
echo "3. The device should boot your custom firmware and start blinking LED D5"
echo "4. The device should NOT appear as USB Mass Storage anymore"
echo ""
print_warning "If the device still appears as USB Mass Storage after power cycle:"
echo "  - Check that ISP pin is not pulled LOW"
echo "  - Verify the firmware was built correctly"
echo "  - Try reflashing the firmware"
echo ""