---
title: Documentation for STM32 Sensor mezzanine board
permalink: /documentation/mezzanine/stm32/
redirect_from: /documentation/mezzanine/stm32/README.md/
---
## STM32 Sensor mezzanine board

# Table of Contents
- [1) Introduction](#1-introduction)
  - [1.1) About the 96Boards STM32 Sensor Mezzanine](#11-about-the-96boards-stm32-sensor-mezzanine)
  - [1.2) Specifications & Features](#12-specifications-and-features)
- [2) Guides and Documentation](#2-guides-and-documentation)

# 1) Introduction
## 1.1) About the 96Boards STM32 Sensor Mezzanine

The [96Boards STM32 Sensor Mezzanine](https://www.96boards.org/product/stm32/) board with STM32F446 MCU (B-F446E-96B01A) enables users to prototype systems that are aware of their environment, thanks to the embedded sensors for movement, pressure and sound. It can directly be plugged on top of the 96Boards CE cards and supports multiple expansion possibilities through the Arduino™ Uno Revision 3 or the Grove™connectivity. The integrated ST-LINK/V2-1 debugger facilitates software development, drag-and-drop programming and provides a direct access to the ARM®mbed™on-line resources.


<img src="https://www.96boards.org/product/mezzanine/stm32/images/STM32_Front.png?raw=true" data-canonical-src="https://www.96boards.org/product/mezzanine/stm32/images/STM32_Front.png?raw=true" width="330" height="215" />

## 1.2) Specifications and Features
- Based on STM32F446 MCU, ARM® Cortex® -M4 180 MHz in LQFP100 package
- Compliant with the 96Boards CE standard
- Two types of extension resources:
  - 96Boards high/low-speed connectivity
  - Arduino™ Uno revision 3 and Grove connectivity
- [ARM® mbed™](http://mbed.org) -enabled, planned for the first quarter of the 2016
- Integrated MEMS sensors:
  - LSM6DS3H: 3D accelerometer / 3D gyroscope
  - LIS3MDL 3-axis magnetometer
  - LPS22HB barometer
  - MP34DT01-M microphone
- On-board ST-LINK/V2-1 debugger/programmer
- USB re-enumeration capability:
  - Virtual com port
  - Mass storage
  - Debug port
- Supported by wide choice of integrated development environments (IDEs) including
  - IAR™
  - Keil®
  - GCC-based IDEs
  - ARM® mbed™ online

# 2) Guides and Documentation
  - [Useful Guides](guides/)
  - [Hardware User Docs](http://www.st.com/content/ccc/resource/technical/document/user_manual/cd/cf/d7/96/33/03/4f/e7/DM00233579.pdf/files/DM00233579.pdf/jcr:content/translations/en.DM00233579.pdf)
  - [Schematics Pack](http://www.st.com/resource/en/schematic_pack/b-f446e-96b01a_sch.zip)
