---
title: Getting Started with Akebi96
permalink: /documentation/enterprise/akebi96/getting-started/
---
# Getting Started

Learn about your Akebi96 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Akebi96 Board](https://www.96boards.org/product/akebi96/)
   - Board based on the Socionext LD20 Processor
- Power adapter
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equipped with a full sized HDMI connector, HDMI capable monitor is recommended

***

# Out of the Box

The following subsections should describe how to get started with the Akebi96 using the release build shipped with the boards. The Akebi96 board is ready to use “out of the box” with a preinstalled version of the Debian Linux distribution.

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Socionext LD20                                                                                   |
|  CPU                 | Quad-core 64-bit, 2x ARM Cortex-A53, 2x ARM Cortex-A72                                           |
|  RAM                 | 3GB DDR3 1866MHz                                                                                 |
|  Storage             | 16GB eMMC <br> Micro SD                                                                          |
|  Ethernet Port       | 10M/100M/1000Mbps <br> PHY : RTL8211E-VB-CG(REALTEK)                                             |
|  Wireless            | WiFi : Dual-band 2T2R 802.11a/b/g/n/ac <br> BT : Ver.4.1 <br> Chipset : RTL8822BU(REALTEK) <br> Module : FN-LINK 6222D-UUB                                                              |
|  USB                 | USB3.0 x1, USB2.0 x1, micro USB x 2(for Debugging)                                               |
|  PCIe                | One PCIe x1 2.0 interfaces                                                                       |
|  Expansion Interface | Linaro 96Boards Low Speed Expansion slot                                                         |
|  Dimension           | Standard 160×120 mm 96Boards Enterprice Edition form factor                                      |
|  Connectors          | One connector for Smart Card One connector for TSI                                               |

***

## Starting the board for the first time

Before starting your Akebi96 for the first time, it is suggested to build and flash the appropriate software. Instructions on how to do this can be found [HERE](https://github.com/96boards-akebi96/Documentation)

***

## Updating to a new release or change your operating system

If you are already familiar with the Akebi96 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Board Recovery](https://github.com/96boards-akebi96/Documentation/)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Support](../support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Akebi96 documentation home page](../)

***
