#!/bin/bash

# LPC11U37 Firmware Build Script
# Compiles Rust code, extracts binary, adds checksum, and prepares for flashing

set -e  # Exit on any error

echo "=========================================="
echo "  Steam Controller Firmware Build Script  "
echo "=========================================="

# Configuration
TARGET="thumbv6m-none-eabi"
FIRMWARE_DIR="./firmware"
BINARY_NAME="lpc11u37_blink"
FLASH_SIZE=131072  # 128KB

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

# Create firmware directory if it doesn't exist
print_step "Creating firmware directory..."
mkdir -p "$FIRMWARE_DIR"

# Clean previous build
print_step "Cleaning previous build..."
cargo clean

# Build the Rust project
print_step "Building Rust project for $TARGET..."
cargo build --target "$TARGET" --release

if [ $? -ne 0 ]; then
    print_error "Cargo build failed!"
    exit 1
fi

print_success "Rust build completed"

# Extract binary using cargo objcopy
print_step "Extracting binary with cargo objcopy..."
cargo objcopy --target "$TARGET" --release -- -O binary "$FIRMWARE_DIR/firmware_raw.bin"

if [ $? -ne 0 ]; then
    print_error "Binary extraction failed!"
    exit 1
fi

print_success "Binary extracted to $FIRMWARE_DIR/firmware_raw.bin"

# Show original binary info
ORIGINAL_SIZE=$(stat -c%s "$FIRMWARE_DIR/firmware_raw.bin")
print_step "Original binary size: $ORIGINAL_SIZE bytes"

# Create 128KB padded version
print_step "Creating 128KB padded firmware..."
dd if=/dev/zero bs="$FLASH_SIZE" count=1 2>/dev/null | tr '\0' '\377' > "$FIRMWARE_DIR/firmware_padded.bin"
dd conv=notrunc if="$FIRMWARE_DIR/firmware_raw.bin" of="$FIRMWARE_DIR/firmware_padded.bin" 2>/dev/null

print_success "Created 128KB padded firmware"

# Create checksum fixer script inline
print_step "Adding LPC checksum..."
cat > "$FIRMWARE_DIR/add_checksum.py" << 'EOF'
#!/usr/bin/env python3
import struct
import sys

def fix_lpc_checksum(filename):
    with open(filename, 'rb') as f:
        data = bytearray(f.read())
    
    if len(data) < 32:
        print("Error: Binary too small")
        return False
    
    # Read first 7 vectors
    vectors = []
    for i in range(7):
        vector = struct.unpack('<L', data[i*4:(i+1)*4])[0]
        vectors.append(vector)
    
    # Calculate checksum
    vector_sum = sum(vectors) & 0xFFFFFFFF
    checksum = (0x100000000 - vector_sum) & 0xFFFFFFFF
    
    # Write checksum to vector 7
    struct.pack_into('<L', data, 28, checksum)
    
    # Verify
    total_sum = (vector_sum + checksum) & 0xFFFFFFFF
    if total_sum != 0:
        print("Checksum verification failed!")
        return False
    
    # Write corrected binary
    with open(filename, 'wb') as f:
        f.write(data)
    
    print(f"Checksum added: 0x{checksum:08x}")
    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 add_checksum.py firmware.bin")
        sys.exit(1)
    
    if fix_lpc_checksum(sys.argv[1]):
        print("Checksum successfully added!")
    else:
        print("Failed to add checksum!")
        sys.exit(1)
EOF

# Run checksum script
python3 "$FIRMWARE_DIR/add_checksum.py" "$FIRMWARE_DIR/firmware_padded.bin"

if [ $? -ne 0 ]; then
    print_error "Checksum addition failed!"
    exit 1
fi

# Copy final firmware
cp "$FIRMWARE_DIR/firmware_padded.bin" "$FIRMWARE_DIR/firmware.bin"

print_success "Final firmware ready: $FIRMWARE_DIR/firmware.bin"

# Show final binary info
print_step "Firmware Information:"
echo "  - Raw size: $ORIGINAL_SIZE bytes"
echo "  - Final size: $(stat -c%s "$FIRMWARE_DIR/firmware.bin") bytes"
echo "  - Target: $TARGET"
echo "  - Flash utilization: $(echo "scale=2; $ORIGINAL_SIZE * 100 / $FLASH_SIZE" | bc)%"

# Verify vector table
print_step "Vector table verification:"
hexdump -C "$FIRMWARE_DIR/firmware.bin" | head -2

# Show usage instructions
echo ""
echo "========================================"
echo -e "${GREEN}BUILD COMPLETED SUCCESSFULLY!${NC}"
echo "========================================"
echo ""
echo "To flash the firmware:"
echo "1. Connect your LPC11U37 in ISP mode (USB mass storage)"
echo "2. Run your flash script with: $FIRMWARE_DIR/firmware.bin"
echo "3. Power cycle the device"
echo ""
echo "Files created:"
echo "  - $FIRMWARE_DIR/firmware_raw.bin    (original binary)"
echo "  - $FIRMWARE_DIR/firmware_padded.bin (128KB with checksum)"
echo "  - $FIRMWARE_DIR/firmware.bin        (final firmware for flashing)"
echo ""

# Cleanup
rm -f "$FIRMWARE_DIR/add_checksum.py"
print_success "Build script completed!"