---
title: Shiratech LTE Quickstart Guides
permalink: /documentation/mezzanine/shiratech-lte/guides/quickstart.md.html
---

# 1) Introduction
Shiratech LTE and Sensor Mezzanine is a 96Boards compatible mezzanine board that adds LTE modem functionality and a set of sensors to any 96Boards CE/EE boards.

This quick start guide will show you how to connect the mezzanine and accessories, configure the LTE modem on Debian Linux and install the onboard sensors demo application.

# 2) Box content
- LTE and sensor mezzanineboard
- LTE RF antenna
- Quick start guide

# 3)Required hardware
- Cellular data SIM
- USB flash drive or Micro SD card
- 96Boards CE/EE board running latest Debian Linux–in this guide we will use the Dragonboard 410C
- Power supply
- HDMI monitor and cable
- USB mouse and keyboard

# 4) Running themezzanine for the first time
- Insert your SIM card to the SIM card connector J12 located at the bottom side of the mezzanine
- Connect the mezzanine on top of your 96BoardsCE/EE board.
- Connect the included LTE antenna toRF connector Antenna Main.
- Connect HDMI monitor,USB keyboard and USB mouse to your board.
- Power on your board.
- Download and install the latest Debian Linux for your 96Boards CE/EE board.For Dragonboard 410C follow the instructions in the following link: [/documentation/consumer/dragonboard410c/downloads/debian.md.html](/documentation/consumer/dragonboard410c/downloads/debian.md.html)

# 5) LTE Modem Configuration
- Once Debian desktop is up and running it is time to configure the LTE modem.
- Click the Network Connection icon on the lower right corner of the desktop.
- Select New Mobile Broadband Connection from the menu.
- In the Set up a Mobile Broadband Connection wizard window click Next.
- Select your country and click Next.
- Select your provider and click Next.
- Select your plan and click Next.
- Confirm configuration settings and click Apply.The modem will attempt to connect to the cellular network. Once connection established the network connection icon will change to LTE connected icon.
- Open a web browser and check your new LTE connection.

# 6) On board sensors demo installation
- Download the sensor demo application from the following link: [https://www.dropbox.com/sh/svpftv2j9h795ep/AAAUN1n1NsvoY0OByLw8aIcKa/LTE%20and%20Sensors%20Mezzanine/sensordemo_0.5-1_all.deb?dl=0](https://www.dropbox.com/sh/svpftv2j9h795ep/AAAUN1n1NsvoY0OByLw8aIcKa/LTE%20and%20Sensors%20Mezzanine/sensordemo_0.5-1_all.deb?dl=0)
- Copy the file sensordemo_1.0_all.deb to a USB flash drive or micro SD card and connect it to your 96Board CE/EE board.
- Open a terminal window.
- To install the sensors demo application type:
```
$ sudo apt-get install <sensor-demo.deb path>
# Example:
$ sudo apt-get install /media/linaro/USB/ sensordemo_0.5-1_all.deb
```
- Once installation is complete open a Web browser and type the following address: 127.0.0.1:8080
The web browser will show an HTML page displaying the four onboard sensors data readings refreshing.
- Move your hand above the proximity and time of flight sensors and see the sensors data readings updates.
Move the board and see the absolute orientation sensor data readings changes according to the board movement.
- To remove the sensor demo application type:
```
$ sudo apt-get remove sensordemo
```
- The source for this demo can be downloaded from: [https://www.dropbox.com/sh/svpftv2j9h795ep/AAAhfGr2My1C-Ll_Uye3zN5Ca/LTE%20and%20Sensors%20Mezzanine/LTE_Demo_Source_Files.zip?dl=0](https://www.dropbox.com/sh/svpftv2j9h795ep/AAAhfGr2My1C-Ll_Uye3zN5Ca/LTE%20and%20Sensors%20Mezzanine/LTE_Demo_Source_Files.zip?dl=0)
