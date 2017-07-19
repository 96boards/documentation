---
title: Getting Started with Carbon
permalink: /documentation/IoTEdition/carbon/getting-started/
redirect_from:
- /documentation/IoTEdition/carbon/getting-started/README.md/
---
# Getting Started

Learn about your Carbon board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Carbon](http://www.96boards.org/product/carbon/)
   - Board based on the STM32F401RE Processor connected to a nRF51822 bluetooth controller
- USB to MicroUSB cable (x2)
   - This is needed for serial console interface and USB-OTG (including DFU support)
- Switches
   - Two switches are provided: RST to reset the STM32F401 chip, BOOT0 to enter the STM32F4 bootloader
- Pin headers (unpopulated)
   - Tx/Rx UART for STM32F4 chip
   - 5-pin SWD interface to STM32F4 chip
   - BOOT0 and BOOT1 lines exposed
   - 5-pin SWD interface to nRF51 chip

**Optional**
- Mezzanine Products
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components

***

# Out of the Box

The following subsections should describe how to get started with the Carbon using the release build shipped with the boards. The Carbon board is ready to use “out of the box” with a preinstalled version of the Zephyr RTOS.

<img src="https://github.com/sdrobertw/documentation/blob/master/IoTEdition/carbon/additional-docs/images/images-board/carbon-front-sd.png?raw=true" data-canonical-src="https://github.com/sdrobertw/documentation/blob/master/IoTEdition/carbon/additional-docs/images/images-board/carbon-front-sd.png?raw=true" width="300" height="150" />
<img src="https://github.com/sdrobertw/documentation/blob/master/IoTEdition/carbon/additional-docs/images/images-board/carbon-front-sd.png?raw=true" data-canonical-src="https://github.com/sdrobertw/documentation/blob/master/IoTEdition/carbon/additional-docs/images/images-board/carbon-back-sd.png?raw=true" width="300" height="150" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:-------------------------------------------------------------------------------------------------|
|  SoC                 | STMicroelectronics STM32F401RE                                                                   |
|  CPU                 | Cortex-M4                                                                                        |
|  Clock speed         | 84MHz maximum                                                                                    |
|  SRAM                | 96KB                                                                                             |
|  Storage             | 512KB onboard Flash                                                                              |
|  Wireless            | nRF51822 Bluetooth                                                                               |
|  USB                 | 2 x Micro USB                                                                                    |
|  Expansion Interface | 30 pin low speed expansion connector: +3.3V, +5V, VCC, GND, UART, I2C, SPI, GPIO x4              |
|  Digital Out Voltage | 3.3V                                                                                             |
|  Analog In Voltage   | 0-3.3V                                                                                           |
|  Analog Pins         | 6                                                                                                |
|  LED                 | 1 x UART Tx, 1 x UART Rx, 1 x Power, 1 x Bluetooth, 2 x User LEDs                                |
|  Button              | RST (Reset the STM32F4), BOOT0 (Boot into bootloader for flashing)                               |
|  Power Source        | micro-USB                                                                                        |
|  OS Support          | Zephyr                                                                                           |
|  Size                | 60x30mm                                                                                          |

**IMPORTANT NOTES**

- Flashing the nRF51 chip requires a SWD programmer such as a ST-Linkv2 or Segger JLink

***

## Starting the board for the first time

**The Carbon comes preloaded with Zephyr on the STM32F4 and nRF51822 chips and can be up and running with a few simple steps:**

- Connect the micro-USB cable to supply power to the Carbon. The board will begin to boot Zephyr immediately. You can use either of the micro-USB ports to power the Carbon.

***

## Learn to build and flash applications to your Carbon Board

It's time to see what your Carbon can do. From here you can learn how to build your own applications, or flash some of our pre-built ones, available on the Downloads page:

- [Downloads page](../downloads/): This page contains prebuilt OS and Application files, simply download and flash to get started!
- [Building for Carbon](../build/): In a few simple steps, here you will learn how to build and flash your own application to the Carbon.
- [Installation page](../installation/): Find instructions on how to flash new applications to your Carbon!
- [Troubleshooting](../troubleshooting/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [Carbon documentation home page](../)

***   
