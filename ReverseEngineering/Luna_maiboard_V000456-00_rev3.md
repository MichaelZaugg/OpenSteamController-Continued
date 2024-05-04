# Luna_mainboard V000456-00 rev3

This document exists to track information regarding the Steam Controller
hardware pertaining to Luna_mainboard V000456-00 rev3.

Note that this [Teardown of Steam Controller](https://www.ifixit.com/Teardown/Steam+Controller+Teardown/52578)
was extremely helpful in identifying chips and offering guidance in disassembling
the Steam Controller to ohm out connections, etc.

# LPC11U37F/501

This is an ARM Cortex-M0, and seems to be the main/master processor of the Steam Controller.

## Resources

This sections tracks useful documentation related to the processor.

* [Product Information](https://www.nxp.com/part/LPC11U37FBD64?lang_cd=en)
* [Datasheet](./Datasheets_Documentation/LPC11U37F/lpc11u3x.pdf)
* [User Manual](./Datasheets_Documentation/LPC11U37F/um10462.pdf)

## Pinout

This sections details how the pins of the process are configured and (potentially) used.


| Pin Number | Datasheet Name | Pin Function     | Pin Direction | Notes                                                                                                                                                                                                                                                                                                                     |
| -----------: | ---------------- | ------------------ | --------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|          1 | PIO1_0         | PIO1_0           | In            | Analog joystick click button                                                                                                                                                                                                                                                                                              |
|          2 | PIO1_25        | PIO1_25          | In            | S14 - Left inner grip button                                                                                                                                                                                                                                                                                              |
|          3 | PIO1_19        | PIO1_19          | In            | S18 - Steam button                                                                                                                                                                                                                                                                                                        |
|          4 | PIO0_0/nRESET  |                  |               |                                                                                                                                                                                                                                                                                                                           |
|          5 | PIO0_1         |                  |               | Connected to S6 - RT (Right trigger digital) for purpose of enacting USB In-Systen Programming (i.e. update firmware via "FAT" file system)                                                                                                                                                                               |
|          6 | PIO1_7         | PIO1_7           | Out           | Active Low haptics enable.                                                                                                                                                                                                                                                                                                |
|          7 | V<sub>SS</sub> | V<sub>SS</sub>   | In            | V<sub>SS</sub>                                                                                                                                                                                                                                                                                                            |
|          8 | XTALIN         |                  |               |                                                                                                                                                                                                                                                                                                                           |
|          9 | XTALOUT        |                  |               |                                                                                                                                                                                                                                                                                                                           |
|         10 | V<sub>DD</sub> | V<sub>DD</sub>   | In            | V<sub>DD</sub>                                                                                                                                                                                                                                                                                                            |
|         11 | PIO0_20        |                  |               |                                                                                                                                                                                                                                                                                                                           |
|         12 | PIO1_10        | PIO1_10          | Out           | TODO: get more info on this... Set as output GPIO and driven ?? (during init). Related to AD? Or has to do with BOD and controller booting up... (routed to pin ??(middle) on U10 on front of PCB)                                                                                                                        |
|         13 | PIO0_2         | PIO0_2           | In            | Interrupt (PINT1) setup to monitor if this changes (trace leads to C56, continues to...). Seems to have something to do with Brown Out Detection.                                                                                                                                                                         |
|         14 | PIO1_26        | PIO1_26          | In            | S2 - Left trackpad click                                                                                                                                                                                                                                                                                                  |
|         15 | PIO1_27        | PIO1_27          | In            | S3 - LT (Left trigger digital)                                                                                                                                                                                                                                                                                            |
|         16 | PIO1_4         | PIO1_4           | In            | S8 - LB (Left bumper)                                                                                                                                                                                                                                                                                                     |
|         17 | PIO1_1         | PIO1_1           | Out           | Active low enable for analog triggers (Left = AD0, Right = AD2)                                                                                                                                                                                                                                                           |
|         18 | PIO1_20        | PIO1_20          | In            | S17 - FRONT_L (Front left arrow button)                                                                                                                                                                                                                                                                                   |
|         19 | PIO0_3         | USB_VBUS         | In            | Monitors the presence of USB bus power. Interrupt (PINT0) set to monitor if this changes.                                                                                                                                                                                                                                 |
|         20 | PIO0_4         | I2C SCL          | In/Out        | Connected to MPU-6500 I2C SCL                                                                                                                                                                                                                                                                                             |
|         21 | PIO0_5         | I2C SDA          | In/Out        | Connected to MPU-6500 I2C SDA                                                                                                                                                                                                                                                                                             |
|         22 | PIO0_21        | CT16B1_MAT0      | Out           | Control Steam Button LED (LED1)                                                                                                                                                                                                                                                                                           |
|         23 | PIO1_17        | RXD (USART)      | In            | Connected to Nordic Semiconductor nRF51822 Bluetooth Smart and 2.4GHz proprietary SoC Pin 21                                                                                                                                                                                                                              |
|         24 | PIO1_23        |                  |               | Connected to MPU-6500 Pin 12 (INT)                                                                                                                                                                                                                                                                                        |
|         25 | USB_DM         |                  |               |                                                                                                                                                                                                                                                                                                                           |
|         26 | USB_DP         |                  |               |                                                                                                                                                                                                                                                                                                                           |
|         27 | PIO1_24        | PIO1_24          | In?           | Related to PIO1_8. Related to USART maybe? TODO                                                                                                                                                                                                                                                                           |
|         28 | PIO1_18        | TXD (USART)      | Out           | Connected to Nordic Semiconductor nRF51822 Bluetooth Smart and 2.4GHz proprietary SoC Pin 20                                                                                                                                                                                                                              |
|         29 | PIO0_6         | not(USB_CONNECT) | Out           | Signal used to switch an external 1.5 k resistor under software control. Used with the SoftConnect USB feature.                                                                                                                                                                                                           |
|         30 | PIO0_7         | PIO0_7           | Out           | Set as output GPIO and driven low during init (trace leads to R9 (no-pop)). Related/similar to GPIO1_28? Any other purpose? More details? TODO                                                                                                                                                                            |
|         31 | PIO1_28        | PIO1_28          | Out           | Set as output GPIO and driven low during init (trace leads to R8 (no-pop)). Related/similar to GPIO0_7? Any other purpose? More details? TODO                                                                                                                                                                             |
|         32 | PIO1_5         | PIO1_5           | In            | USART/Radio Chip Related. PINT2 setup to monitor change. Trace leads to TODO                                                                                                                                                                                                                                              |
|         33 | V<sub>DD</sub> | V<sub>DD</sub>   | In            | V<sub>DD</sub>                                                                                                                                                                                                                                                                                                            |
|         34 | PIO1_2         | PIO1_2           | In            | S19 - FRONT_R (Front right arrow button)                                                                                                                                                                                                                                                                                  |
|         35 | PIO1_21        | PIO1_21          | In            | S5 - Right trackpad click                                                                                                                                                                                                                                                                                                 |
|         36 | PIO0_8         | MISO0            | In            | Master In Slave Out for SSP0. Connected to MISO on Right Trackpad/Haptic and Left Trackpad/Haptic.                                                                                                                                                                                                                        |
|         37 | PIO0_9         | MOSI0            | Out           | Master Out Slave In for SSP0. Connected to MOSI on Right Trackpad/Haptic and Left Trackpad/Haptic.                                                                                                                                                                                                                        |
|         38 | SWCLK/PIO0_10  | SWCLK?           |               | Connected to DEBUG interface for LPC11U37F                                                                                                                                                                                                                                                                                |
|         39 | PIO1_8         | PIO1_8           | In?           | Related to PIO1_24. Related to USART maybe? TODO                                                                                                                                                                                                                                                                          |
|         40 | PIO0_22        | AD6              | In            | Measures voltage that matters when no USB power is present? (trace leads to C6, continues to R10 near power...)                                                                                                                                                                                                           |
|         41 | PIO1_29        | SCK0             | Out           | Serial clock for SSP0. Connected to SCLK on Right Trackpad/Haptic and Left Trackpad/Haptic.                                                                                                                                                                                                                               |
|         42 | TDI/PIO0_11    | AD0              | In            | Measures Left Analog trigger position (when PIO1_1 is low) (Note: Functions as TDI for short time during initialization)                                                                                                                                                                                                  |
|         43 | PIO1_11        | PIO1_11          | In            | S9 - Y Button                                                                                                                                                                                                                                                                                                             |
|         44 | TMS/PIO0_12    | AD1              | In            | Measure Analog Joystick X position                                                                                                                                                                                                                                                                                        |
|         45 | TDO/PIO0_13    | AD2              | In            | Measures Right Analog trigger position (when PIO1_1 is low) (Note: Functions as TDO for short time during initialization)                                                                                                                                                                                                 |
|         46 | nTRST/PIO0_14  | AD3              | In            | Measure Analog Joystick Y position                                                                                                                                                                                                                                                                                        |
|         47 | PIO1_13        | PIO1_13          | In            | S6 - RT (Right trigger digital)                                                                                                                                                                                                                                                                                           |
|         48 | V<sub>DD</sub> | V<sub>DD</sub>   | In            | V<sub>DD</sub>                                                                                                                                                                                                                                                                                                            |
|         49 | PIO1_14        | PIO1_14          | In            | S10 - RB (Right bumper)                                                                                                                                                                                                                                                                                                   |
|         50 | PIO1_3         | PIO1_3           | In            | S16 - Right inner grip button                                                                                                                                                                                                                                                                                             |
|         51 | PIO1_22        | PIO1_22          | In            | S4 - B Button                                                                                                                                                                                                                                                                                                             |
|         52 | SWDIO/PIO0_15  | SWDIO?           |               | Connected to DEBUG interface for LPC11U37F                                                                                                                                                                                                                                                                                |
|         53 | PIO0_16        |                  |               |                                                                                                                                                                                                                                                                                                                           |
|         54 | V<sub>SS</sub> | V<sub>SS</sub>   | In            | V<sub>SS</sub>                                                                                                                                                                                                                                                                                                            |
|         55 | PIO1_9         | PIO1_9           | In            | S7 - X Button                                                                                                                                                                                                                                                                                                             |
|         56 | PIO0_23        | PIO0_23          | In            | Input with pull-down resistor enabled. Connected to Data Ready on Right Trackpad/Haptic.                                                                                                                                                                                                                                  |
|         57 | PIO1_15        | PIO1_15          | Out           | Chip Select/SS for Right Trackpad/Haptic (active low)                                                                                                                                                                                                                                                                     |
|         58 | V<sub>DD</sub> | V<sub>DD</sub>   | In            | V<sub>DD</sub>                                                                                                                                                                                                                                                                                                            |
|         59 | PIO1_12        | PIO1_12          | Out           | Right Haptic Activate. Toggle to generate vibrations (TODO: need better details on this). Initially input. Read during init to check if it is logic low or not. (trace leads to VDD on Trackpad/Haptics). If low PIO0_18 is checked. Later set to output and driven low (before PIO0_18 is set to output and driven low). |
|         60 | PIO0_17        | PIO0_17          | In            | S1 - A Button                                                                                                                                                                                                                                                                                                             |
|         61 | PIO0_18        | PIO0_18          | Out           | Left Haptic Activate. Toggle to generate vibrations (TODO: need better details on this). Initially input (If PIO1_12 is low this is read during init to check if it is logic low or not. (trace leads to R43 on front of PCB))? Later output related to haptics?                                                          |
|         62 | PIO0_19        | PIO0_19          | Out           | Active high enable for powering Joystick to produce X and Y position ADC values.                                                                                                                                                                                                                                          |
|         63 | PIO1_16        | PIO1_16          | In            | Input with pull-down resistor enabled. Connected to Data Ready on Left Trackpad/Haptic.                                                                                                                                                                                                                                   |
|         64 | PIO1_6         | PIO1_6           | Out           | Chip Select/SS for Left Trackpad/Haptic (active low)                                                                                                                                                                                                                                                                      |

## Peripherals

This section details what peripherals are used for on this processor.

* I2C Bus
  * Interface to MPU-6650?
  * TODO: Not confirmed yet.
* WWDT
  * TODO: unknown.
* USART/SMART CARD
  * Interface to nRF51822 (Radio Chip)?
  * TODO: Not confirmed yet.
* 16-bit counter/timer 0 (CT16B0)
  * Timer for implementing a sleep function.
* 16-bit counter/timer 1 (CT16B1)
  * PWM for controlling Steam Button LED brightness.
* 32-bit counter/timer 0 (CT32B0)
  * Related to haptics (and jingle)
  * MR1 related to right haptic (PIO1_12)
  * MR2 related to left haptic (PIO0_18)
* 32-bit counter/timer 1 (CT32B1)
  * Unused?
* ADC
  * AD0
    * Left Analog Trigger Position
  * AD1
    * Analog Joystick X Position
  * AD2
    * Right Analog Trigger Position
  * AD3
    * Analog Joystick Y Position
  * AD4
    * Unused?
  * AD5
    * Unused?
  * AD6
    * Battery charge level?
    * TODO: Not confirmed yet.
  * AD7
    * Unused?
* flash/EEPROM controller
  * TODO: List settings stored in flash.
* SSP0
  * Interface to Cirque Pinnacle Touch Controllers (Left and Right Trackpad (TODO: and haptics?))
* SSP1
  * Unused?
* GPIOs
  * See Pinout section
  * TODO: List pins that are actually used as GPIOs??
* Pin Interrupts
  * PIN_INT0
    * Triggers on TODO of USB_VBUS (PIO0_3)..
    * Related to USB cable disconnect?
    * TODO: Not confirmed yet.
  * PIN_INT1
    * Triggers on TODO of PIO0_2.
    * Related to Brown Out Detect (BOD)?
    * TODO: Not confirmed yet.
  * PIN_INT2
    * Triggers on TODO of PIO1_5.
    * Related to USART/Radio Chip?
    * TODO: Not confirmed yet.
  * PIN_INT3
    * Triggers on rising edge of PIO0_23.
    * Related to Right Trackpad ASIC Data Ready.
  * PIN_INT4
    * Triggers on rising edge of PIO1_16.
    * Related to Left Trackpad ASIC Data Ready.
  * PIN_INT5
    * Unused?
  * PIN_INT6
    * Unused?
  * PIN_INT7
    * Unused?
* USB
  * USB HID (see [usbInterface.md](./usbInterface.md) for details)
    * EP1 = Keyboard
    * EP2 = Mouse
    * EP3 = Controller
  * Firmware Programming
    * See [How to Manually Load Firmware](https://steamcommunity.com/sharedfiles/filedetails/?id=572740074) or AN11305v1 from NXP for details.

# MPU-6500

This is a 6-axis motion tracking device (i.e. accelerometer, gyroscope).

## Resources

[Datasheets & User Manuals](./Datasheets_Documentation/MPU-6500)

## Pinout


| Pin Number | Datasheet Name | Pin Function                                                                                                                                                                                | Notes                                                        |
| -----------: | ---------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
|          1 | NC             | NC                                                                                                                                                                                          | No Connect                                                   |
|          2 | NC             | NC                                                                                                                                                                                          | No Connect                                                   |
|          3 | NC             | NC                                                                                                                                                                                          | No Connect                                                   |
|          4 | NC             | NC                                                                                                                                                                                          | No Connect                                                   |
|          5 | NC             | NC                                                                                                                                                                                          | No Connect                                                   |
|          6 | NC             | NC                                                                                                                                                                                          | No Connect                                                   |
|          7 | AUX_CL         | I2C Master serial clock, for connecting to external sensors                                                                                                                                 |                                                              |
|          8 | VDDIO          | Digital I/O supply voltage                                                                                                                                                                  |                                                              |
|          9 | SDO/AD0        | I2C Slave Address LSB (AD0); SPI serial data output (SDO)                                                                                                                                   | Connected to VDDIO which makes I2C Slave Address is b1101001 |
|         10 | REGOUT         | Regulator filter capacitor connection                                                                                                                                                       | Connected C36 to GND                                         |
|         11 | FSYNC          | Frame synchronization digital input. Connect to GND if unused.                                                                                                                              | Connected to GND                                             |
|         12 | INT            | Interrupt digital output (totem pole or open-drain)<br />Note: The Interrupt line should be connected to a pin on the Application Processor (AP) that can bring the AP out of suspend mode. | Connected to Pin 24 on LPC11U37F                             |
|         13 | VDD            | Power supply voltage and Digital I/O supply voltage                                                                                                                                         | Connected to VDDIO                                           |
|         14 | NC             |                                                                                                                                                                                             |                                                              |
|         15 | NC             |                                                                                                                                                                                             |                                                              |
|         16 | NC             |                                                                                                                                                                                             |                                                              |
|         17 | NC             |                                                                                                                                                                                             |                                                              |
|         18 | GND            |                                                                                                                                                                                             | Connected to GND                                             |
|         19 | RESV           | Reserved. Do not connect.                                                                                                                                                                   | Connected to GND                                             |
|         20 | RESV           | Reserved. Do not connect.                                                                                                                                                                   |                                                              |
|         21 | AUX_DA         | I2C master serial data, for connecting to external sensors                                                                                                                                  |                                                              |
|         22 | nCS            | Chip select (SPI mode only)                                                                                                                                                                 | Connected to VDDIO for I2C operation                         |
|         23 | SCL/SCLK       | I2C SCL                                                                                                                                                                                     | Connected to Pin 20 on LPC11U37F                             |
|         24 | SDA/SDI        | I2C SDA                                                                                                                                                                                     | Connected to Pin 21 on LPC11U37F                             |

# nRF51822

This is the powerful, highly flexible multiprotocol SoC ideally suited for
Bluetooth® low energy and 2.4GHz ultra low-power wireless applications. The
silkscreen labels this as RADIO.

## Resources

[Datasheets & User Manuals](./Datasheets_Documentation/nRF51822)

## Pinout


| Pin Number | Datasheet Name             | Pin Function                                                                                                                                      | Notes                                            |
| :----------- | ---------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------- |
| 1          | VDD                        |                                                                                                                                                   |                                                  |
| 2          | DCC                        | DC/DC output voltage to external LC filter                                                                                                        |                                                  |
| 3          | P0.30                      | Digital I/O                                                                                                                                       |                                                  |
| 4          | P0.00<br />AREF0           | Digital I/O<br />Analog input(ADC/LPCOMP reference input 0)                                                                                       |                                                  |
| 5          | P0.01<br />AIN2            | Digital I/O<br />Analog input(ADC/LPCOMP input 2.)                                                                                                |                                                  |
| 6          | P0.02<br />AIN3            | Digital I/O<br />Analog input(ADC/LPCOMP input 3.)                                                                                                |                                                  |
| 7          | P0.03<br />AIN4            | Digital I/O<br />Analog input(ADC/LPCOMP input 4.)                                                                                                |                                                  |
| 8          | P0.04<br />AIN5            | Digital I/O<br />Analog input(ADC/LPCOMP input 5.)                                                                                                |                                                  |
| 9          | P0.05<br />AIN6            | Digital I/O<br />Analog input(ADC/LPCOMP input 6.)                                                                                                |                                                  |
| 10         | P0.06<br />AIN7<br />AREF1 | Digital I/O<br />Analog input(ADC/LPCOMP input 7.)<br />Analog input (ADC/LPCOMP reference input 1.)                                              |                                                  |
| 11         | P0.07                      | Digital I/O                                                                                                                                       |                                                  |
| 12         | VDD                        |                                                                                                                                                   |                                                  |
| 13         | VSS                        |                                                                                                                                                   |                                                  |
| 14         | P0.08                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 15         | P0.09                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 16         | P0.10                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 17         | P0.11                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 18         | P0.12                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 19         | P0.13                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 20         | P0.14                      | General purpose I/O pin                                                                                                                           | Connected to Pin 20 (USART TXD) on LPC11U37F/501 |
| 21         | P0.15                      | General purpose I/O pin                                                                                                                           | Connected to Pin 23 (USART RXD) on LPC11U37F/501 |
| 22         | P0.16                      | General purpose I/O pin                                                                                                                           |                                                  |
| 23         | SWDIO/nRESET               | (Digital I/O) System reset (active low). Hardware debug and flash programming I/O                                                                 | Connected to Pin 27 on LPC11U37F/501             |
| 24         | SWDCLK                     | (Digital input) Hardware debug and flash programming I/O.                                                                                         | Connected to Pin 39 on LPC11U37F/501             |
| 25         | P0.17                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 26         | P0.18                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 26         | P0.19                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 28         | P0.20                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 29         | DEC2                       | Power supply decoupling                                                                                                                           |                                                  |
| 30         | VDD_PA                     | Power supply output (+1.6 V) for on-chip RF power amp.                                                                                            |                                                  |
| 31         | ANT1                       | Differential antenna connection (TX and RX).                                                                                                      |                                                  |
| 32         | ANT2                       | Differential antenna connection (TX and RX).                                                                                                      |                                                  |
| 33         | VSS                        |                                                                                                                                                   |                                                  |
| 34         | VSS                        |                                                                                                                                                   |                                                  |
| 35         | AVDD                       | Analog power supply (Radio).                                                                                                                      |                                                  |
| 36         | AVDD                       | Analog power supply (Radio).                                                                                                                      |                                                  |
| 37         | XC1                        | (Analog input) Connection for 16/32 MHz crystal or external 16 MHz clock reference.                                                               |                                                  |
| 38         | XC2                        | (Analog output) Connection for 16/32 MHz crystal.                                                                                                 |                                                  |
| 39         | DEC1                       | Power supply decoupling                                                                                                                           |                                                  |
| 40         | P0.21                      | General purpose I/O pin                                                                                                                           |                                                  |
| 41         | P0.22                      | General purpose I/O pin                                                                                                                           |                                                  |
| 42         | P0.23                      | General purpose I/O pin                                                                                                                           |                                                  |
| 43         | P0.24                      | General purpose I/O pin                                                                                                                           |                                                  |
| 44         | P0.25                      | General purpose I/O pin                                                                                                                           |                                                  |
| 45         | P0.26<br />AIN0<br />XL2   | Digital I/O<br />(Analog input) ADC/LPCOMP input 0.<br />(Analog output) Connection for 32.768 kHz crystal                                        |                                                  |
| 46         | P0.27<br />AIN1<br />XL1   | Digital I/O<br />(Analog input) ADC/LPCOMP input 1.<br />(Analog input) Connection for 32.768 kHz crystal or external 32.768 kHz clock reference. |                                                  |
| 47         | P0.28                      | General purpose I/O pin.                                                                                                                          |                                                  |
| 48         | P0.29                      | General purpose I/O pin.                                                                                                                          |                                                  |

# Cirque 1CA027

This is the processor on the haptics board, which seems to be a custom design
similar to the [GlidePoint TM040040](http://www.cirque.com/glidepoint-circle-trackpads).

## Resources

[Datasheets & User Manuals](./Datasheets_Documentation/Cirque-1CA027)

[Ribbon Cable Pinout](./Datasheets_Documentation/Cirque-1CA027/Ribbon-Cable-Pinout-to-Cirque-Board.md)

## Pinout


| Pin Number | Datasheet Name | Pin Function                                                                                                                                                                                                      | Notes                                            |
| -----------: | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------- |
|          1 | REXT           | External bias resistor pin (Input). A resistor is tied between this pin and ground. It is used to adjust the sensitivity of the measurement system.                                                               |                                                  |
|          2 | SNSP1          | Sense Positive input pin(s) for sensor. A trace must be routed to the sensor and throughout the sensor grids. It is typically connected to AVSS through a 47 pF capacitor.<br />Note Must be shielded from noise. |                                                  |
|          3 | SNSN           | Sense Negative input pin. This is an input to the analog measurement system. It is typically connected to AVSS through a 47 pF capacitor.<br />Note Must be shielded from noise.                                  |                                                  |
|          4 | AVSS           | Analog Ground                                                                                                                                                                                                     |                                                  |
|          5 | YE0            | Y Electrode pins (outputs). Used to charge the sensor and determine finger position in the Y direction by switching patterns.                                                                                     |                                                  |
|          6 | YE1            | Same as above.                                                                                                                                                                                                    |                                                  |
|          7 | YE2            | Same as above.                                                                                                                                                                                                    |                                                  |
|          8 | YE3            | Same as above.                                                                                                                                                                                                    |                                                  |
|          9 | YE4            | Same as above.                                                                                                                                                                                                    |                                                  |
|         10 | YE5            | Same as above.                                                                                                                                                                                                    |                                                  |
|         11 | YE6            | Same as above.                                                                                                                                                                                                    |                                                  |
|         12 | YE7            | Same as above.                                                                                                                                                                                                    | Connected to Pin 13 via 470K indicating SPI Mode |
|         13 | YE8            | Same as above.                                                                                                                                                                                                    | Connected to Pin 12 via 470K indicating SPI Mode |
|         14 | YE9            | Same as above.                                                                                                                                                                                                    |                                                  |
|         15 | YE10           | Same as above.                                                                                                                                                                                                    |                                                  |
|         16 | YE11           | Same as above.                                                                                                                                                                                                    |                                                  |
|         17 | XE0            | X Electrode pins (outputs). Used to charge the sensor and determine finger position in the X direction by switching patterns.                                                                                     |                                                  |
|         18 | XE1            | Same as above.                                                                                                                                                                                                    |                                                  |
|         19 | XE2            | Same as above.                                                                                                                                                                                                    |                                                  |
|         20 | XE3            | Same as above.                                                                                                                                                                                                    |                                                  |
|         21 | XE4            | Same as above.                                                                                                                                                                                                    |                                                  |
|         22 | XE5            | Same as above.                                                                                                                                                                                                    |                                                  |
|         23 | XE6            | Same as above.                                                                                                                                                                                                    |                                                  |
|         24 | XE7            | Same as above.                                                                                                                                                                                                    |                                                  |
|         25 | XE8            | Same as above.                                                                                                                                                                                                    |                                                  |
|         26 | XE9            | Same as above.                                                                                                                                                                                                    |                                                  |
|         26 | XE10           | Same as above.                                                                                                                                                                                                    |                                                  |
|         28 | XE11           | Same as above.                                                                                                                                                                                                    |                                                  |
|         29 | XE12           | Same as above.                                                                                                                                                                                                    |                                                  |
|         30 | XE13           | Same as above.                                                                                                                                                                                                    |                                                  |
|         31 | XE14           | Same as above.                                                                                                                                                                                                    |                                                  |
|         32 | XE15           | Same as above.                                                                                                                                                                                                    |                                                  |
|         33 | PA0            | I/O pins used for Communications (PS/2, SPI, I2C), button inputs and other I/0 needs.                                                                                                                             |                                                  |
|         34 | PA1            | Same as above.                                                                                                                                                                                                    |                                                  |
|         35 | PA2            | Same as above.                                                                                                                                                                                                    |                                                  |
|         36 | PA3            | Same as above.                                                                                                                                                                                                    |                                                  |
|         37 | PA4            | Same as above.                                                                                                                                                                                                    |                                                  |
|         38 | PA5            | Same as above.                                                                                                                                                                                                    |                                                  |
|         39 | PA6            | Same as above.                                                                                                                                                                                                    |                                                  |
|         40 | PA7            | Same as above.                                                                                                                                                                                                    |                                                  |
|         41 | PB2            | Same as above.                                                                                                                                                                                                    |                                                  |
|         42 | PB1            | Same as above.                                                                                                                                                                                                    |                                                  |
|         43 | PB0            | Same as above.                                                                                                                                                                                                    |                                                  |
|         44 | DVSS           | Digital Ground                                                                                                                                                                                                    |                                                  |
|         45 | OSCA           | Oscillator pin (input). Activates internal oscillator when connected to an external resistor to ground.                                                                                                           |                                                  |
|         46 | DVDD           | Digital Power pin. Supplies digital logic, processor and memory.                                                                                                                                                  |                                                  |
|         47 | VREG_VDD       | Supply voltage for 5 volt operation. Regulates the internal VDD voltage.                                                                                                                                          |                                                  |
|         48 | AVDD           | Analog Power pin for analog measurement system and electrodes.                                                                                                                                                    |                                                  |
