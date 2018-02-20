---
title: Getting Started with the DragonBoard 820c
permalink: /documentation/consumer/dragonboard820c/getting-started/
---
# Getting Started

Learn about your DragonBoard™ 820c board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [DragonBoard 820c](../../dragonboard820c/)
   - Board based on Qualcomm® Snapdragon™ 820E processor
- Power adapter
   - 96Boards specifications requires a 6.5V-18V with 2000mA Power adapter
- USB Keyboard and Mouse
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Monitor and HDMI Cable
   - All 96Boards are equiped with a full sized HDMI connector, HDMI capable monitor is recommended

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

The following subsections should describe how to get started with the DragonBoard 820c using the release build shipped with the boards. The DragonBoard 820c is ready to use “out of the box” with a preinstalled version of Android (unless otherwise specified).

<img class="lazyload" src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-docs/images/images-board/sd/dragonboard820c-front-sd.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-docs/images/images-board/sd/dragonboard820c-front-sd.png?raw=true" width="480" height="250" />
<img class="lazyload" src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-docs/images/images-board/sd/dragonboard820c-back-sd.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-docs/images/images-board/sd/dragonboard820c-back-sd.png?raw=true" width="480" height="250" />

## Features

|   Component          |   Description                                                                  |
|:---------------------|:-------------------------------------------------------------------------------|
|  SoC                 | Qualcomm® Snapdragon™ 820E                                                     |
|  CPU                 | Snapdragon 820E embedded platform, custom 64-bit Kryo quad-core CPU up to 2.35GHz , 14nm FinFET process technology                                                  |
|  GPU                 | Adreno™ 530 GPU OpenGL ES 3.1 + AEP, OpenCL2.0 Full1, Vulcan, Renderscript, 64-bit virtual addressing                                                                                  |
|  RAM                 | Dual-channel PoP LPDDR4 1866MHz                                                |
|  Storage             | 32GB UFS 2.0 and SD 3.0 (UHS-I)                                                |
|  Ethernet Port       | GbE Ethernet connection                                                        |
|  Wireless            | WLAN 802.11ac and Bluetooth 4.2                                                |
|  USB                 | One USB 2.0 micro B (device mode only)<br>Two USB 3.0 (host mode only)                                                                 |
|  Display             | 4k60 FPS decode 10-bit over HDMI 2.0 4K30<br>Miracast 2.0 streaming HEVC 10-bit and VP9<br>decode Direct Stream Video for Wireless<br>Display, 3:1 Frame Buffer Compression ratio       |
|  Video               | 4K UltraHD@30fps video playback and capture with H.264 (AVC) and H.265 (HEVC)  |
|  Audio               | PCM/AAC+/MP3/WMA, ECNS, Audio+ post-processing (optional)                      |
|  Camera              | Integrated Dual ISP with support for 3 image sensors up to 28MP                |
|  Expansion Interface | Expansion Connectors:<br>1x 96boards 40 pin Low-Speed connector (UART x2, SPI, I2S, I2C x2, GPIO x12, DC power)<br>1x 96boards 60 pin High-Speed connector (4L-MIPI DSI, USB,I2C x2, 2L+4L-MIPI CSI)<br>2x Analog expansion connector (headset, speaker via sound-wire interface, microphones, line-outs)<br>1x 60 pin High-Speed connector (secondary 4L-MIPI DSI, SSC serial busses, TSIF – connection available only in hardware)<br>I/O Interfaces:<br>HDMI Full-size Type A connector (4K@60fps)<br>1x USB 2.0 micro B (device mode only), 2x USB 2.0 type A (host mode only), micro SD card slot<br>1x GbE RJ45, 1x PCIe HMC, headset                                                |
|  LED                 | 6 LED indicators<br>4 - user controllable<br>2 - for radios (BT and WLAN activity) |
|  Button              | Power/Reset<br>Volume Up<br>Volume down                                                                   |
|  Power Source        | 96Boards compliant power supply                  |
|  OS Support          | Linux Debian today<br>Linux OpenEmbedded – later 2018                          |
|  Size                | 100mm by 85mm meeting 96Boards™ Consumer Edition ’extended’ dimensions specifications.               |


***

## Starting the board for the first time

**To start the board, follow these simple steps:**

- Step 1: Connect the HDMI cable to the 820c HDMI connector (marked J6) and to the LCD Monitor.
- Step 2: Connect the mouse and keyboard to the 820C USB connectors marked J2 and. (It doesn’t matter which order
you connect them in. You can also connect via an external USB Hub.)
- Step 3: Ensure that the boot switches S1 are set to ‘0000’, all in Off position.
- Step 4: Connect the power supply to power connector J1.
- Step 5: Plug the power supply into a power outlet.

The board will start the booting process, and you should see Linux boot up. The ’power up’ blue LED ‘DS10’ should
illuminate.

> NOTE: The first boot takes 3-4 minutes due to first time initialization. Subsequent boot times should be faster in
the range of 1-2 minutes.

For more information and support, you may also want to visit the [DragonBoard 820c Hardware User Manual](../hardware-docs/).

***

## What's Next?

If you are already familiar with the i.MX7 96 board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/): This page lists all Linaro and 3rd party operating systems available for the DragonBoard 820c
- [Installation page](../installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your DragonBoard 820c
- [Board Recovery](../installation/board-recovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [Troubleshooting](../support/)

- From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [DragonBoard 820c documentation home page](../)

***
