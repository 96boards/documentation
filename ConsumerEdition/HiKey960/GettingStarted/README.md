---
title: Getting Started with HiKey960
permalink: /documentation/ConsumerEdition/HiKey960/GettingStarted/
redirect_from: /documentation/ConsumerEdition/HiKey960/GettingStarted/README.md/
---
# Getting Started

Learn about your HiKey960 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [HiKey960](http://www.96boards.org/product/hikey960/)
   - Board based on the Kirin 960 Processor
- [Power adapter](http://www.96boards.org/product/power/)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Type-A (Host Machine) to USB Type-C (HiKey960) cable
   - This is needed for interfacing with fastboot/adb commands
- [USB Keyboard and Mouse](USBKeyBoardMouse.md)
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended
- Jumpers / DIP Switches
   - J2001 Header on the HiKey960 comes with two pin-jumpers, does not apply for DIP Switches

**Optional**
- [Mezzanine Products](../../../MezzanineProducts/)
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components
- USB to MicroUSB cable
   - This is needed for serial console interfacing
- USB to ethernet adapter and ethernet cable
   - For connecting to a network without using WiFi

***

# Out of the Box

The following subsections should describe how to get started with the HiKey960 using the release build shipped with the boards. The HiKey960 board is ready to use “out of the box” with a preinstalled version of AOSP.

<img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey960/AdditionalDocs/Images/Images_Board/Hikey960_front_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey960/AdditionalDocs/Images/Images_Board/Hikey960_front_SD.png?raw=true" width="250" height="160" />
<img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey960/AdditionalDocs/Images/Images_Board/Hikey960_angle_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey960/AdditionalDocs/Images/Images_Board/Hikey960_angle_SD.png?raw=true" width="250" height="160" />
<img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey960/AdditionalDocs/Images/Images_Board/Hikey960_back_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey960/AdditionalDocs/Images/Images_Board/Hikey960_back_SD.png?raw=true" width="250" height="160" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Kirin 960                                                                                        |
|  CPU                 | 4 Cortex A73 + 4 Cortex A53 Big.Little CPU architecture                                          |
|  GPU                 | ARM Mali G71 MP8                                                                                 |
|  RAM                 | 3GB LPDDR4 SDRAM                                                                                 |
|  PMU                 | Hi6421GWCV530 PMU                                                                                |
|  Storage             | 32GB UFS Flash Storage                                                                           |
|  Wireless            | WiFi (2.4- and 5-GHz dual band with two antennas) and Bluetooh 4.1                               |
|  USB                 | 2 x USB 3.0 type A (host mode only) and 1 x USB 2.0 type C OTG                                   |
|  Display             | 1 x HDMI 1.4 (Type A - full), 1 x 4L-MIPI DSI and HDMI output up to FHD 1080P                    |
|  Video               | Inside Encoder: H.265/H.264 3840 x 2400@30fps 4 x 1080p @ 30 fps, Inside Decoder: H.265, HEVC MP/High Tier, Main 10/High Tier, H.264 BP/MP/HP, MPEG1/2/4, VC-1, VP6/8                                                                 |
|  Audio               | HDMI output                                                                                      |
|  Camera              | 1 x 4-lane MIPI CSI and 1 x 2-lane MIPI CSI                                                      |
|  Expansion Interface | 40 pin low speed expansion connector: +1.8V, +5V, DC power, GND, 2UART, 2I2C, SPI, I2S, 12xGPIO and 60 pin high speed expansion connector: 4L-MIPI DSI, I2C x2, SPI (48M), USB 2.0, 2L+4LMIPI CSI                                    |
|  LED                 | 1 x WiFi activity LED（Yellow), 1 x BT activity LED (Blue) and 4 x User LEDs (Green)             |
|  Button              | Power Button ： Button Power on/off & Reset the system                                           |
|  Power Source        | Recommend a 12V@2A adapter with a DC plug which has a 4.75mm outer diameter and 1.7mm center pin with standard center-positive (EIAJ-3 Compliant)                                                                                        |
|  OS Support          | AOSP/LINUX                                                                                       |
|  Size                | 85mm x 55mm                                                                                      |

Please visit the [HiKey960 Hardware User Manual](../HardwareDocs/HardwareUserManual.md) for more information

**IMPORTANT NOTES**

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with **MOST but not all** monitors/TVs.
- As there is only one USB controller on the HiKey960, there are limitations on the usage of the USB ports, such that either the USB-C OTG port **OR** the USB-A/mezzanine ports can be used at one time. If anything is plugged into the USB-C port, the other ports will stop functioning.

***

## Starting the board for the first time

### Modes

Your HiKey960 has 3 modes: **normal, fastboot and recovery**.

Name          | Link / Switch       | Normal Mode   | Fastboot Mode | Recovery Mode |
------------- | ------------------- | ------------- | ------------- | ------------- |
Auto Power up | Link 1-2 / Switch 1 | closed / ON   | closed / ON   | closed / ON   |
Recovery      | Link 3-4 / Switch 2 | open / OFF    | open / OFF    | closed / ON   |
Fastboot      | Link 5-6 / Switch 3 | open / OFF    | closed / ON   | open / OFF    |

- Normal Mode: Select this mode to have HiKey960 boot OS from onboard storage
- [Fastboot Mode](../Installation/): Select this mode to flash a new Operating system using the OTG (USB Type-C) port and fastboot commands
- [Recovery Mode](../Installation/BoardRecovery.md): Select this mode to recover HiKey960 from bricked state. Also use when updating base firmware

### First boot

- HiKey960 is not connected to power
- Ensure HiKey960 is in Normal Mode
- Connect HDMI cable to compatible monitor
- Connect Keyboard and Mouse
- Power on with 96Boards compliant power supply

Board should boot up into AOSP.

***

## Explore your HiKey960

If you are already familiar with the HiKey960 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [HiKey960 96Boards Home page](http://www.96boards.org/product/HiKey960/)
- [Downloads page](../Downloads/): This page lists all Linaro and 3rd party operating systems available for HiKey960
- [Installation page](../Installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your HiKey960 board
- [Board Recovery](../Installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Support](../Support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

***

Return to the [HiKey960 Documentation home page](../)
