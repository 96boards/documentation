---
title: WinLink E850-96Board Installation
permalink: /documentation/consumer/e850-96b/installation/
---
# Installation

This guide will help you choose and install an operating system on your WinLink E850-96Board.

This requires the following hardware:

- WinLink E850-96Board with power supply
- Host machine (Linux, Mac OS X, or Windows)
- MicroSD card with 8GB (Class 10 recommended) or more for storage
- USB Mouse and/or keyboard
- HDMI Monitor

1. Download prebuilt Android-Q images:
    - `$ cd ~/repos`<br>`$ git clone https://gitlab.com/Linaro/96boards/e850-96/images`


2. Boot the board into fastboot mode:
    - Connect the power to your board
    - Press “POWER” button for 1 second to power on the board
    - Press and hold “VOLUME DOWN” button for around 10 seconds.

3. Flash all images to eMMC:
   - `cd ~/repos/images`<br>`./flash-all.sh`

The board is going to reboot automatically, and some Android UI will appear on your TV screen
(please use HDMI connection for that). You can control the UI with mouse and keyboard connected
to USB ports on your board.