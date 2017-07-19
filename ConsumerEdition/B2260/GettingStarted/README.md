---
title: Getting Started with B2260
permalink: /documentation/ConsumerEdition/B2260/GettingStarted/
redirect_from:
- /documentation/ConsumerEdition/B2260/GettingStarted/README.md/
---
# Getting Started
Learn about your B2260 board as well as how to prepare and set up for basic use.

## Setup - Hardware

**Required**
- [B2260](http://www.96boards.org/product/b2260/)
   - Board based on the Cannes2-STiH410 SoC
- Power Supply
   - 12V supply required, recommended minimum 2A
   - For more info see: https://www.96boards.org/products/accessories/power/
- USB Keyboard and Mouse
   - 96board CE specification requires two USB-A connectors, thus all 96Boards can be simultaneously equipped with a keyboard and mouse without the need for an external USB hub
- Monitor and HDMI Cable
   -  96Boards are equiped with a full sized HDMI connector
   -  HDMI capable monitors or TVs with resolutions up to 1080p60 are supported
- MicroSD Card
   - Used for storage and quick and easy switching between operating systems
   - For standard Linaro images, SD cards are required to have be at least 4GB

**Optional**
- Ethernet cable
   - For connecting to networks without using WiFi
- 96Boards UART Adapter Board
   - For connecting to PC via serial link (particuarlly useful for debugging the boot process)
   - For more info see: https://www.96boards.org/products/mezzanine/uarts/

***

# Out of the Box
The following subsections describe how to get started with the B2260 using the release build shipped with the board.

The B2260 is supplied with Micro SD card containig a preinstalled version of Debian, thus should be ready to use out-of-the-box.

<img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/B2260/AdditionalDocs/Images/Images_Board/ST_B2260_Front_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/B2260/AdditionalDocs/Images/Images_Board/ST_B2260_Front_SD.png?raw=true" width="240" height="276" />
<img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/B2260/AdditionalDocs/Images/Images_Board/ST_B2260_Angle_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/B2260/AdditionalDocs/Images/Images_Board/ST_B2260_Angle_SD.png?raw=true" width="276" height="240" />
<img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/B2260/AdditionalDocs/Images/Images_Board/ST_B2260_Back_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/B2260/AdditionalDocs/Images/Images_Board/ST_B2260_Back_SD.png?raw=true" width="240" height="276" />

***

## Features

|   Component          |   Description|
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Cannes2-STiH410 EJG |
|  CPU                 | Dual ARMcortex-A9 @ 1.5 GHz |
|  GPU                 | ARM Mali 400 GPU @ 355 MHz |
|  RAM                 | 2 x (DDR3 16-bit 500MB) |
|  PMU                 | None |
|  Storage             | Built-in MicroSD card reader |
|  Ethernet Port       | Up to 1 Gb/s |
|  Wireless            | Wi-Fi 802.11 g/n, Bluetooth 4.0 LE |
|  USB                 | 2 x USB2.0 Host (TypeA), 1x USB3.0 DRD Salve (Type micro AB), 1 x USB 2.0 host (on high-speed expansion connector) |
|  Display             | 1 x HDMI 1.4 up to 1080p60 (TypeA) |
|  Video               | Software video codecs |
|  Audio               | HDMI and PCM/I2S (via Low-speed expansion connector) |
|  Camera              | None |
|  Expansion Interface | 40 pin Low-speed expansion connector (12 x GPIO, 1 UART 4 wires, 1 UART 2 wires, 2 x I2C, 1 PCM/I2S, 1 SPI, 1 fan ctrl, reset  button);  60 pin High-speed expansion connector (1x USB, 2 x I2C, 1x SPI, 1x SD interface) |
|  LED                 | 1 x WiFi activity LED (yellow, 1 x BT activity LED (blue), 4 x User LEDs (green) |
|  Button              | Reset |
|  Power Source        | 12V, 2A (min), Plug specification is inner diameter 1.7mm and outer diameter 4.8mm |
|  OS Support          | Linux based on Debian, Linux based on OpenEmbedded |
|  Size                | 85mm x 100mm |

**IMPORTANT NOTES**

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with most but not all monitors/TVs.

***

## Starting the board for the first time
MicroSD card comes preloaded with Debian Linux and can be up and running with a few simple steps:

- Connect the B2260 to your display with the HDMI cable
  - It is important to do this first because the monitor will not detect the board if it is connected after starting
  - Ensure that the source for the display is switched to the HDMI port you are using
- Connect the USB keyboard and mouse to the USB Type-A connectors
- Insert the populated Micro SD card

> Note: The above setup will cause B2260 Board to Auto Power up when it is plugged into power

- Connect the power supply to the B2260
  - The board will begin to boot Debian Linux after a few seconds

***

## Updating to a new release or changing your Operating System

If you are already familiar with the B2260 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../Downloads/): This page lists all Linaro and 3rd party operating systems available for B2260
- [Installation page](../Installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your B2260 board
- [Board Recovery](../Installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a successfull board recovery.
- [Troubleshooting](../Support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [B2260 documentation home page](../)
