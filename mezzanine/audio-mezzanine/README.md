---
title: Documentation for Audio Mezzanine
permalink: /documentation/mezzanine/audio-mezzanine/
redirect_from: /documentation/mezzanine/audio-mezzanine/README.md/
---
## Audio Mezzanine for 96Boards

# Table of Contents
- [1) Introduction](#1-introduction)
  - [1.1) About the 96Boards Audio Mezzanine](#11-about-the-96bBoards-audio-mezzanine)
  - [1.2) Specifications](#12-specifications)
  - [1.3) Features](#13-features)
- [2) Useful Guides](#2-useful-guides)

# 1) Introduction
## 1.1) About the 96Boards Audio Mezzanine

This [Audio Mezzanine Board](https://www.96boards.org/products/mezzanine/sensors-mezzanine/) is a Grove interfaced expansion board intended for 96boards. You can connect 96Boards to various modules easily with this expansion board. There are six grove ports which can be used to connect rich Grove functional modules, which will make your application more complicated and attracting. In addition, this expansion board gets one 3.5 mm audio port and two independent microphones which can be applied into multimedia processing. Since 96Boards I/O voltage is set at 1.8 V, so it cannot be connected directly to embedded world. This expansion board has used voltage converting circuit so that you can choose 3.3V/5V as the output voltage. Other features are also embedded on this expansion board such as USB to Serial circuit and reset button, and so on, all those make 96Boards more conveniently to build applications.


<img src="https://www.96boards.org/product/mezzanine/audio-mezzanine/images/audio-mezzanine.png?raw=true" data-canonical-src="https://www.96boards.org/product/mezzanine/audio-mezzanine/images/audio-mezzanine.png?raw=true" width="330" height="215" />

## 1.2) Specifications
- Input Voltage: 6.5~18V(DC Input)
- Operating Voltage: 1.8/3.3/5V
- No-load Current: 30mA
- Dimension: 85x54mm
- Weight: 28g
- Location hole diameter: 2.5mm

## 1.3) Features
- 6 x On-board Grove connector
  - 2x I2C
  - 1x UART
  - 3x GPIO
- USB to UART conversion for access to the 410c system console.
- Access to the Analog Audio on the 410c board
  - 3.5mm headset jack
  - Analog Mic
  - Digital Mic
  - Speaker connection
- Access to the low-speed expansion connector
  - Level shifted to 3.3V or 5V levels (selection switch)
  - Access to level shifted signals on 2.54mm (0.1”) 40-pin connector for ease of connectivity
  - Switch to disable level shifters for pass-through applications
  - Signals available at 1.8V levels on 2mm connector
- Power and Reset/Volume down buttons
- Pass through stacking connectors so that other Mezzanine cards may be stacked on top of the Audio Mezzanine.

# 2) [Useful Guides](Guides/)
