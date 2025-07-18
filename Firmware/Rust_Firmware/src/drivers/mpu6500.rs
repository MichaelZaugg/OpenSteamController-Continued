use crate::hal::{I2cDriver, I2cError};

// MPU-6500 I2C address (with AD0 pin low)
const MPU6500_ADDR: u8 = 0x68;

// MPU-6500 register addresses
const PWR_MGMT_1: u8 = 0x6B;
const PWR_MGMT_2: u8 = 0x6C;
const SMPLRT_DIV: u8 = 0x19;
const CONFIG: u8 = 0x1A;
const GYRO_CONFIG: u8 = 0x1B;
const ACCEL_CONFIG: u8 = 0x1C;
const ACCEL_CONFIG_2: u8 = 0x1D;
const WHO_AM_I: u8 = 0x75;

// Data register addresses
const ACCEL_XOUT_H: u8 = 0x3B;
const GYRO_XOUT_H: u8 = 0x43;
const TEMP_OUT_H: u8 = 0x41;

// Expected WHO_AM_I value for MPU-6500
const MPU6500_WHO_AM_I: u8 = 0x70;

#[derive(Debug, Clone, Copy)]
pub enum Mpu6500Error {
    I2cError(I2cError),
    InvalidDevice,
    InvalidConfig,
}

impl From<I2cError> for Mpu6500Error {
    fn from(error: I2cError) -> Self {
        Mpu6500Error::I2cError(error)
    }
}

#[derive(Debug, Clone, Copy)]
pub struct AccelData {
    pub x: i16,
    pub y: i16,
    pub z: i16,
}

#[derive(Debug, Clone, Copy)]
pub struct GyroData {
    pub x: i16,
    pub y: i16,
    pub z: i16,
}

#[derive(Debug, Clone, Copy)]
pub enum AccelRange {
    Range2G = 0,
    Range4G = 1,
    Range8G = 2,
    Range16G = 3,
}

#[derive(Debug, Clone, Copy)]
pub enum GyroRange {
    Range250DPS = 0,
    Range500DPS = 1,
    Range1000DPS = 2,
    Range2000DPS = 3,
}

pub struct Mpu6500 {
    i2c: I2cDriver,
    accel_range: AccelRange,
    gyro_range: GyroRange,
}

impl Mpu6500 {
    pub fn new(i2c: I2cDriver) -> Self {
        Mpu6500 {
            i2c,
            accel_range: AccelRange::Range2G,
            gyro_range: GyroRange::Range250DPS,
        }
    }

    pub fn init(&mut self) -> Result<(), Mpu6500Error> {
        // Check device ID
        let who_am_i = self.read_register(WHO_AM_I)?;
        if who_am_i != MPU6500_WHO_AM_I {
            return Err(Mpu6500Error::InvalidDevice);
        }

        // Reset device
        self.write_register(PWR_MGMT_1, 0x80)?;
        
        // Wait for reset to complete (typically 100ms)
        // In a real implementation, you'd want a proper delay
        for _ in 0..100000 {
            // Simple delay loop
        }

        // Wake up device and set clock source to PLL with X axis gyroscope reference
        self.write_register(PWR_MGMT_1, 0x01)?;
        
        // Configure sample rate divider (1kHz / (1 + 7) = 125Hz)
        self.write_register(SMPLRT_DIV, 0x07)?;
        
        // Configure low pass filter (DLPF_CFG = 3, ~42Hz)
        self.write_register(CONFIG, 0x03)?;
        
        // Configure gyroscope range
        self.set_gyro_range(self.gyro_range)?;
        
        // Configure accelerometer range
        self.set_accel_range(self.accel_range)?;
        
        // Configure accelerometer low pass filter
        self.write_register(ACCEL_CONFIG_2, 0x03)?;
        
        // Enable all sensors
        self.write_register(PWR_MGMT_2, 0x00)?;

        Ok(())
    }

    pub fn set_accel_range(&mut self, range: AccelRange) -> Result<(), Mpu6500Error> {
        self.accel_range = range;
        let config_value = (range as u8) << 3;
        self.write_register(ACCEL_CONFIG, config_value)?;
        Ok(())
    }

    pub fn set_gyro_range(&mut self, range: GyroRange) -> Result<(), Mpu6500Error> {
        self.gyro_range = range;
        let config_value = (range as u8) << 3;
        self.write_register(GYRO_CONFIG, config_value)?;
        Ok(())
    }

    pub fn read_accel(&mut self) -> Result<AccelData, Mpu6500Error> {
        let mut data = [0u8; 6];
        self.i2c.write_read(MPU6500_ADDR, &[ACCEL_XOUT_H], &mut data)?;
        
        Ok(AccelData {
            x: ((data[0] as i16) << 8) | (data[1] as i16),
            y: ((data[2] as i16) << 8) | (data[3] as i16),
            z: ((data[4] as i16) << 8) | (data[5] as i16),
        })
    }

    pub fn read_gyro(&mut self) -> Result<GyroData, Mpu6500Error> {
        let mut data = [0u8; 6];
        self.i2c.write_read(MPU6500_ADDR, &[GYRO_XOUT_H], &mut data)?;
        
        Ok(GyroData {
            x: ((data[0] as i16) << 8) | (data[1] as i16),
            y: ((data[2] as i16) << 8) | (data[3] as i16),
            z: ((data[4] as i16) << 8) | (data[5] as i16),
        })
    }

    pub fn read_temp(&mut self) -> Result<i16, Mpu6500Error> {
        let mut data = [0u8; 2];
        self.i2c.write_read(MPU6500_ADDR, &[TEMP_OUT_H], &mut data)?;
        
        Ok(((data[0] as i16) << 8) | (data[1] as i16))
    }

    pub fn read_all(&mut self) -> Result<(AccelData, GyroData, i16), Mpu6500Error> {
        // Read all sensor data in one transaction for efficiency
        let mut data = [0u8; 14];
        self.i2c.write_read(MPU6500_ADDR, &[ACCEL_XOUT_H], &mut data)?;
        
        let accel = AccelData {
            x: ((data[0] as i16) << 8) | (data[1] as i16),
            y: ((data[2] as i16) << 8) | (data[3] as i16),
            z: ((data[4] as i16) << 8) | (data[5] as i16),
        };
        
        let temp = ((data[6] as i16) << 8) | (data[7] as i16);
        
        let gyro = GyroData {
            x: ((data[8] as i16) << 8) | (data[9] as i16),
            y: ((data[10] as i16) << 8) | (data[11] as i16),
            z: ((data[12] as i16) << 8) | (data[13] as i16),
        };
        
        Ok((accel, gyro, temp))
    }

    fn write_register(&mut self, register: u8, value: u8) -> Result<(), Mpu6500Error> {
        self.i2c.write(MPU6500_ADDR, &[register, value])?;
        Ok(())
    }

    fn read_register(&mut self, register: u8) -> Result<u8, Mpu6500Error> {
        let mut data = [0u8; 1];
        self.i2c.write_read(MPU6500_ADDR, &[register], &mut data)?;
        Ok(data[0])
    }

    // Convert raw accelerometer data to m/s² (approximate)
    pub fn accel_to_ms2(&self, raw: i16) -> f32 {
        let sensitivity = match self.accel_range {
            AccelRange::Range2G => 16384.0,
            AccelRange::Range4G => 8192.0,
            AccelRange::Range8G => 4096.0,
            AccelRange::Range16G => 2048.0,
        };
        
        (raw as f32 / sensitivity) * 9.81
    }

    // Convert raw gyroscope data to degrees per second
    pub fn gyro_to_dps(&self, raw: i16) -> f32 {
        let sensitivity = match self.gyro_range {
            GyroRange::Range250DPS => 131.0,
            GyroRange::Range500DPS => 65.5,
            GyroRange::Range1000DPS => 32.8,
            GyroRange::Range2000DPS => 16.4,
        };
        
        raw as f32 / sensitivity
    }

    // Convert raw temperature data to Celsius
    pub fn temp_to_celsius(&self, raw: i16) -> f32 {
        (raw as f32 / 333.87) + 21.0
    }

    // Advanced motion processing methods
    
    /// Read all sensor data and apply calibration
    pub fn read_calibrated_data(&mut self) -> Result<(AccelData, GyroData, i16), Mpu6500Error> {
        let (accel, gyro, temp) = self.read_all()?;
        
        // Apply simple calibration (in production, these would be stored values)
        let calibrated_accel = AccelData {
            x: accel.x,  // In a real system, subtract bias
            y: accel.y,
            z: accel.z,
        };
        
        let calibrated_gyro = GyroData {
            x: gyro.x,   // In a real system, subtract bias
            y: gyro.y,
            z: gyro.z,
        };
        
        Ok((calibrated_accel, calibrated_gyro, temp))
    }
    
    /// Perform gyroscope calibration (device should be stationary)
    pub fn calibrate_gyro(&mut self) -> Result<GyroData, Mpu6500Error> {
        let mut sum_x = 0i32;
        let mut sum_y = 0i32;
        let mut sum_z = 0i32;
        let samples = 100;
        
        for _ in 0..samples {
            let gyro = self.read_gyro()?;
            sum_x += gyro.x as i32;
            sum_y += gyro.y as i32;
            sum_z += gyro.z as i32;
            
            // Small delay between samples
            for _ in 0..1000 {
                core::hint::spin_loop();
            }
        }
        
        Ok(GyroData {
            x: (sum_x / samples) as i16,
            y: (sum_y / samples) as i16,
            z: (sum_z / samples) as i16,
        })
    }
    
    /// Perform accelerometer calibration (device should be in various orientations)
    pub fn calibrate_accel(&mut self) -> Result<AccelData, Mpu6500Error> {
        let mut sum_x = 0i32;
        let mut sum_y = 0i32;
        let mut sum_z = 0i32;
        let samples = 100;
        
        for _ in 0..samples {
            let accel = self.read_accel()?;
            sum_x += accel.x as i32;
            sum_y += accel.y as i32;
            sum_z += accel.z as i32;
            
            // Small delay between samples
            for _ in 0..1000 {
                core::hint::spin_loop();
            }
        }
        
        Ok(AccelData {
            x: (sum_x / samples) as i16,
            y: (sum_y / samples) as i16,
            z: (sum_z / samples) as i16,
        })
    }
    
    /// Enable/disable motion detection interrupt
    pub fn enable_motion_interrupt(&mut self, threshold: u8) -> Result<(), Mpu6500Error> {
        // Configure motion detection threshold
        self.write_register(0x1F, threshold)?; // Motion threshold register
        
        // Enable motion interrupt
        self.write_register(0x38, 0x40)?; // Enable motion interrupt
        
        Ok(())
    }
    
    /// Read motion interrupt status
    pub fn get_motion_interrupt_status(&mut self) -> Result<bool, Mpu6500Error> {
        let status = self.read_register(0x3A)?; // Interrupt status register
        Ok((status & 0x40) != 0) // Motion interrupt bit
    }
    
    /// Configure sample rate for optimal performance
    pub fn configure_for_gaming(&mut self) -> Result<(), Mpu6500Error> {
        // Set sample rate to 1kHz (good for gaming)
        self.write_register(SMPLRT_DIV, 0x00)?;
        
        // Configure DLPF for better noise performance
        self.write_register(CONFIG, 0x01)?; // 184Hz bandwidth
        
        // Configure gyro for 1000 DPS (good sensitivity for gaming)
        self.set_gyro_range(GyroRange::Range1000DPS)?;
        
        // Configure accel for 8G range (good for gaming movements)
        self.set_accel_range(AccelRange::Range8G)?;
        
        // Configure accelerometer DLPF
        self.write_register(ACCEL_CONFIG_2, 0x01)?; // 184Hz bandwidth
        
        Ok(())
    }
    
    /// Get data ready status
    pub fn is_data_ready(&mut self) -> Result<bool, Mpu6500Error> {
        let status = self.read_register(0x3A)?; // Interrupt status register
        Ok((status & 0x01) != 0) // Data ready bit
    }
    
    /// Advanced filtering functions
    pub fn apply_low_pass_filter(&self, current: i16, previous: i16, alpha: f32) -> i16 {
        let filtered = alpha * (current as f32) + (1.0 - alpha) * (previous as f32);
        filtered as i16
    }
    
    /// Calculate magnitude of acceleration vector
    pub fn accel_magnitude(&self, accel: AccelData) -> f32 {
        let x = self.accel_to_ms2(accel.x);
        let y = self.accel_to_ms2(accel.y);
        let z = self.accel_to_ms2(accel.z);
        
        libm::sqrtf(x * x + y * y + z * z)
    }
    
    /// Calculate magnitude of gyroscope vector
    pub fn gyro_magnitude(&self, gyro: GyroData) -> f32 {
        let x = self.gyro_to_dps(gyro.x);
        let y = self.gyro_to_dps(gyro.y);
        let z = self.gyro_to_dps(gyro.z);
        
        libm::sqrtf(x * x + y * y + z * z)
    }
}