---
title: Installation for ROCK960
permalink: /documentation/consumer/rock/installation/
redirect_from: /documentation/consumer/rock960/installation/
---
# Installation

Choose and install an operating system on your ROCK960. To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow flashing instructions

***

## Methods of Installation

In most cases, you will be presented with two options when installing your new operating system onto your ROCK960:

- eMMC USB upgrade Method
    - The firmware will be downloaded from the USB to the ROCK960 on board eMMC storage
- Running on SD Card Method
    - The firmware will be written on a SD Card and insert on ROCK960 to run.

Each method has it's own benifits, and requires different levels of experience

### eMMC USB upgrade Method

[Rockusb](http://opensource.rock-chips.com/wiki_Rockusb) is a custom USB protocal from Rockchip supported by ROCK960 and can be used for firmware installation(USB to eMMC). This is for advanced users who are most likely familiar with command line tool or modifying/customizing source code and will need to download such updates to the board for test/execution.

This method requires the following hardware:

- ROCK960 with power supply
- Host machine (Linux/Mac)
- USB type C to type A cable
- USB serial to TTL cable(not required to perform flash)
- USB Mouse and/or keyboard (not required to perform flash)
- HDMI Monitor with full size HDMI cable (not required to perform flash)

Go to the [Downloads page](../downloads) to get your bootloader, boot image, and root file system image (rootfs).

Choose host machine

- [Linux/macOS](linux-mac-rkdeveloptool.md)

***

### Running on SD Card Method

The SD card method allows you to place a microSD card into a ROCK960 to automatically boot and run. It will not affect your on board eMMC storage unless you intend to write the eMMC after booting up the SD card OS. This method is generally simpler than other methods and should be used by beginners.

This method requires the following hardware:

- ROCK960 with power supply
- Host machine (Linux, Mac OS X, or Windows)
- MicroSD card with 4GB or more of storage
- USB Mouse and/or keyboard
- HDMI Monitor with full size HDMI cable

Go to the [Downloads page](../downloads) to get your SD card image.

Choose host machine

- [Linux](linux-sd.md)
- [Mac](mac-sd.md)
- [Windows](windows-sd.md)

***
