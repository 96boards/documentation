---
title: Documentation for 96Boards UART Serial Adapter
permalink: /documentation/mezzanine/uartserial/
redirect_from: /documentation/mezzanine/uartserial/README.md/
---
## 96Boards UART Serial Adapter

# Table of Contents
- [1) Introduction](#1-introduction)
  - [1.1) About the 96Boards UART Serial Mezzanine](#11-about-the-96boards-uart-serial-mezzanine)
  - [1.2) Specifications & Features](#12-specifications-and-features)
- [2) Guides and Documentation](#2-guides-and-documentation)

# 1) Introduction
## 1.1) About the 96Boards UART Serial Mezzanine

The [96Boards UART Serial Mezzanine](https://www.96boards.org/product/uartserial/) is a USB to UART interface to be used with any base board compatible with the 96Boards Consumer Edition or Enterprise Edition specifications.

It makes it easy to connect your PC to the serial console on the 96Boards low-speed expansion connector, without worrying about pinout or level shifting for 1.8V IO. It also provides remote control of the power button and reset signals so that the base board can be completely controlled over a single USB cable.


<img src="https://www.96boards.org/product/mezzanine/uartserial/images/96boards-uarts-seed4-crop.jpg?raw=true" data-canonical-src="https://www.96boards.org/product/mezzanine/uartserial/images/96boards-uarts-seed4-crop.jpg?raw=true" width="330" height="215" />

## 1.2) Specifications and Features

**Features**
 - Attaches to 96Boards LS expansion connector
 - FT230X USB to UART adapter chip
 - USB bus powered. Doesn’t disconnect when base board power is cycled
 - Switchable between LS UART0 and UART1. UART1 is the default console
 - CTS/RTS when using UART0
 - TX and RX LEDs
 - Remote control of baseboard reset and power signals
 - Base board reset button
 - TX and RX LEDs
 - User LED connected to GPIOB (GPIOA on v1.0 of the adapter)

# 2) Guides and Documentation
  - [Usefule Guides](guides/)
