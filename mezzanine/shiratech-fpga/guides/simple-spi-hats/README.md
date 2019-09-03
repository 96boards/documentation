---
title: Interfacing with Simple SPI HATS and Sensors
permalink: /documentation/mezzanine/shiratech-fpga/guides/simple-spi-hats/
---
# Introduction

This guide will walk you through Interfacing with Raspberry Pi HATs that use SPI bus.

## Hardware Setup

- **[Any 96Boards CE Board](/products/ce/)**
- **Shiratech FPGA Mezzanine**
- **Simple SPI HAT**
  - For the Purpose of this guide I will be using:
    - [MAX7219 LED Matrix HAT](https://www.crazypi.com/RPI-LED-MATRIX)

## Software setup

- **[Install MRAA on 96Boards CE](https://youtu.be/c8b6pcc6H2c)**
- **[Install UPM on 96Boards CE](https://github.com/intel-iot-devkit/upm/blob/master/docs/building.md)**

## Running the Demos

- The SPI ports on the Raspberry Pi headers act as a pass-through to the I2C0 Pins on the Low Speed Header.
- We first need to enable the spi pass-through: `sudo i2cset 0 0x6f 0x3a 0x00`
- This means and device connected over spi via the FPGA Mezzanine should be available on `/dev/spidev0.0/`.

### MAX7219: C

For the MPU6050, we are going to use one of the example codes from the MRAA repository:

- Fetch the code: `wget https://raw.githubusercontent.com/intel-iot-devkit/mraa/master/examples/c/spi.c`
- Compile the code: `gcc spi.c -o spi -lmraa`
- Run the code: `sudo ./spi`
- You should see all the LEDs in the Matrix light up one by one.
