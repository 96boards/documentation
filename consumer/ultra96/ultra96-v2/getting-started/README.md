---
title: Getting Started with the Ultra96-V2
permalink: /documentation/consumer/ultra96/ultra96-v2/getting-started/
---

# Getting Started

Learn about your Ultra96 board as well as how to prepare and set up for basic use.

**Note** If you are looking for v1 _Getting Started_ instructions please click [here](https://www.96boards.org/documentation/consumer/ultra96/ultra96-v1/getting-started/).

## Setup - What you will need

**Need**

- [Ultra96](https://www.96boards.org/product/ultra96/)
   - Board based on Xilinx Zynq UltraScale+ MPSoC ZU3EG A484, includes microSD card
- [Power adapter](http://avnet.me/96BoardPower)
   - 12V @ 2A AC/DC converter compatible with the 96Boards specification

**Optional**

- [Ultra96 USB-to-JTAG/UART Pod](http://avnet.me/ultra96jtag)
   - Provides Xilinx USB-to-JTAG and USB-to-UART capability with a single microUSB connector
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Display
   - Ultra96 comes with a mini DisplayPort connector
   - Use a miniDP-to-DP cable with a DisplayPort monitor or a miniDP-to-HDMI adapter with HDMI monitor
- Mezzanine Products
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components
   - [Seeed Grove Starter Kit](https://www.96boards.org/product/sensors-mezzanine/)

***

# Out of the Box

The following subsections describe how to get started with the Ultra96 using the release build shipped with your board. The MicroSD card provided in the kit is blank. Download the [MicroSD card image](http://avnet.me/ultra96-v2-oob). An easy way to copy the linux image to the MicroSD card uses [Etcher](https://www.balena.io/etcher/).

<img src="https://github.com/96boards/documentation/blob/master/consumer/ultra96/ultra96-v2/additional-docs/images/images-board/sd/ultra96-front-sd.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/ultra96/ultra96-v2/additional-docs/images/images-board/sd/ultra96-front-sd.png?raw=true" width="250" height="160" />
<img src="https://github.com/96boards/documentation/blob/master/consumer/ultra96/ultra96-v2/additional-docs/images/images-board/sd/ultra96-back-sd.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/ultra96/ultra96-v2/additional-docs/images/images-board/sd/ultra96-back-sd.png?raw=true" width="250" height="160" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Xilinx Zynq UltraScale+ MPSoC ZU3EG A484                                                         |
|  RAM                 | Micron LPDDR4 memory provides 2 GB of RAM in a 512M x 32 configuration                           |
|  Storage             | Delkin 16 GB microSD card + adapter                                                              |
|  Wireless            | 802.11b/g/n Wi-Fi and _Bluetooth_® wireless technology 4.2 (provides both Bluetooth Classic and Low Energy (BLE))       |
|  USB                 | 1x USB 3.0 Type Micro-B upstream port<br>2x USB 3.0, 1x USB 2.0 Type A downstream ports          |
|  Display             | Mini DisplayPort (MiniDP or mDP)                                                                 |
|  Expansion Interface | 40-pin 96Boards Low-speed expansion header<br>60-pin 96Boards High speed expansion header        |
|  LED                 | 4 x user-controllable LEDs                                                                       |
|  Power Source        | 12V@2A, Plug specification is inner diameter 1.7mm and outer diameter 4.8mm                   |
|  OS Support          | Linux                                                                                            |
|  Size                | 85mm x 54mm                                                                                      |

***

## Starting the board for the first time

The Ultra96 comes with a blank MicroSD card that must be loaded with linux before it can be used. Download the [MicroSD card image](http://avnet.me/ultra96-v2-oob). An easy way to copy the linux image to the MicroSD card uses [Etcher](https://www.balena.io/etcher/).

After loading the linux image on the card, it can be up and running in two ways:

> NOTE: In both cases ensure the included microSD card is fully inserted in the microSD card cage.

- **Option 1**
   - Connect the power supply to the Ultra96, the green LED D17 will illuminate.
   - Momentarily press the button labeled SW4 / POWER.  It is located between the two USB 3.0 Type A ports, the green power on LED D2 will illuminate.
   - The first sign that the boot process has begun will be an blue LED labeled D1 / DONE illuminating.  This means that the bistream for the FPGA portion of Ultra96v2 has successfully loaded.  This happens during uboot.
   - Once LED D7 begins to show a regular "heartbeat" Linux is up and running.
   - From a laptop or other device search for and connect to the WI-FI network called Ultra96_xxxxxxxxxxxx, where the 12 x's correspond to Ultra96's MAC ID.
   - From a browser, go to http://192.168.2.1
   - You will be greeted by Ultra96v2's homepage.

- **Option 2**
   - Connect the Ultra96v2 to a DisplayPort monitor with a miniDP to DisplayPort cable plugged into the connector labeled DISPLAY PORT.
   - Connect a USB keyboard and mouse to J8 and J9, or through a USB hub connected to J8 or J9.
   - Connect the power supply to the Ultra96.
   - Momentarily press the button labeled SW4 / POWER.  It is located between the two USB 3.0 Type A ports.
   - You will be able to watch the progress of the boot process on the monitor.
   - As in Option 1, an LED labeled D1 / DONE will illuminate at some point during boot.  This means that the bistream for the FPGA portion of Ultra96 has successfully loaded.
   - Linux will boot, launching a desktop environment.

***

## What's Next?

If you are already familiar with the Ultra96 and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads): This page lists all Linaro and 3rd party operating systems available for the Ultra96
- [Installation page](../installation): If you already have the images you need, this page has information on how to install the different operating systems onto your Ultra96
- [Guides](../guides/)
- [Board Recovery](../installation/board-recovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Support](../support)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Ultra96 documentation home page](../)

***
