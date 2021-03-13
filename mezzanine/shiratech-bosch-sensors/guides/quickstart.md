---
title: Shiratech Bosch Sensors Mezzanine Quickstart Guides
permalink: /documentation/mezzanine/shiratech-bosch-sensors/guides/quickstart.md.html
---
# Introduction

Shiratech Bosch Sensors Mezzanine is a 96Boards compatible mezzanine board that adds a set of sensors to any 96Boards CE/EE boards.

This quick start guide will show you how to connect the mezzanine and install the on board sensors demo application on Debian Linux.

# Box content
- Bosch Sensors Mezzanine board
- Quick start guide

# Required hardware
- USB flash drive or Micro SD card
- 96Boards CE board running latest Debian Linux, in this guide we will use the Dragonboard 410C
- Power supply
- HDMI monitor and cable
- USB mouse and keyboard

# Running the mezzanine for the first time
- Connect the mezzanine on top of your 96BoardsCE board.
- Connect HDMI monitor,USB keyboard and USB mouse to your board.
- Power on your board.
- Download and install the latest Debian Linux for your 96Boards CE board.
For Dragonboard 410C follow the instructions in the following [link](/documentation/consumer/dragonboard/dragonboard410c/downloads/debian.md.html)

# On board sensors demo installation
- Download the sensor demo applicationfrom the following [link](http://www.shiratech-solutions.com/resources/)
- Copy the file sensordemo_1.0_all.deb to a USB flash drive or micro SD card and connect it to your 96Board CE board.
- Open a terminal window.
- To install the sensors demo application, type ```$ sudo apt-get install <sensor-demo.deb path>```
- Once installation is complete open a Web browser and type the following address: ```127.0.0.1:8081```
- The web browser will show an HTML page displaying the five on-board sensors data readings refreshing.
- Move the board and see the absolute orientation sensor data readings changes according to the board movement.
- To remove the sensor demo application type: ```$sudo apt-get remove sensordemo```
