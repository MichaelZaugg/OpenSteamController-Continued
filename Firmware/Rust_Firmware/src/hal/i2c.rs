use lpc11xx::I2C;

pub struct I2cDriver {
    i2c: I2C,
}

#[derive(Debug, Clone, Copy)]
pub enum I2cError {
    Nack,
    ArbitrationLost,
    Timeout,
    BusError,
}

impl I2cDriver {
    pub fn new(i2c: I2C) -> Self {
        I2cDriver { i2c }
    }

    pub fn init(&mut self) {
        // Initialize I2C peripheral
        // Configure I2C clock, enable peripheral, set up pins
        // This will need to be implemented based on LPC11U37F register layout
        
        // Enable I2C interface
        self.i2c.conset.write(|w| w.i2en().set_bit());
        
        // Set I2C frequency (100kHz for standard mode)
        // Assuming 48MHz system clock
        // I2C clock = PCLK / (SCLL + SCLH)
        // For 100kHz: 48MHz / 100kHz = 480
        // Split roughly equally between high and low periods
        let clock_div = 240;
        self.i2c.scll.write(|w| unsafe { w.bits(clock_div) });
        self.i2c.sclh.write(|w| unsafe { w.bits(clock_div) });
        
        // Clear any pending flags
        self.i2c.conclr.write(|w| w
            .si().set_bit()
            .sta().set_bit()
        );
    }

    pub fn write(&mut self, address: u8, data: &[u8]) -> Result<(), I2cError> {
        // Send START condition
        self.send_start()?;
        
        // Send address with write bit (0)
        self.send_address(address << 1)?;
        
        // Send data bytes
        for &byte in data {
            self.send_data(byte)?;
        }
        
        // Send STOP condition
        self.send_stop();
        
        Ok(())
    }

    pub fn read(&mut self, address: u8, buffer: &mut [u8]) -> Result<(), I2cError> {
        // Send START condition
        self.send_start()?;
        
        // Send address with read bit (1)
        self.send_address((address << 1) | 1)?;
        
        // Read data bytes
        let buffer_len = buffer.len();
        for (i, byte) in buffer.iter_mut().enumerate() {
            let is_last = i == buffer_len - 1;
            *byte = self.read_data(!is_last)?; // ACK all but last byte
        }
        
        // Send STOP condition
        self.send_stop();
        
        Ok(())
    }

    pub fn write_read(&mut self, address: u8, write_data: &[u8], read_buffer: &mut [u8]) -> Result<(), I2cError> {
        // Write phase
        self.send_start()?;
        self.send_address(address << 1)?;
        
        for &byte in write_data {
            self.send_data(byte)?;
        }
        
        // Repeated START for read phase
        self.send_start()?;
        self.send_address((address << 1) | 1)?;
        
        // Read phase
        let read_buffer_len = read_buffer.len();
        for (i, byte) in read_buffer.iter_mut().enumerate() {
            let is_last = i == read_buffer_len - 1;
            *byte = self.read_data(!is_last)?;
        }
        
        self.send_stop();
        Ok(())
    }

    fn send_start(&mut self) -> Result<(), I2cError> {
        // Clear STA flag and set START condition
        self.i2c.conclr.write(|w| w.sta().set_bit());
        self.i2c.conset.write(|w| w.sta().set_bit());
        
        // Wait for START condition to be sent
        self.wait_for_status(0x08) // START condition transmitted
    }

    fn send_address(&mut self, address: u8) -> Result<(), I2cError> {
        // Load address into data register
        self.i2c.dat.write(|w| unsafe { w.bits(address as u32) });
        
        // Clear START flag
        self.i2c.conclr.write(|w| w.sta().set_bit());
        
        // Wait for address to be transmitted and ACK received
        let expected_status = if address & 1 == 0 {
            0x18 // SLA+W transmitted, ACK received
        } else {
            0x40 // SLA+R transmitted, ACK received
        };
        
        self.wait_for_status(expected_status)
    }

    fn send_data(&mut self, data: u8) -> Result<(), I2cError> {
        // Load data into data register
        self.i2c.dat.write(|w| unsafe { w.bits(data as u32) });
        
        // Clear SI flag to continue
        self.i2c.conclr.write(|w| w.si().set_bit());
        
        // Wait for data to be transmitted and ACK received
        self.wait_for_status(0x28) // Data transmitted, ACK received
    }

    fn read_data(&mut self, send_ack: bool) -> Result<u8, I2cError> {
        // Set or clear ACK bit based on whether this is the last byte
        if send_ack {
            self.i2c.conset.write(|w| w.aa().set_bit());
        } else {
            self.i2c.conclr.write(|w| w.aa().set_bit());
        }
        
        // Clear SI flag to continue
        self.i2c.conclr.write(|w| w.si().set_bit());
        
        // Wait for data to be received
        let expected_status = if send_ack {
            0x50 // Data received, ACK transmitted
        } else {
            0x58 // Data received, NACK transmitted
        };
        
        self.wait_for_status(expected_status)?;
        
        // Read received data
        Ok(self.i2c.dat.read().bits() as u8)
    }

    fn send_stop(&mut self) {
        // Set STOP condition
        self.i2c.conset.write(|w| w.sto().set_bit());
        
        // Clear SI flag
        self.i2c.conclr.write(|w| w.si().set_bit());
    }

    fn wait_for_status(&mut self, expected_status: u8) -> Result<(), I2cError> {
        // Simple timeout counter
        let mut timeout = 10000;
        
        while timeout > 0 {
            // Check if SI flag is set (operation complete)
            if self.i2c.conset.read().si().bit_is_set() {
                let status = self.i2c.stat.read().bits() as u8;
                
                if status == expected_status {
                    return Ok(());
                }
                
                // Handle error conditions
                match status {
                    0x20 | 0x30 => return Err(I2cError::Nack), // NACK received
                    0x38 => return Err(I2cError::ArbitrationLost), // Arbitration lost
                    0x00 => return Err(I2cError::BusError), // Bus error
                    _ => return Err(I2cError::BusError), // Other error
                }
            }
            
            timeout -= 1;
        }
        
        Err(I2cError::Timeout)
    }

    pub fn is_busy(&self) -> bool {
        self.i2c.conset.read().si().bit_is_set()
    }
}