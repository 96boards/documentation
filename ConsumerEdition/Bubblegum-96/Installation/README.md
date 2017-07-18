---
title: Installation for Bubblegum-96
permalink: /documentation/ConsumerEdition/Bubblegum-96/Installation/
redirect_from: /documentation/ConsumerEdition/Bubblegum-96/Installation/README.md/
---
# Installation

This guide will help you choose and install an operating system on your Bubblegum-96.

To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow flashing instructions

***

## Methods of Installation

In most cases, you will be presented with two options when installing your new operating system onto your Bubblegum-96:

- SD Card Method
- Fastboot Method

Each method has it's own benifits, and requires different levels of experience

### SD Card Method

The SD card method allows you to place a microSD card into a Bubblegum-96 to automatically boot and install an operating system onto the eMMC of your board. This method is generally simpler than other methods and should be used by beginners.

This method requires the following hardware:

- Bubblegum-96 with power supply
- Host machine (Linux Host)
- MicroSD card with 4GB or more of storage

Go to the [Downloads page](../Downloads/) to get your SD card image.

Choose Host machine

- [Linux](LinuxSD.md)

***

### Fastboot Method

Fastboot is supported by the board and can be used for installs. This is for advanced users who are most likely modifying/customizing source code and will need to download such updates to the board for test/execution.

This method requires the following hardware:

- Bubblegum-96 with power supply
- Host machine (Ubuntu/Debian system  with kernel version > 3.16.0)
- USB cable Type-A to Type-A
- USB to microUSB cable
- Serial console with converter board (Recommended to use [Serial Console Mezzanine](../../../MezzanineProducts/96Boards%20UART%20Serial%20Adapter/))
- USB Thumb drive
- USB Mouse and/or keyboard (not required to perform flash)
- HDMI Monitor with full size HDMI cable (not required to perform flash)

Go to the [Downloads page](../Downloads/) to get your bootloader, boot image, and root file system image (rootfs).

Choose host machine

- [Linux](LinuxFastboot.md)

***
