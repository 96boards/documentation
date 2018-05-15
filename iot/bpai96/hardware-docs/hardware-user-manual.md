---
title: BPai96 User Manual
permalink: /documentation/iot/bpai96/hardware-user-manual.html
---

# BPai96 Hardware User Manual

### Table of Contents

- [Introduction](#introduction)
- [Specifications](#specification)
- [Hardware Overview](#hardware-overview)
- [Pinout Map](#pinout-map)


# Introduction

BPI NB-IoT with BC95 module development board is the first Banana Pi board for 96Board IoT Specification.

# 2) Specification

**General Board Specification**

|   Component          |   Description                               |
|:---------------------|:--------------------------------------------|
|  SoC                 | STM32F103RCT6 / STM32F103RBT6               |
|  CPU                 | ARM 32-bit CortexTM-M3                      |
|  Clock speed         | 72 MHz                                      |
|  SDRAM               | 48KB / 20 KB                                |
|  Storage             | 256KB / 128KB                               |
|  Wireless            | Quectel BC95-B5/8/20 or BC95-G              |
|  Expansion Interface | 40pin GPIO                                  |
|  Digital Out Voltage | 1.8v                                        |
|  OS Support          | LiteOS                                      |
|  Power               | 5V/2A via MicroUSB / 2PIN Battery Connector |

**NB-IoT Module Specification**

|   Component  |   Description                                   |
|:-------------|:------------------------------------------------|
|  Module      | Quectel BC95-B5/8/20 or BC95-G                  |
|  SIM         | Micro SD SIM Slot                               |
|  e-SIM       | e-SIM optional(footprint reserved on the board) |
|  Antenna     | IPEX antenna connector                          |
|  Frequency:  |                                                 |
|  BC95-B20    | 800MHz                                          |
|  BC95-B5     | 850MHz                                          |
|  BC95-B8     | 900MHz                                          |
|  BC95-G      | B1/B3/B5/B8/B20/B28 @FDD-LTE (TBD)              |

# Hardware Overview

| Component             |  Description                                                                                                           |
|:---------------------:|:----------------------------------------------------------------------------------------------------------------------:|
| Low-Level Peripherals | 40 Pins Header (2.0mm Pitch), 32×GPIOs, Some of which can be used for specific functions including UART, I2C, SPI, PWM |
| On board Network      | Quectel BC95                                                                                                           |
| On board SIM          | MicroSD SIM Slot eSIM(optional)                                                                                        |
| USB                   | 1 USB 2.0 host                                                                                                         |
| LEDs                  | 1 Power status Led and 5 User LEDs                                                                                     |
| Dimensions            | 60 mm × 30mm                                                                                                           |
| Weight                | 10g                                                                                                                    |

# Pinout Map

**BPI-BC95 40PIN GPIO (CON1)**

| GPIO Pin Name | Default Function | Secondary Function |
|:-------------:|:----------------:|:------------------:|
| CON1-P01      | GND              | GND                |
| CON1-P02      | GND              | GND                |
| CON1-P03      | MCU_USART2_RTS   | PA1                |
| CON1-P04      | GPIO_PC6         | PC6                |
| CON1-P05      | MCU_USART2_RX    | PA3                |
| CON1-P06      | RST_BTN          | RST_BTN            |
| CON1-P07      | MCU_USART2_TX    | PA2                |
| CON1-P08      | SPI1_SCK         | PA5                |
| CON1-P09      | MCU_USART2_CTS   | PA0                |
| CON1-P10      | SPI1_MISO        | PA6                |
| CON1-P11      | GPIO_PB8         | PB8                |
| CON1-P12      | SPI1_NSS         | PA4                |
| CON1-P13      | GPIO_PB9         | PB9                |
| CON1-P14      | SPI1_MOSI        | PA7                |
| CON1-P15      | I2C1_SCL         | PB6                |
| CON1-P16      | GPIO_PC13        | PC13               |
| CON1-P17      | I2C1_SDA         | PB7                |
| CON1-P18      | GPIO_PA15        | PA15               |
| CON1-P19      | I2C2_SCL         | PB10               |
| CON1-P20      | GPIO_PB0         | PB0                |
| CON1-P21      | I2C2_SDA         | PB11               |
| CON1-P22      | GPIO_PB1         | PB1                |
| CON1-P23      | USART1_CK        | PB5                |
| CON1-P24      | SPI2_NSS         | PB12               |
| CON1-P25      | USART1_TX        | PA9                |
| CON1-P26      | SPI2_SCK         | PB13               |
| CON1-P27      | USART1_RX        | PA10               |
| CON1-P28      | SPI2_MISO        | PB14               |
| CON1-P29      | USART5_CK        | PB5                |
| CON1-P30      | SPI2_MOSI        | PB15               |
| CON1-P31      | USART5_TX        | PB3                |
| CON1-P32      | USART4_RX        | PB11               |
| CON1-P33      | USART5_RX        | PB4                |
| CON1-P34      | USART4_TX        | PB10               |
| CON1-P35      | VCC_1v8          | VCC_1v8            |
| CON1-P36      | NC               | NC                 |
| CON1-P37      | VCC_5v           | VCC_5v             |
| CON1-P38      | NC               | NC                 |
| CON1-P39      | GND              | GND                |
| CON1-P40      | GND              | GND                |

**SWD (CN1)**

| GPIO Pin Name | Default Function | Secondary Function |
|:-------------:|:----------------:|:------------------:|
| CN1-P1        | VCC              | VCC                |
| CN1-P2        | GND              | GND                |
| CN1-P3        | SWCLK            | PA14               |
| CN1-P4        | SWDIO            | PA13               |
| CN1-P5        | RESET-ST         | RESET-ST           |

**DEBUG UART (CON2)**

| GPIO Pin Name | Default Function | Secondary Function |
|:-------------:|:----------------:|:------------------:|
| CON2-P01      | GND              | GND                |
| CON2-P02      | USART1_RX        | PA9                |
| CON2-P03      | USART1_TX        | PA10               |
