use lpc11xx;

use crate::hal::with_peripherals;


#[derive(Clone, Copy)]
pub struct Pin
{
    pub dir: u8,
    pub pin: u8
}

impl Pin
{
    pub fn new(dir: u8, pin: u8) -> Result<Self, PinError>
    {
        if dir > 3 {return Err(PinError::InvalidPort)}
        if pin > 31 {return Err(PinError::InvalidPin)}
        Ok( Pin {dir, pin})
    }
}


pub enum PinValue
{
    LOW,
    HIGH
}


#[derive(Debug, Clone, Copy)]
pub enum PinMode {
    Input,
    Output
}

#[derive(Debug, Clone, Copy)]
pub enum PinError
{
    InvalidPin,
    InvalidPort,
    PeripheralsTaken
}



/// Val: 0=input 1=output
pub fn set_pin_mode(pin: Pin, val: PinMode) -> Result<(), PinError>
{
    if pin.pin > 31 { return Err(PinError::InvalidPin); }

    let _ = with_peripherals(|dp|
    {
        match pin.dir
        {
            0 => dp.GPIO0.dir.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            1 => dp.GPIO1.dir.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            2 => dp.GPIO2.dir.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            3 => dp.GPIO3.dir.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            _ => return Err(PinError::InvalidPort)    
        }
        Ok(())
    })?;

    Ok(())
}


pub fn gpio_digital_write(pin: Pin, val: PinValue) -> Result<(), PinError>
{
    if pin.pin > 31 { return Err(PinError::InvalidPin); }

    let _ = with_peripherals(|dp|
    {
        match pin.dir
        {
            0 => dp.GPIO0.data.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            1 => dp.GPIO1.data.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            2 => dp.GPIO2.data.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            3 => dp.GPIO3.data.modify(|r, w| unsafe { w.bits((r.bits() & !(1 << pin.pin)) | ((val as u32) << pin.pin)) }),
            _ => return Err(PinError::InvalidPort)    
        }
        Ok(())
    })?;

    Ok(())
}

pub fn gpio_digital_read(pin: Pin) -> Result<PinValue, PinError>
{
    if pin.pin > 31 { return Err(PinError::InvalidPin); }

    let pin_read = with_peripherals(|dp|
    {
        match pin.dir
        {
            0 => return Ok(dp.GPIO0.data.read().bits()),
            1 => return Ok(dp.GPIO1.data.read().bits()),
            2 => return Ok(dp.GPIO2.data.read().bits()),
            3 => return Ok(dp.GPIO3.data.read().bits()),
            _ => return Err(PinError::InvalidPort)    
        }
    })??;

    let read_value = (pin_read >> pin.pin) & 1;

    if read_value == 0
    {
        Ok(PinValue::LOW)
    }
    else
    {
        Ok(PinValue::HIGH)
    }
}


pub fn toggle_gpio(pin: Pin) -> Result<(), PinError>
{
    if pin.pin > 31 { return Err(PinError::InvalidPin); }

    let _ = with_peripherals(|dp|
    {
            match pin.dir {
            0 => unsafe {dp.GPIO0.data.modify(|r, w| w.bits(r.bits() ^ (1 << pin.pin)))},
            1 => unsafe {dp.GPIO1.data.modify(|r, w| w.bits(r.bits() ^ (1 << pin.pin)))},
            2 => unsafe {dp.GPIO2.data.modify(|r, w| w.bits(r.bits() ^ (1 << pin.pin)))},
            3 => unsafe {dp.GPIO3.data.modify(|r, w| w.bits(r.bits() ^ (1 << pin.pin)))},
            _ => return Err(PinError::InvalidPort)
        }
        Ok(())
    })?;
    
    Ok(())
}

// mod Registers
// {

// }