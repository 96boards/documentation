---
title: Audio Mezzanine Getting Started Guides
permalink: /documentation/mezzanine/audio-mezzanine/Guides/beginner-guides/getting-started.md.html
---

# Basic Setup Guide

## Table of Content
- [1. Hardware](#1-hardware)
  - [1.1 Hardware Overview](#11-hardware-overview)
  - [1.2 Hardware Requirements](#12-hardware-requirements)
  - [1.3 Hardware Setup](#13-hardware-setup)
- [2 Software Setup](#21-software-setup)

# 1. Hardware
## 1.1 Hardware Overview
![Front labeled](/mezzanine/audio-mezzanine/images/audio-mezz-front-labeled.png)

1. Switch 1: On/Off switch for 2.5mm Low speed Header
2. Switch 2: Voltage Select for Groove Connectors and 2.5mm Low speed Header 3v3 and 5v
3. Groove Connector: i2c-0
4. Groove Connector: GPIO A and B
5. Groove Connector: UART0
6. Groove Connector: GPIO I and H
7. Groove Connector: GPIO F and E
8. Groove Connector: i2c-1
9. Volume Down Button. Fastboot Button
10. Power Button
11. On-Board Analog Microphone 1
12. 3.5mm Analog Audio Out and Mic In
13. Micro-USB for UART, Connected to UART1
14. ..Standard 96Boards Low Speed Header
15. 2.5mm pin spacing I/O expansion connector level shifted to 3.3/5V via SW2
16. 16 P8 96Boards HS connector
17. On-Board Digital Microphone 2

## 1.2 Hardware Requirements
1. 1x Audio Mezzanine
2. 1x DragonBoard 410c
3. 1x Mouse and Keyboard
4. 1x HDMI Display
5. 1x 12v 2A Power Supply

## 1.3 Hardware Setup
1. Make sure the DragonBoard 410c is powered down, and the power connector is unplugged.
2. Carefully line up the Low-Speed and High-Speed Headers
3. Press firmly and make sure that the connectors are correctly lined up and make good contact.

# 2 Software Setup
1. Latest Build of Debian for Dragonboard 410c
https://www.96boards.org/documentation/ConsumerEdition/DragonBoard-410c/Installation/

2. Update the Debian Installation
```shell
$ sudo apt update
$ sudo apt dist-upgrade
```
