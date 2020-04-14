---
title: Getting Started with the Chameleon96
permalink: /documentation/consumer/chameleon96/getting-started/
---
# Getting Started

Learn about your Chameleon96 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Chameleon96](../../chameleon96/)
   - Board based on the Intel Cyclone V SoC FPGA
- Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equipped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equipped with a full sized HDMI connector, HDMI capable monitor is recommended

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

The following subsections should describe how to get started with the Chameleon96 using the release build shipped with the boards.

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Intel Cyclone V SoC FPGA<br>Dual ARM Cortex-A9<br>110K Logic Elements FPGA fabric                |
|  GPU                 | Graphics based on Intel Video Suite for FPGA                                                     |
|  RAM                 | 512MB DDR3L (support to 1GByte)                                                                  |
|  PMU                 | 4 to 64 GByte microSD                                                                            |
|  Connectivity        | WLAN 802.11 b/g/n 2.4GHz, _Bluetooth_® wireless technology 4.1, One USB 2.0 OTG micro AB, Two USB 2.0 HOST
1 USB 2.0 Host via expansion connector, Integrated USB-Blaster II JTAG cable                                              |
|  USB                 |                                                                                                  |
|  Display             | Up to 1080p@60fps HD video through a HDMI interface                                              |
|  Video               |                                                                                                  |
|  Audio               | HDMI Audio, Bluetooth Audio, I2S 4Wire interface via expansion connector                         |
|  Camera              | MIPI CSI interface (Mobile Industry<br>Processor Interface - Camera Serial<br>Interface) 2x lane. (requires a custom IP for the FPGA) |
|  Expansion Interface | One 40-pin Low Speed (LS) expansion connector<br>UART x2, SPI, I2S, I2C x2, GPIO x12 and DC power.<br>One 60-pin High Speed (HS) expansion connector<br>SDHC/SDIO, 2L-MIPI DSI, 2L-MIPI CSI, I2C, USB 2.0 HOST & USB 2.0 HOST HSIC<br>The board can be made compatible with Arduino using an add-on mezzanine board.                                                                                                 |
|  User Interface      | Power Button, Reset Button, 6 LED Indicators<br>4 – user controllable<br>2 – for radios (BT and WLAN activity) |
|  Power Source        | +5V to +42VDC (exceeding 96Boards specifications)                                                |
|  OS Support          | Linux OS, terminal base (BuildRoot build)<br>Linux OS, GUI (Yocto build)                         |
|  Size                | Dimensions: 54mm x 85mm meeting 96Boards™ Consumer Edition standard dimensions specifications    |

***

## Starting the board for the first time

Please review the [Chameleon96 User Guide](../hardware-docs/files/chameleon96-user-guide.pdf) for more information on starting your board for the first time.

***

## What's Next?

If you are already familiar with the Chameleon96 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Installation page](../installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your Chameleon96
- [Troubleshooting](../support/) From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Chameleon96 documentation home page](../)



***
