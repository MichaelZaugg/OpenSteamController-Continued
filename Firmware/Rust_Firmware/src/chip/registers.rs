

pub struct GpioRegisters {
    // Offset 0x0000: Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31
    // The C uses [128][32], so we maintain that for direct memory layout compatibility.
    pub b: [[u8; 32]; 128], // Byte pin registers (access via volatile read/write)

    // Offset 0x1000: Word pin registers port 0 to n
    pub w: [[u32; 32]; 32], // Word pin registers (access via volatile read/write)

    // Offset 0x2000: Direction registers port n
    pub dir: [u32; 32], // Direction registers (access via volatile read/write)

    // Offset 0x2080: Mask register port n
    pub mask: [u32; 32], // Mask register (access via volatile read/write)

    // Offset 0x2100: Portpin register port n
    pub pin: [u32; 32], // Portpin register (access via volatile read/write)

    // Offset 0x2180: Masked port register port n
    pub mpin: [u32; 32], // Masked port register (access via volatile read/write)

    // Offset 0x2200: Write: Set register for port n Read: output bits for port n
    pub set: [u32; 32], // Set register (access via volatile read/write)

    // Offset 0x2280: Clear port n
    pub clr: [u32; 32], // Clear register (access via volatile read/write)

    // Offset 0x2300: Toggle port n
    pub not: [u32; 32], // Toggle register (access via volatile read/write)
}