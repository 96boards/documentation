---
title: QuickStart for MediaTek X20
permalink: /documentation/ConsumerEdition/MediaTekX20/QuickStart/
redirect_from: /documentation/ConsumerEdition/MediaTekX20/QuickStart/README.md/
---
# Quickstart

Learn about your MediaTek X20 board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [MediaTek X20 Development Board](http://www.96boards.org/products/ce/mediatek-x20/)
   - Read about the MediaTek X20 and see where it is available to buy!
- [Power adapter](https://www.96boards.org/products/accessories/power/)
   - 96Boards specifications requires a 8V-18V with 2000mA Power adapter
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

The following subsections should describe how to get started with the MediaTek X20 using the release build shipped with the boards. The MediaTek X20 Development Board is ready to use “out of the box” with a pre-installed version of Android.

<img src="http://i.imgur.com/Mdjs6Nx.png" data-canonical-src="http://i.imgur.com/Mdjs6Nx.png" width="250" height="160" />
<img src="http://i.imgur.com/3EleXMR.png" data-canonical-src="http://i.imgur.com/3EleXMR.png" width="250" height="160" />
<img src="http://i.imgur.com/p1N2nDt.png" data-canonical-src="http://i.imgur.com/p1N2nDt.png" width="250" height="160" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | Helio X20                                                                                        |
|  CPU                 | 2x ARM Cortex-A72 @ 2.1GHz ~ 2.3GHz<br>4x Cortex-A53 @ 1.95GHz<br>4x Cortex-A53 @ 1.4GHz         |
|  GPU                 | ARM Mali-T880 GPU operating at up to 800MHz                                                      |
|  RAM                 | DDR: 2GB LPDDR3                                                                                  |
|  PMU                 | MT6351                                                                                           |
|  Storage             | 8GB eMMC5.1 on board storage MicroSD card slot	                                                  |
|  Ethernet Port       | USB2.0 expansion                                                                                 |
|  Wireless            | Wi-Fi 802.11 a/b/g/n + Bluetooth 4.1                                                             |
|  USB                 | 2 x USB2.0 Host 1 x USB 2.0 OTG                                                                  |
|  Display             | 1 x HDMI 1.4 (Type A - full) 1 x MIPI-DSI HDMI output up to FHD 1080P                            |
|  Video               | 1080p@30 fps HD video encoding, supporting 1080p@30 fps HD camera 1080p@30 fps HD video decoding Supports H.264, SVC, MPEG1/2/4, H.263, VC-1, WMV9, DivX, RV8/9/10, AVS, VP8                                                        |
|  Audio               | HDMI output                                                                                      |
|  Camera              | One 4-lane MIPI camera serial interface(CSI), one 2-lane MIPI CSI                                |
|  Expansion Interface | 40 pin low speed expansion connector: +1.8V, +5V, SYS_DCIN, GND, UART, I2C, SPI, PCM, PWM,GPIO x12 60 pin high speed expansion connector:   SDIO, MIPI_DSI, MIPI_CSI                                                                |
|  LED                 | 1 x WiFi activity LED（Yellow） 1 x BT  activity LED (Blue) 4 x User LEDs (Green)                |
|  Button              | Power Button ： Button Power on/off & Reset the system                                           |
|  Power Source        | 8V~18V@3A, Plug specification is inner diameter 1.7mm and outer diameter 4.8mm                   |
|  OS Support          | Android Marshmallow 6.0                                                                          |
|  Size                | 85mm x 54mm                                                                                      |

**IMPORTANT NOTES**

- Uncommon BPS rate of 921600.
- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p(or less) this resolution will be selected. This selected mode will work with most but not all monitors/TVs. See below for further information on what to do if your monitor/TV does not display the UI.
There are limitations on the usage of the USB ports on the MediaTek X20 Development Board. Please refer to the Hardware section in the document for further information.

***

## Starting the board for the first time

**The MediaTek X20 comes preloaded with Android and can be up and running with a few simple steps**

- Connect the HDMI cable to the MediaTek X20 Development Board connector (marked CON6501) and to the LCD Monitor
- Set the the third pin (USB HOST SET) of switch SW3205 to the position ON and connect the keyboard to USB connector marked CON6402 and the mouse to the USB connector marked CON6401 (It doesn’t matter which order you connect them in.)
- Plug the power supply into the power outlet
- Press down the button (marked SW3201), and keep more than 3 seconds, the Android system will start

> Note: If set the first pin (AUTO_BOOT_SET) of switch SW3205 to the position ON, the Android system will start automatically when the power supply is plugged into the power outlet.

***

## Updating to a new release or change your operating system

If you are already familiar with the MediaTek X20 board and would like to change out the stock operating system please proceed to one of the following pages:

- [Downloads page**](../Downloads/): This page lists all Linaro and 3rd party operating systems available for MediaTek X20
- [Installation page](../Installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your MediaTek X20 board
- [Board Recovery](../Installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../Troubleshooting/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers
