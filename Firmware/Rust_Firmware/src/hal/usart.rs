use lpc11xx::UART;
use nb;

pub struct UsartDriver {
    uart: UART,
}

impl UsartDriver {
    pub fn new(uart: UART) -> Self {
        UsartDriver { uart }
    }

    pub fn init(&mut self, baud_rate: u32) {
        // Configure UART for communication with nRF51822
        // Set baud rate, data bits, stop bits, parity
        // This will need to be implemented based on LPC11U37F specs
        
        // Enable UART clock (assuming system clock is enabled)
        // Configure baud rate divisor
        // For now, we'll use a simple divisor calculation
        // Actual implementation would need system clock frequency
        let divisor = 48_000_000 / (16 * baud_rate); // Assuming 48MHz system clock
        
        // Set DLAB bit to access divisor registers
        self.uart.lcr.modify(|_, w| w.dlab().set_bit());
        
        // Set divisor
        self.uart.dll().write(|w| unsafe { w.bits((divisor & 0xFF) as u32) });
        self.uart.dlm().write(|w| unsafe { w.bits(((divisor >> 8) & 0xFF) as u32) });
        
        // Clear DLAB and set data format (8N1)
        self.uart.lcr.write(|w| w
            .dlab().clear_bit()
            .wls().bits(0b11)  // 8 data bits
            .sbs().clear_bit() // 1 stop bit
            .pe().clear_bit() // No parity
        );
        
        // Enable FIFO
        self.uart.fcr().write(|w| w
            .fifoen().set_bit()
            .rxfifores().set_bit()
            .txfifores().set_bit()
        );
        
        // Enable UART
        // (UART is enabled by default on LPC11xx)
    }

    pub fn write(&mut self, byte: u8) -> nb::Result<(), ()> {
        // Check if transmit buffer is ready
        if self.uart.lsr.read().thre().bit_is_set() {
            self.uart.thr().write(|w| unsafe { w.bits(byte as u32) });
            Ok(())
        } else {
            Err(nb::Error::WouldBlock)
        }
    }

    pub fn flush(&mut self) -> nb::Result<(), ()> {
        // Wait for transmit shift register to be empty
        if self.uart.lsr.read().temt().bit_is_set() {
            Ok(())
        } else {
            Err(nb::Error::WouldBlock)
        }
    }

    pub fn read(&mut self) -> nb::Result<u8, ()> {
        // Check if receive buffer has data
        if self.uart.lsr.read().rdr().bit_is_set() {
            Ok(self.uart.rbr().read().bits() as u8)
        } else {
            Err(nb::Error::WouldBlock)
        }
    }

    pub fn write_bytes(&mut self, data: &[u8]) -> Result<(), ()> {
        for &byte in data {
            loop {
                match self.write(byte) {
                    Ok(()) => break,
                    Err(nb::Error::WouldBlock) => continue,
                    Err(nb::Error::Other(_)) => return Err(()),
                }
            }
        }
        Ok(())
    }

    pub fn read_bytes(&mut self, buffer: &mut [u8]) -> Result<usize, ()> {
        let mut count = 0;
        for byte in buffer.iter_mut() {
            match self.read() {
                Ok(data) => {
                    *byte = data;
                    count += 1;
                }
                Err(nb::Error::WouldBlock) => break,
                Err(nb::Error::Other(_)) => return Err(()),
            }
        }
        Ok(count)
    }

    pub fn write_str(&mut self, s: &str) -> Result<(), ()> {
        self.write_bytes(s.as_bytes())
    }

    pub fn data_available(&self) -> bool {
        self.uart.lsr.read().rdr().bit_is_set()
    }

    pub fn tx_ready(&self) -> bool {
        self.uart.lsr.read().thre().bit_is_set()
    }

    pub fn tx_empty(&self) -> bool {
        self.uart.lsr.read().temt().bit_is_set()
    }
}