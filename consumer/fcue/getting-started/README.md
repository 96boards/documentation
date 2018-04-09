<!---
---
title: Basic Kit  for boardname
permalink: /documentation/consumer/boardname/getting-started/
---
-->

# Getting Started

Learn about your Board-X board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Board-X](Insert Board-X 96Boards.org landing page link here)
   - Board based on the XXXXXXX Processor
- Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended
- Jumpers
   - J15 Header on the Board-X comes with two pin-jumpers

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

The following subsections should describe how to get started with the Board-X using the release build shipped with the boards. The Board-X board is ready to use “out of the box” with a preinstalled version of the Debian Linux distribution.

< Please send all HD board images to robert.wolff@linaro.org to have these replaced >

<img src="" data-canonical-src="" width="250" height="160" />
<img src="" data-canonical-src="" width="250" height="160" />
<img src="" data-canonical-src="" width="250" height="160" />

## Features

< Please add descriptions to table, example "Getting Started" page can be found here: >

< https://github.com/96boards/documentation/blob/master/ConsumerEdition/DragonBoard-410c/GettingStarted/README.md >

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

**IMPORTANT NOTES**

< Insert Board-X Important notes - Example Below - This section should be monitored by board maintainers. This information should be periodically updated. Please treat this section as a "News" section. Important notes should consist of thing you think end user MUST KNOW to minimize unnecessary support questions surrounding the out of box experience with shipped stock image >

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with **MOST but not all** monitors/TVs.
- There are limitations on the usage of the USB ports on the Board-X board.

***

## Starting the board for the first time

< Insert Board-X Initial Start up instructions - Example below >

**The Board-X comes preloaded with Debian Linux and can be up and running with a few simple steps:**

- Connect the Board-X to your display with the HDMI cable. It is important to do this first because the monitor will not detect the board if it is connected after starting. Ensure that the source for the display is switched to the HDMI port you are using
- Connect the USB keyboard and mouse. Do not connect the USB OTG port to your computer – this will prevent the keyboard and mouse from operating. The USB OTG port is the micro USB connector on the board

> Note: The above setup will cause Board-X Board to Auto Power up when it is plugged into power

- Connect the power supply to the Board-X. The board will begin to boot Debian Linux immediately

***

## Updating to a new release or change your operating system

If you are already familiar with the Board-X board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/README.md): This page lists all Linaro and 3rd party operating systems available for Board-X
- [Installation page](../installation/README.md): If you already have the images you need, this page has information on how to install the different operating systems onto your Board-X board
- [Board Recovery](../installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../support/README.md)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Board-X documentation home page](../README.md)

***   
