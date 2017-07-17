---
title: Getting Started with Bubblegum-96
permalink: /documentation/ConsumerEdition/Bubblegum-96/GettingStarted/
redirect_from: /documentation/ConsumerEdition/Bubblegum-96/GettingStarted/README.md/
---
# Getting Started

Learn about your Bubblegum-96 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Bubblegum-96 Development Board](http://www.96boards.org/product/bubblegum-96/)
   - Board based on Actions Semi S900 Processor
- [Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 6.5V-18V with 2000mA Power adapter
- [USB Keyboard and Mouse](USBKeyBoardMouse.md)
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- [Monitor and HDMI Cable](MonitorHDMI.md)
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended

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

The following subsections should describe how to get started with the Bubblegum-96 using the release build shipped with the boards. The Bubblegum-96 board is ready to use “out of the box” with a preinstalled version of Android.

<img src="http://i.imgur.com/eVR3IZv.png" data-canonical-src="http://i.imgur.com/eVR3IZv.png" width="250" height="160" />
<img src="http://i.imgur.com/gaFuoBk.png" data-canonical-src="http://i.imgur.com/gaFuoBk.png" width="250" height="160" />
<img src="http://i.imgur.com/XHiHLOl.png" data-canonical-src="http://i.imgur.com/XHiHLOl.png" width="250" height="160" />

## Features

|   Component          |   Description                                                                                          |
|:---------------------|:-------------------------------------------------------------------------------------------------------|
|  SoC                 | Actions - S900                                                                                         |
|  CPU                 | ARM Cortex-A53 Quad-core up to 1.8GHz                                                                  |
|  GPU                 | Imagination Power VR G6230, OpenGL ES 3.1, OpenGL 3.2, DirectX 10, OpenCL 1.2 EP                       |
|  RAM                 | 2GB LPDDR3 @ 533MHz                                                                                    |
|  PMU                 | ???                                                                                                    |
|  Storage             | 8GB eMMC 4.51 on board storage MicroSD card slot	                                                     |
|  Ethernet Port       | USB 2.0 expansion                                                                                      |
|  Wireless            | Wi-Fi 802.11 b/g/n 2.4GHz Dual-mode bluetooth and bluetooth low energy                                 |
|  USB                 | 1 x USB2.0, 1 x USB3.0, 1 x USB 2.0 OTG                                                                |
|  Display             | HDMI 1.4b with HDCP (HDMI connector type A/C), up to 4k Ultra                                          |
|  Video               | 1080p@60fps HD video playback and capture with H.264 (AVC), 4096*2304@30fps playback with H.265 (HEVC) |
|  Audio               | PMC / AAC+ / MP3 / WMA                                                                                 |
|  Camera              |                                                                              |
|  Expansion Interface | 40 pin low speed expansion connector: UART, SPI, I2S, I2Cx2, GPIOx12, DC Power; 60 pin high speed expansion connector: 4L-MIPI DSI, USB, I2C x2, 2L+4L-MIPI CSI; 1xJTAG header option                                                       |
|  LED                 | 6 x LED: 4xUser controlled, 2xRadio(BT and WLAN activity)                                               |
|  Button              | ???                                                                             |
|  Power Source        | 6.5V~18V@3A, Plug specification is inner diameter 1.7mm and outer diameter 4.8mm  |
|  OS Support          | Android 5.1 / Debian Linux / Ubuntu Core / Android Remix                                          |
|  Size                | 85mm x 54mm                                                                     |

**IMPORTANT NOTES**

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with **MOST but not all** monitors/TVs.
- There are limitations on the usage of the USB ports on the Bubblegum-96 board.

***

## Starting the board for the first time

**The Bubblegum-96 comes preloaded Android and can be up and running with a few simple steps:**

- Connect the Bubblegum-96 to your [display with the HDMI cable](MonitorHDMI.md). It is important to do this first because the monitor will not detect the board if it is connected after starting. Ensure that the source for the display is switched to the HDMI port you are using
- Connect the [USB keyboard and mouse](USBKeyBoardMouse.md). Do not connect the USB OTG port to your computer – this will prevent the keyboard and mouse from operating. The USB OTG port is the micro USB connector on the board
- Connect the power supply to the Bubblegum-96.

Once you plug the power supply into a power outlet, the board will start the booting process. You should see Android boot up.

Please note, the first boot takes several minutes due to Androids initializations. Subsequent boot times should be faster after the first boot.

***

## Updating to a new release or change your operating system

If you are already familiar with the Bubblegum-96 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page**](../Downloads/): This page lists all Linaro and 3rd party operating systems available for HiKey
- [Installation page](../Installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your Bubblegum-06 board
- [Board Recovery](../Installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../Support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Bubblegum-96 documentation home page](../)

***   
