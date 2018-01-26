---
title: Getting Started with the DragonBoard 820c
permalink: /documentation/consumer/dragonboard820c/getting-started/
---
# Getting Started

Learn about your DragonBoard™ 820c board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [DragonBoard 820c](http://www.96boards.org/product/dragonboard820c/)
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

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-doc/images/images-board/sd/dragonboard820c-front-sd.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-doc/images/images-board/sd/dragonboard820c-front-sd.png?raw=true" width="480" height="250" />
<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-doc/images/images-board/sd/dragonboard820c-back-sd.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/additional-doc/images/images-board/sd/dragonboard820c-back-sd.png?raw=true" width="480" height="250" />

## Features

|   Component          |   Description                                                                                             |
|:---------------------|:----------------------------------------------------------------------------------------------------------|
|  SoC                 | Qualcomm Snapdragon 820                                                                                   |
|  CPU                 | Quad-core Qualcomm® Kryo™at up to 2.15GHz per core, 64-Bit capable                                        |
|  GPU                 | Qualcomm® Adreno™ 530 624MHz GPU for PC-class graphics with support for advanced APIs, including OpenGL ES 3.1+, OpenCL, DirectX, and content security       |
|  RAM                 | 3GB LPDDR4 1866MHz                                                                                        |
|  Storage             | 32GB UFS 2.0, SD 3.0 (UHS-I)                                                                              |
|  Wireless            | WLAN 2x2 802.11 b/g/n/ac 2.4 and 5GHz with on-board dual band WLAN antennas<br>Bluetooth v4.1 with on-board antenna<br>GPS with On-board GPS antenna    |
|  USB                 | One USB 2.0 micro B (device mode only), Two USB 3.0 (host mode only)                                      |
|  Video               | 4K UltraHD@30fps video playback and capture with H.264 (AVC) and H.265 (HEVC)  |
|  Audio               | PCM/AAC+/MP3/WMA, ECNS, Audio+ post-processing (optional)                                                 |
|  Camera              | Integrated Dual ISP with support for 3 image sensors up to 28MP                                           |
|  Expansion Interface | MINI PCIe, One 40-pin Low Speed (LS) expansion connector, Two 60-pin High Speed (HS) expansion connector, One 16 pin audio expansion connector, Camera connector based upon 96boards camera interface addendum. 30 pin connector ZIF connector with 4L-CSI, DC power, 5V and 3.3V supply, camera control signals, I2C.  |
|  LED                 | 4 - user controllable, 2 - for radios (BT and WLAN activity)                                              |
|  Button              | Power/Reset, Volume up, Volume down                                                                       |
|  Power Source        | Input voltage: +6.5V to +18V                                                                              |
|  OS Support          | Linux Debian                                                                                              |
|  Size                | 100mm by 85mm meeting 96Boards™ Consumer Edition ’extended’ dimensions specifications                     |


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

For more information and support, you may also want to visit the [DragonBoard 820c Hardware User Manual](https://github.com/96boards/documentation/blob/master/consumer/dragonboard820c/hardware-docs/files/db820c-user-guide.pdf).

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
