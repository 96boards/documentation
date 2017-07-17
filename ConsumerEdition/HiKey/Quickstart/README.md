---
title: QuickStart Guides for HiKey
permalink: /documentation/ConsumerEdition/HiKey/QuickStart/
redirect_from: /documentation/ConsumerEdition/HiKey/QuickStart/README.md/
---
# Getting Started

Learn about your HiKey board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [HiKey Development Board](http://www.96boards.org/product/hikey/)
   - Board based on HiSilicon Kirin 6220 processor
- [Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- [USB Keyboard and Mouse](USBKeyBoardMouse.md)
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- [Monitor and HDMI Cable](MonitorHDMI.md)
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended
- Jumpers
   - J15 Header on the HiKey comes with two pin-jumpers

**Optional**
- MicroSD card with adapter
   - For quick and easy switching between operating systems and extra storage
- [Mezzanine Products](../../../MezzanineProducts/)
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components
- USB to MicroUSB cable
   - This is needed for serial console interface and fastboot/adb commands
- USB to ethernet adapter and ethernet cable
   - For connecting to a network without using WiFi

***

# Out of the Box

The following subsections should describe how to get started with the HiKey using the release build shipped with the boards. The HiKey board is ready to use “out of the box” with a preinstalled version of the Debian Linux distribution.

<img src="http://i.imgur.com/uKfxuu5.jpg" data-canonical-src="http://i.imgur.com/uKfxuu5.jpg" width="250" height="160" />
<img src="http://i.imgur.com/g5X5j72.jpg" data-canonical-src="http://i.imgur.com/g5X5j72.jpg" width="250" height="160" />
<img src="http://i.imgur.com/egwXwjX.jpg" data-canonical-src="http://i.imgur.com/egwXwjX.jpg" width="250" height="160" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Kirin 620                                                                                        |
|  CPU                 | ARM® CortexTM-A53 Octa-core 64-bit up to 1.2GHz (ARM v8 instruction set)                         |
|  GPU                 | ARM Mali 450-MP4, supporting 3D graphics processing, OpenGL ES 1.1/2.0, OpenVG 1.1, 2000Mega@500 MHz, 110M triangle@500 MHz, and 32G flops@500MHz                                                                                    |
|  RAM                 | 1GB/2GB LPDDR3 SDRAM @ 800MHz                                                                    |
|  PMU                 | HI6553V100                                                                                       |
|  Storage             | 8GB eMMC on board storage MicroSD card slot	                                                     |
|  Ethernet Port       | USB2.0 expansion                                                                                 |
|  Wireless            | Wi-Fi 802.11 b/g/n 2.4GHz Dual-mode bluetooth and bluetooth low energy                           |
|  USB                 | 2 x USB2.0 Host 1 x USB 2.0 OTG                                                                  |
|  Display             | 1 x HDMI 1.4 (Type A - full) 1 x MIPI-DSI HDMI output up to FHD 1080P                            |
|  Video               | 1080p@30 fps HD video encoding, supporting 1080p@30 fps HD camera 1080p@30 fps HD video decoding Supports H.264, SVC, MPEG1/2/4, H.263, VC-1, WMV9, DivX, RV8/9/10, AVS, VP8                                                        |
|  Audio               | HDMI output                                                                                      |
|  Camera              | One 4-lane MIPI camera serial interface(CSI), one 2-lane MIPI CSI                                |
|  Expansion Interface | 40 pin low speed expansion connector: +1.8V, +5V, SYS_DCIN, GND, UART, I2C, SPI, PCM, PWM,GPIO x12 60 pin high speed expansion connector:   SDIO, MIPI_DSI, MIPI_CSI                                                                |
|  LED                 | 1 x WiFi activity LED（Yellow） 1 x BT  activity LED (Blue) 4 x User LEDs (Green)                |
|  Button              | Power Button ： Button Power on/off & Reset the system                                           |
|  Power Source        | 8V~18V@3A, Plug specification is inner diameter 1.7mm and outer diameter 4.8mm                   |
|  OS Support          | Android 4.2 / Debian Linux                                                                       |
|  Size                | 85mm x 54mm                                                                                      |

**IMPORTANT NOTES**

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with **MOST but not all** monitors/TVs.
- There are limitations on the usage of the USB ports on the HiKey board.

***

## Starting the board for the first time

**The HiKey comes preloaded with Debian Linux and can be up and running with a few simple steps:**

- Connect the HiKey to your [display with the HDMI cable](MonitorHDMI.md). It is important to do this first because the monitor will not detect the board if it is connected after starting. Ensure that the source for the display is switched to the HDMI port you are using
- Connect the [USB keyboard and mouse](USBKeyBoardMouse.md). Do not connect the USB OTG port to your computer – this will prevent the keyboard and mouse from operating. The USB OTG port is the micro USB connector on the board
- Ensure J15 Jumper pins are linked as follows:

| Name          | Link     | State  |
|:--------------|:--------:|:------:|
| Auto Power up | Link 1-2 | closed |
| Boot Select   | Link 3-4 | open   |
| GPIO3-1       | Link 5-6 | open   |

> Note: The above setup will cause HiKey Board to Auto Power up when it is plugged into power

- Connect the power supply to the HiKey. The board will begin to boot Debian Linux immediately

***

## Updating to a new release or change your operating system

If you are already familiar with the HiKey board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../Downloads/): This page lists all Linaro and 3rd party operating systems available for HiKey
- [Installation page](../Installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your HiKey board
- [Board Recovery](../Installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../Troubleshooting/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [HiKey documentation home page](../)

***   
