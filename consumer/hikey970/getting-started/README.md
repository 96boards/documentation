---
title: Getting Started with the HiKey970
permalink: /documentation/consumer/hikey970/getting-started/
---

# Getting Started

Learn about your HiKey970 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- HiKey970
   - Board based on the HI3670 Application Processor
- Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- A HDMI LCD Monitor that supports a resolution of 1080P/60Hz
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended
- HDMI-HDMI cable cable to connect the board to the Monitor.

**Optional**
- MicroSD card with adapter
   - For quick and easy switching between operating systems and extra storage
- Mezzanine Products
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components
- USB to MicroUSB cable
   - This is needed for serial console interface and fastboot/adb commands
- USB to ethernet adapter and ethernet cable
   - For connecting to a network without using WiFi

***

# Out of the Box

The following subsections should describe how to get started with the Board-X using the release build shipped with the boards. The HiKey970 board is ready to use “out of the box” with a preinstalled version of the Debian Linux distribution.



<img src="" data-canonical-src="" width="250" height="160" />
<img src="" data-canonical-src="" width="250" height="160" />
<img src="" data-canonical-src="" width="250" height="160" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 |                                                                                                  |
|  CPU                 |                                                                                                  |
|  GPU                 |                                                                                                  |
|  RAM                 |                                                                                                  |
|  PMU                 |                                                                                                  |
|  Storage             | 	                                                                                               |
|  Ethernet Port       |                                                                                                  |
|  Wireless            |                                                                                                  |
|  USB                 |                                                                                                  |
|  Display             |                                                                                                  |
|  Video               |                                                                                                  |
|  Audio               |                                                                                                  |
|  Camera              |                                                                                                  |
|  Expansion Interface |                                                                                                  |
|  LED                 |                                                                                                  |
|  Button              |                                                                                                  |
|  Power Source        |                                                                                                  |
|  OS Support          |                                                                                                  |
|  Size                |                                                                                                  |


***

## Starting the board for the first time

To start the board, follow these simple steps:

- Step 1. Connect the HDMI cable to the HiKey970 HDMI connector (marked J2001) and to the LCD Monitor.
- Step 2. Connect the keyboard to the boards USB connector marked J1901(or J1902) and the mouse to the USB connector marked J1902(or J1901).
- Step 3. Ensure that the boot switches SW2402 are set to ‘1000’, on/off/off/off position.
- Step 4. Connect the power supply to power connector J401.

Once you plug the power supply into a power outlet the board will start the booting process, and you should see Android boot up.
Please note that the first boot takes several minutes due to Androids initialization. Subsequent boot times should be faster.

***

## What's Next?

If you are already familiar with the HiKey970 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/): This page lists all Linaro and 3rd party operating systems available for Board-X
- [Installation page](../installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your Board-X board
- [Support](../support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Board-X documentation home page](../)

***   
