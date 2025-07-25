#!/usr/bin/env python3
import struct
import sys

def fix_lpc_checksum(filename):
    """Fix the LPC checksum in vector 7 of the binary file"""
    
    with open(filename, 'rb') as f:
        data = bytearray(f.read())
    
    if len(data) < 32:
        print("Error: Binary too small (needs at least 32 bytes)")
        return False
    
    # Read the first 7 vectors (28 bytes)
    vectors = []
    for i in range(7):
        vector = struct.unpack('<L', data[i*4:(i+1)*4])[0]
        vectors.append(vector)
        print(f"Vector {i}: 0x{vector:08x}")
    
    # Calculate sum of first 7 vectors
    vector_sum = sum(vectors) & 0xFFFFFFFF
    print(f"Sum of vectors 0-6: 0x{vector_sum:08x}")
    
    # Calculate checksum (two's complement)
    checksum = (0x100000000 - vector_sum) & 0xFFFFFFFF
    print(f"Required checksum: 0x{checksum:08x}")
    
    # Write checksum to vector 7 (offset 0x1C)
    struct.pack_into('<L', data, 28, checksum)
    
    # Verify the sum is now zero
    total_sum = (vector_sum + checksum) & 0xFFFFFFFF
    print(f"Verification - total sum: 0x{total_sum:08x}")
    
    if total_sum != 0:
        print("Warning: Checksum verification failed!")
        return False
    
    # Write the corrected binary
    with open(filename, 'wb') as f:
        f.write(data)
    
    print(f"Checksum fixed! Vector 7 set to 0x{checksum:08x}")
    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 fix_lpc_checksum.py firmware.bin")
        sys.exit(1)
    
    filename = sys.argv[1]
    if fix_lpc_checksum(filename):
        print("Success! Binary is ready for flashing.")
    else:
        print("Failed to fix checksum.")
        sys.exit(1)