---
title: Useful Guides for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/guides/
redirect_from:
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/README.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/
- /documentation/consumer/dragonboard410c/guides/README.md/
- /db410c-getting-started/Guides/README.md/
---
# Useful Guides

These guides will help to get you started with a variety of available on-boards software

## Debian

Linux User Guide ([View](https://github.com/96boards/documentation/blob/master/consumer/dragonboard410c/guides/LinuxUserGuide_DragonBoard.pdf) / [Download](https://github.com/96boards/documentation/raw/master/consumer/dragonboard410c/guides/LinuxUserGuide_DragonBoard.pdf)) | This guide hosts a variety of basic setup instructions sets. From getting your board booted up for the fir
st time to swapping out your OS

| Guide                                                            | Descripion                                                                                                                 |
|:----------------------------------------------------------------:|:---------------------------------------------------------------------------------------------------------------------------|
| [Terminal](Terminal.md)                                          | Learn the  basics, how to access your terminal & getting started with basic commands. Includes links to external resources |
| [General Purpose Input / Output](../../guides/gpio.md)           | This all extensive I/O guide bridges across all 96Boards consumer edition boards.                                          |
| [Force display resolution and bypass EDID](ForceDisplayRes.md)   | Learn how to force a diplay resolution                                                                                     |
| [Enabling SPI on Dragonboard 410c with SPIDEV](EnableSPI.md)     | Learn to enable SPI using SPIDEV                                                                                           |
| [Create custom GPT](GPT.md)                                      | Learn to create a custom GUID Partition table                                                                              |
| [UART Serial Console Access](uart-serial-console.md)             | This guide will walk you through gaining access to the Serial Console available through on board UART                      |
| [LEDs and Connectors](led-connectors.md)                         | Basic walkthrough of the onboard LEDs and connectors                                                                       |
| [Using USB](using-usb.md)                                        | An in depth look at the onboard USB connectors and how to use them                                                         |
| [Device Tree Overlay](dt-overlays.md)                            | Shows how to load device tree overlays using configfs                                                                      |
| [Linux SD boot using U-Boot](uboot-linux-sd.md)                  | Shows how to boot Linux from SD card using u-boot                                                                          |
| [Create a Bootable SD Card](bootable-sd-card.md)                 | Shows how to boot Linux from SD card without using u-boot                                                                  |
| [OV5645 Camera Module Guide](CameraModule.md)                    | A guide on how to use the OV5645 camera module                                                                             |
| [Customize EMMC Partition](customize-emmc-partition.md)          | A guide on customizing the emmc partition table                                                                            |
| [Enable DMIC Support](enable-dmic.md)                            | Instruction to enable DMIC(Digital MICrophone)                                                                             |
| [Enable SPI Ethernet Controller](EnableSPIEthernetController.md) | Instructions to connect and enable SPI Ethernet Controllers                                                                |
| [Running LAVA Tests](Testing.md)                                 | How to utilize the Linaro test suite on Dragonboard 410c                                                                   |

## Android

- Android User Guide ([View](https://github.com/96boards/documentation/blob/master/consumer/dragonboard410c/guides/AndroidUserGuide_DragonBoard.pdf) / [Download](https://github.com/96boards/documentation/raw/master/consumer/dragonboard410c/guides/AndroidUserGuide_DragonBoard.pdf))

| Guide                                                          | Descripion                                                                                                                 |
|:--------------------------------------------------------------:|:---------------------------------------------------------------------------------------------------------------------------|
|[AOSP](AOSP.md)                                                 |  It is possible to build AOSP for the Dragonboard 410c. Please note, this is experimental work.                            |
