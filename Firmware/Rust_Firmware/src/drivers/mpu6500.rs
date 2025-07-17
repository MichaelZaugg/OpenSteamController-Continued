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
}