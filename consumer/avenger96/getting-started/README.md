---
title: Getting Started with the Avenger96
permalink: /documentation/consumer/avenger96/getting-started/
---
# Getting Started

Learn about your Avenger96 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Required**
- Avenger96 development board
- Power adapter
   - 96Boards specification requires a 12V with 2500mA power adapter

**Optional**
- HDMI Display
- microSD Card
- USB Keyboard and Mouse

***

# Out of the Box

In the Box you can find the Avenger96 as well as a microSD card which comes with a pre-installed linux.

<img src="../additional-docs/images/images-board/sd/avenger96-front-sd.png" data-canonical-src="../additional-docs/images/images-board/sd/avenger96-front-sd.png" width="250" height="250" />
<img src="../additional-docs/images/images-board/sd/avenger96-back-sd.png" data-canonical-src="../additional-docs/images/images-board/sd/avenger96-back-sd.png" width="250" height="250" />


## Features

|   Component          |   Description |
|:---------------------|:--------------|
|  SoC                 | STM32MP157AAC              |
|  CPU                 | 2x ARM®Cortex-A7 up to 650 MHz <br> 1x ARM®Cortex-M4 up to 200 MHz                                                     |
|  GPU                 | 1x 3D GPU Vivante® @ 533 MHz -OpenGL® ES 2.0                                                                           |
|  PMIC                | STPMIC1A                                                                                                               |
|  RAM                 | 1024 Mbyte @ 533MHz                                                                                                    |
|  Storage             | eMMC v4.51: 8 Gbyte <br> QSPI: 2Mbyte <br> EEPROM: 128 byte <br> microSD Socket: UHS-1 v3.01                           |
|  Ethernet Port       | 10/100/1000 Mbit/s, IEEE 802.3 Compliant                                                                               |
|  Wireless            | WiFi: 5 GHz & 2.4GHz IEEE 802.11a/b/g/n/ac <br> _Bluetooth_® wireless technology v4.2 (BR/EDR/BLE) <br> PCB Antenna                           |
|  USB                 | Host: 2x type A, 2.0 high-speed <br> OTG: 1x type micro-AB, 2.0 high-speed                                             |
|  Display             | HDMI: WXGA (1366x768)@ 60 fps, HDMI 1.4                                                                                |
|  Audio               | Over HDMI                                                                                                              |
|  Expansion Interface | 96Boards Compliant: <br> 40-Pin Low Speed Header <br> 60-Pin High Speed Header                                         |
|  LED                 | 4x green user controlled LEDs <br> 1x blue Bluetooth enabled <br> 1x yellow WiFi enabled <br> 1x red power supply okay |
|  Button              | Power and Reset                                                                                                        |
|  Power Source        | DC Power Jack: 1.65mm Center Positive <br> 8v - 18v upto 24W                                                           |
|  OS Support          | U-Boot version: U-Boot 2018.09-stm32mp-r2 <br> Linux version: Linux stm32mp1-av96 4.14.48 <br> Linux Distribution: ST OpenSTLinux Weston (A Yocto Project Based Distro) |
|  Size                | 100 x 85 mm                                                                                                            |


***

## Starting the board for the first time

This short guide leads you through the first steps to start exploring your Avenger96.

**Easy Setup Guide**
- Make sure the boot switch is set to boot from the “SD-Card(Standard)”

| Switch 1 | Switch 2 | Switch 3 |
|:--------:|:--------:|:--------:|
| 1        | 0        | 1        |

- Insert the included microSDcard with pre-installed linux
- Connect an display via the HDMI-connector
- Connect keyboard and mouse to the host USB ports
- Connect a proper power supply(See chapter1.2.3)
- Plug the power supply into the power socket
- When Linux starts up the standard Weston desktop will appear on the display. A terminal window can be opened by clicking on the terminal icon in the top left corner


***

## Whats Next?

If you are already familiar with the Avenger96 and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/): This page lists all Linaro and 3rd party operating systems available for the Avenger96
- [Installation page](../installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your Avenger96
- [Board Recovery](../installation/board-recovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Support](../support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Avenger96 documentation home page](../)

***
