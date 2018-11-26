---
title: Bosch Sensors Mezzanine for 96Boards
permalink: /documentation/mezzanine/shiratech-bosch-sensors/
---
# Shiratech LTE Mezzanine

- 1) [Introduction](#introduction)
	- 1.1) [About the Shiratech LTE Mezzanine](#11-about-the-shiratech-lte-and-sensors-mezzanine)
	- 1.2) [Features & Specifications](#12-features-and-specifications)
- 2) [Guides](#2-guides)
- 3) [Files](#3-files)

## 1) Introduction
### 1.1) About the Shiratech LTE and Sensor Mezzanine

The Shiratech Bosch Sensor Mezzanine lets you add high-performance, high-accuracy Bosch sensors to your IoT product
The new Shiratech Bosch Sensor Mezzanine adds full sensing capabilities to the 96boards platform, including pressure and environmental sensors, accelerometer, magnometer and a hub sensor for design and evaluation purposes.
comAll sensors are activated from the 1.8v voltage and controlled by spi-0, i2c-0 and 6 gpio lines (gpio a,b,c,d,e,f).

The following Bosch sensors are assembled on the mezzanine:
- BHI160 Sensor HUB with integrated IMU
- BMM150 Geomagnetic sensor
- BMP388 Digital pressure sensor
- BME680 Gas, pressure, temperature and humidity sensor
- BMA456 Tri-Axial acceleration sensor


### 1.2) Features & Specifications

- **BHI160:**
The BHI160 is a small, low power smart hub with an integrated three axis gyroscope plusan integrated three axis accelerometer plus a programmable microcontroller.

It is connected directly to I2C0 bus and uses I2C address 0x29.

The device interrupt signal is connected to the carrier board GPIO_A pin.

Serving as sensor hub the device uses signal pins ASDA and ASCK to drive I2C master functionality and GPIO1, 2 and 7.

- **BMM150:**
The BMM150 is a standalone geomagnetic sensor for consumer market applications. It allows measurements of the magnetic field in three perpendicular axes.

It is connected to the BHI160 I2C local sensor bus and uses I2C address 0x10.

- **BMP388:**
The BMP388 is a digital sensor with pressure and temperature measurement based on proven sensing principles.

It is connected to the board SPI0 bus and uses SPI0_CS_N signal for CS.

- **BME680:**
The BME680 is a digital 4-in-1 sensor with gas, humidity, pressure and temperature measurement based on proven sensing principles.

It is connected to the board SPI0 bus and uses GPIO_C signal for CS.

- **BMA456:**
The BMA456 is 16bit, digital, triaxial acceleration sensor with intelligent on-chip motion triggered interrupt features optimized for wearable applications.

It is connected to the board SPI0 bus and uses GPIO_D signal for CS.

GPIO_E and GPIO_F are used for interrupt signals.

## 2) [Guides](guides/)

## 3) Files

- [Schematics](files/shiratech-bosch-sensors-schematics.pdf)
- [Quick Start](files/shiratech-bosch-sensors-quick-start.pdf)
- [User Manual](files/shiratech-bosch-sensors-user-manual.pdf)
