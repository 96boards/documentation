---
title: Basic Kit  for RS-G2L100
permalink: /documentation/consumer/rs-g2l100/getting-started/
---

# Getting Started

Learn about your RS-G2L100 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [RS-G2L100]
   - Board based on the Renesas RZ-G2L Processor
- Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended
- SW1
   - SW1 on the RS-G2L100 comes with three pin-jumpers

**Optional**
- MicroSD card with adapter
   - For quick and easy switching between operating systems and extra storage
- Mezzanine Products
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components
- USB to MicroUSB cable
   - This is needed for serial console interface
- USB to ethernet adapter and ethernet cable
   - For connecting to a network without using WiFi

***

# Out of the Box

The following subsections should describe how to get started with the RS-G2L100 using the release build shipped with the boards. The RS-G2L100 board is ready to use “out of the box” with a preinstalled version of the Linux(Yocto) distribution.

<img src="../additional-docs/images/images-board/sd/rs-g2l100-front-sd.png" data-canonical-src="../additional-docs/images/images-board/sd/rs-g2l100-front-sd.png" width="250" height="250" />
<img src="../additional-docs/images/images-board/sd/rs-g2l100-back-sd.png" data-canonical-src="../additional-docs/images/images-board/sd/rs-g2l100-back-sd.png" width="250" height="250" />
<img src="../additional-docs/images/images-board/sd/rs-g2l100-angle-sd.png" data-canonical-src="../additional-docs/images/images-board/sd/rs-g2l100-angle-sd.png" width="250" height="250" />

## Features

< https://github.com/96boards/documentation/blob/master/ConsumerEdition/DragonBoard-410c/GettingStarted/README.md >

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 |   Renesas RZ/G2L                                                                                 |
|  CPU                 |   1× or 2× Cortex®-A55@1.2GHz L1,L3 Parity/ECC,1× Cortex®-M33@200MHz                             |
|  GPU                 |   Arm Mali-G31 GPU @500MHz                                                                       |
|  RAM                 |   16-bit ×1ch DDR4-1600/DDR3L-1333 w/ECC                                                         |
|  PMU                 |                                                                                                  |
|  Storage             | 	8GB eMMC on board storage MicroSD card slot                                                    |
|  Ethernet Port       |   2ch                                                                                            |
|  Wireless            |   WIFI Module 2.4G/5.0G (optional)                                                               |
|  USB                 |   2 x USB2.0, 1 x USB(OTG)                                                                       |
|  Display             |   1 x HDMI                                                                                       |
|  Video               |   Support up to Full HD @30fps resolutions Encoding and Decoding: H.264                          |
|  Audio               |                                                                                                  |
|  Camera              |                                                                                                  |
|  Expansion Interface |                                                                                                  |
|  LED                 |                                                                                                  |
|  Button              |                                                                                                  |
|  Power Source        |                                                                                                  |
|  OS Support          |                                                                                                  |
|  Size                |                                                                                                  |

**IMPORTANT NOTES**

< Insert RS-G2L100 Important notes - Example Below - This section should be monitored by board maintainers. This information should be periodically updated. Please treat this section as a "News" section. Important notes should consist of thing you think end user MUST KNOW to minimize unnecessary support questions surrounding the out of box experience with shipped stock image >

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with **MOST but not all** monitors/TVs.
- There are limitations on the usage of the USB ports on the Board-X board.

***

## Starting the board for the first time

**The RS-G2L100 comes preloaded with Linux(Yocto) and can be up and running with a few simple steps:**

- Connect the RS-G2L100 to your display with the HDMI cable. It is important to do this first because the monitor will not detect the board if it is connected after starting. Ensure that the source for the display is switched to the HDMI port you are using
- Connect the USB keyboard and mouse. Do not connect the USB OTG port to your computer – this will prevent the keyboard and mouse from operating. The USB OTG port is the micro USB connector on the board

- Ensure SW1 Pins are linked as follows:

| 1             | 2        | 3      | Boot Configuration    |
|:--------------|:--------:|:------:|:---------------------:|
| 0             | 0        | 1      | Boot from eMMC        |
| 1             | 0        | 0      | Boot from Single/Quad |
| 1             | 0        | 1      | SCIF download         |

- Boot Mode Selection Switch Below are the Boot mode switch selection settings to boot the board.

> Note: The above setup will cause RS-G2L100 Board to Auto Power up when it is plugged into power

- Connect the power supply to the RS-G2L100. The board will begin to boot Debian Linux immediately
***

## Updating to a new release or change your operating system

If you are already familiar with the Board-X board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/README.md): This page lists all Linaro and 3rd party operating systems available for Board-X
- [Installation page](../installation/README.md): If you already have the images you need, this page has information on how to install the different operating systems onto your Board-X board
- [Board Recovery](../installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../support/README.md)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [RS-G2L100 documentation home page](../README.md)

***   
