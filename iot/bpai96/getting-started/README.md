---
title: Getting Started with BPai96
permalink: /documentation/iot/bpai96/getting-started/
redirect_from:
- /documentation/iot/bpai96/getting-started/README.md/
---
# Getting Started

Learn about your BPai96 board as well as how to prepare and set up for basic use

## Setup - What you will need

- **Software**
  - PC Running Windows
  - [Arm Keil MDK](http://www2.keil.com/mdk5)
  - MDK5&STM32F1XX Package for Keil
- **Hardware**
  - [JLink Debugger](https://www.segger.com/products/debug-probes/j-link/)
  - Power supply : Micro USB or 3.7V Li-ion

***

# Out of the Box

Coming soon...

## Features

|   Component          |   Description                   |
|:---------------------|:--------------------------------|
|  SoC                 | STM32F103RCT6 / STM32F103RBT6   |
|  CPU                 | ARM 32-bit CortexTM-M3          |
|  Clock speed         | 72 MHz                          |
|  SRAM                | 48KB / 20 KB                    |
|  Storage             | 256KB / 128KB                   |
|  Wireless            | Quectel BC95-B5/8/20 or BC95-G  |
|  Expansion Interface | 40pin GPIO                      |
|  Digital Out Voltage | 1.8v                            |
|  OS Support          | LiteOS                          |

For more information, please refer to the [Hardware User Manual] ([View](https://github.com/96boards/documentation/blob/master/iot/bpai96/hardware-docs/bpai96-user-manual.pdf) / [Download](https://github.com/96boards/documentation/raw/master/iot/bpai96/hardware-docs/bpai96-user-manual.pdf))

**IMPORTANT NOTES**

- Keil is a Windows only IDE

***

## Starting the board for the first time

**How to connect?**

![](/documentation/iot/bpai96/additional-docs/images/images-hw-user-manual/Interface_line_sequence-en.png)

JLink and BPI NB-IoT Linaro SWD mode connection:

![](/documentation/iot/bpai96/additional-docs/images/images-hw-user-manual/connect1.png)

MDK5 “Options for Target” — “Debug” setting：

First need to build the project file based on the corresponding chip, and in the Options of Target do the following settings

（Project file specific settings include but are not limited to the following settings）

![](/documentation/iot/bpai96/additional-docs/images/images-hw-user-manual/debug_setting_1.png)

![](/documentation/iot/bpai96/additional-docs/images/images-hw-user-manual/debug_setting_2.png)

（Development board needs to be kept powered）

Debug method：

1.	You can use the debug serial port (MCU USART1) to debug.

2.	Use Micro USB virtual serial port for debugging.
The above two methods require MCU program support

Note：

1.	Debug serial port, SWD simulation interface spacing 2.54mm, GPIO pitch 2.0mm

2.	The LED next to the Micro USB is the power indicator, which should be on after any power-up.
 
- ## NB-Iot part

This module needs to be used with NB_IOT SIM card.

Different carriers support different frequency bands，Module operating frequency band to distinguish the module model，such as：

![](/documentation/iot/bpai96/additional-docs/images/images-hw-user-manual/Band.png)

##### Firmware version：

Query firmware instructions：AT+CGMR

Result：V100R100C10B656SP2  firmware version is B656SP2

##### Scramble code function：

The module is consistent with the base station.

##### SIM Card:

The module can used two kinds of SIM card. Standard SIM card or eSIM card.

##### Antenna:

The module has reserved the MHF WiFi antenna interface, which can be selected according to the actual usage of the product.

***

## What's Next?

If you are already familiar with the BPai96 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/): This page lists all Linaro and 3rd party operating systems available for the BPai96
- [Installation page](../installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your BPai96
- [Board Recovery](../installation/)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../support/)

- From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [BPai96 documentation home page](../)

***   
