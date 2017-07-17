---
title: Getting Started with Poplar
permalink: /documentation/EnterpriseEdition/Poplar/GettingStarted/
redirect_from: /documentation/EnterpriseEdition/Poplar/GettingStarted/README.md/
---
# Getting Started

Learn about your Poplar board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Poplar Board](http://www.96boards.org/product/poplar/)
   - Board based on the HiSilicon Hi3798C V200 Processor
- Power adapter
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equipped with a full sized HDMI connector, HDMI capable monitor is recommended
- Jumper Caps
   - Poplar board comes with three pin-jumper caps

***

# Out of the Box

The following subsections should describe how to get started with the Poplar using the release build shipped with the boards. The Poplar board is ready to use “out of the box” with a preinstalled version of the Debian Linux distribution.

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | HiSilicon Hi3798C V200                                                                           |
|  CPU                 | Integrated Quad-core 64-bit ARM Cortex-A53 CPU up to 2.0 GHz per core                            |
|  RAM                 | DDR3/3L/4 SDRAM interface, maximum 32-bit data width 2 GB on board                               |
|  Storage             | 8GB eMMc On-Board storage                                                                        |
|  Ethernet Port       | 1 GBe Ethernet                                                                                   |
|  Wireless            | 802.11AC 2x2 with Bluetooth                                                                      |
|  USB                 | Two USB 2.0 ports One USB 3.0 ports                                                              |
|  Console             | USB-micro port for console support                                                               |
|  PCIe                | One PCIe 2.0 interfaces                                                                          |
|  JTAG                | 8-Pin JTAG                                                                                       |
|  Expansion Interface | Linaro 96Boards Low Speed Expansion slot                                                         |
|  Dimension           | Standard 160×120 mm 96Boards Enterprice Edition form factor                                      |
|  Connectors              | One connector for Smart Card One connector for TSI                                           |

**IMPORTANT NOTES**

Coming soon...

***

## Starting the board for the first time

Before starting your Poplar for the first time, it is suggested to build and flash the appropriate software. Instructions on how to do this can be found [HERE](https://github.com/Linaro/poplar-tools/blob/latest/build_instructions.md)

***

## Updating to a new release or change your operating system

If you are already familiar with the Poplar board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Board Recovery](https://github.com/Linaro/poplar-tools/blob/latest/build_instructions.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Support](../Support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Poplar documentation home page](../)

***   
