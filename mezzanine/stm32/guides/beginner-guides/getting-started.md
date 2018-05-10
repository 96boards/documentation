---
title: STM32 Sensor Mezzanine Getting Started Guides
permalink: /documentation/mezzanine/stm32/guides/beginner-guides/getting-started.md.html
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
<img src="https://raw.githubusercontent.com/96boards/documentation/master/mezzanine/stm32/images/stm32-front-labeled.png?raw=true" data-canonical-src="https://raw.githubusercontent.com/96boards/documentation/master/mezzanine/stm32/images/stm32-front-labeled.png?raw=true" width="330" height="215" />

<img src="https://raw.githubusercontent.com/96boards/documentation/master/mezzanine/stm32/images/stm32-back-labeled.png?raw=true" data-canonical-src="https://raw.githubusercontent.com/96boards/documentation/master/mezzanine/stm32/images/stm32-back-labeled.png?raw=true" width="330" height="215" />

## 1.2 Hardware Requirements
1. 1x Audio Mezzanine
2. 1x Consumer Edition 96Boards
3. 1x Mouse and Keyboard
4. 1x HDMI Display
5. 1x 12v 2A Power Supply

## 1.3 Hardware Setup
1. Make sure board is powered down, and the power connector is unplugged.
2. Carefully line up the Low-Speed and High-Speed Headers
3. Press firmly and make sure that the connectors are correctly lined up and make good contact.
4. Power on the board and you should see three LEDs will start to blink alternatively

# 2 Software Setup
1. Latest Build of Debian for Dragonboard 410c
https://www.96boards.org/documentation/consumer/dragonboard410c/installation/

2. Update the Debian Installation
```shell
$ sudo apt update
$ sudo apt dist-upgrade
```
3. Make sure you are connected to the internet
