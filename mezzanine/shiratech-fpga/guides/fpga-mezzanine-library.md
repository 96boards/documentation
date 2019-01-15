---
title: Interfacing with Arduino IO
permalink: /documentation/mezzanine/shiratech-fpga/guides/fpga-mezzanine-library.md.html
---
# Introduction

This guide will walk you through Interfacing with Arduino IO on the FPGA Mezzanine using a dedicated C Library.

## Hardware Setup

- **[Any 96Boards CE Board](https://www.96boards.org/products/ce/)**
- **Shiratech FPGA Mezzanine**

## Software setup

- **[Install MRAA on 96Boards CE](https://youtu.be/c8b6pcc6H2c)**
- **Clone the fpga_mezz_lib repository**
    - `git clone https://github.com/96boards-projects/fpga_mezz_lib`

## Using the Library

> Note: The library currently only supports the Arduino header

1. **Pin Map:** This library uses the following pin map for the Arduino header

| Arduino Pins | Function      | GPIO Pin Number |
|:------------:|:-------------:|:---------------:|
| A0-A3        | NA            | NC              |
| A5           | I2C1 SDA/GPIO | 17              |
| A6           | I2C1 SCL/GPIO | 16              |
| D0           | UART0 RX/GPIO | 0               |
| D1           | UART0 TX/GPIO | 1               |
| D2           | GPIO          | 2               |
| D3           | GPIO          | 3               |
| D4           | GPIO          | 4               |
| D5           | GPIO          | 5               |
| D6           | GPIO          | 6               |
| D7           | GPIO          | 7               |
| D8           | GPIO          | 8               |
| D9           | GPIO          | 9               |
| D10          | SPI_CS/GPIO   | 10              |
| D11          | SPI_MOSI/GPIO | 11              |
| D12          | SPI_MISO/GPIO | 12              |
| D13          | SPI_CLK/GPIO  | 13              |
| SDA          | I2C0 SDA/GPIO | 14              |
| SCL          | I2C0 SCL/GPIO | 15              |

2. **Macros:** Following macros will come handy

- Macros for Multifunction IO Pins on the Arduino Header to be used with pinMode()
    - `ARD_I2C_0_FUNC`: Refers to GPIO15 and GPIO14 responsible for I2C0 Bus
    - `ARD_SPI_FUNC`: Refers to GPIO10 to GPIO13 responsible for SPI Bus
    - `ARD_UART_FUNC`: Refers to GPIO0 and GPIO1 responsible for UART0 Bus
    - `ARD_I2C_1_FUNC`: Refers to GPIO17 and GPIO16 responsible for I2C1 Bus
- I2C Bus used by the FPGA Mezzanine
    - `I2C_BUS`: Just in case a 96Boards has a different internal Bus on I2C0 pins.
- Macros for Input or Output Mode used in pinMode()
    - `INPUT`: Value 1
    - `OUTPUT`: Value 0
- Macros for High or LOW GPIO state used in digitalWrite() and digitalRead()
    - `HIGH`: Value 1
    - `LOW`: Value 0
- Macros for Multifunction IO Pin state used in pinFunction()
    - `FUNC_PASSTHROUGH`: Sets I2c, SPI or UART in Passthrough mode.
    - `FUNC_GPIO`: Sets I2c, SPI or UART pins in GPIO mode.

3. **Functions:**

- **check_version(mraa_i2c_context i2c)**
    - This function returns the current firmware revision of the FPGA Mezzanine which is stored in the REV_REG 0x00.
    - Input:
        - `i2c`: MRAA I2C context of the FPGA Mezzanine on bus 0 and address 0x6f
    - Returns revision as `int` value.
    - Returns `-1` if I2C communication fails.
- **test(mraa_i2c_context i2c)**
    - This function sets a specific value to the TEST_REG 0x01 and reads back the value to test I2C communication.
    - Input:
        - `i2c`: MRAA I2C context of the FPGA Mezzanine on bus 0 and address 0x6f
    - Returns `1` if test passed.
    - Returns `-1` if an error occurs.
- **pinFunction(u_int8_t func_type, u_int8_t func, mraa_i2c_context i2c)**
    - This function sets Multi-Functional pins to either PassThrough to LowSpeed header or GPIO.
    - Inputs:
        - `func_type`: The MultiFunctional pins you want to toggle. These may be:
            - `ARD_I2C_0_FUNC`: for GPIO 14 and 15 that are connected to the I2C0 bus.
            - `ARD_I2C_1_FUNC`: for GPIO 16 and 17 that are connected to the I2C1 bus.
            - `ARD_SPI_FUNC`: for GPIO 10, 11, 12 and 13 that are connected to the SPI bus.
            - `ARD_UART_FUNC`: for GPIO 0, 1 that are connected to the UART0 bus.
        - `func`: Set as Passthrough or GPIO.
            - `FUNC_PASSTHROUGH`: The pins are directly connected to their respective Bus on the 96Boards Low Speed Header.
            - `FUNC_GPIO`: The pins are detached from the Low Speed Header and can be used as regular GPIO pins using the digitalWrite and digitalRead functions.
        - `i2c`: MRAA I2C context of the FPGA Mezzanine on bus 0 and address 0x6f
    - Returns `-1` if an error occurs.
- **pinMode(u_int8_t pin, u_int8_t mode, mraa_i2c_context i2c)**
    - This function sets the GPIO pins as either Input or Output pins. Multi-Functions pins will need to be set to GPIO mode before being used with this function.
    - Inputs:
        - `pin`: Pin value, refer to the pin map on section one of 'Using The Library'
        - `mode`: Input or Output mode.
            - `INPUT`: Sets pins as input pins.
            - `OUTPUT`: Sets pins as output pins.
        - `i2c`: MRAA I2C context of the FPGA Mezzanine on bus 0 and address 0x6f
    - Returns `-1` if an error occurs.
- **digitalWrite(u_int8_t pin, u_int8_t state, mraa_i2c_context i2c)**
    - This function writes a pin to either high or low if it's configured as an OUTPUT.
    - Inputs:
        - `pin`: Pin value, refer to the pin map on section one of 'Using The Library'
        - `state`: Input or Output mode.
            - `HIGH`: Sets pins as high.
            - `LOW`: Sets pins as low.
        - `i2c`: MRAA I2C context of the FPGA Mezzanine on bus 0 and address 0x6f
    - Returns `-1` if an error occurs.
- **digitalRead(u_int8_t pin, mraa_i2c_context i2c)**
    - This function reads the value of a pin.
    - Inputs:
        - `pin`: Pin value, refer to the pin map on section one of 'Using The Library'
        - `i2c`: MRAA I2C context of the FPGA Mezzanine on bus 0 and address 0x6f
    - Returns `-1` if an error occurs.
    - Returns `1` if the pin is HIGH.
    - Returns `0` id the pin is LOW.

## Example

An example implementation is present in the repository, it can be built by running `make`.
