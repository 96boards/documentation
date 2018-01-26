---
title: Installation for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/installation/
redirect_from:
- /documentation/ConsumerEdition/DragonBoard-410c/Installation/README.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Installation/
- /documentation/consumer/dragonboard410c/installation/README.md/
- /db410c-getting-started/Installation/README.md/
---
# Installation

Stand alone DragonBoard 410c will ship with the Android image. If the DragonBoard 410c is purchased as part of a kit, it may have a different pre-loaded operating system.

This guide will help you choose and install an operating system and installation method on your DragonBoard 410c.

To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow flashing instructions

***

## Methods of Installation

In most cases, you will be presented with two options when installing your new operating system onto your DragonBoard 410c:

- SD Card Method - Install and boot from eMMC
- SD Card Method - Install and boot from SD Card
- Fastboot Method

Each method has it's own benifits, and requires different levels of experience

### SD Card Method - Install and boot from eMMC

The SD card method allows you to place a microSD card into a DragonBoard™ 410c to automatically boot and install an operating system onto the eMMC of your board. This method is generally simpler than other methods and should be used by beginners.

This method requires the following hardware:

- DragonBoard 410c with power supply
- Host machine (Linux, Mac OS X, or Windows)
- MicroSD card with 4GB or more of storage
- USB Mouse and/or keyboard
- HDMI Monitor with full size HDMI cable

#### Download necessary installation image
Go to the [Downloads page](../downloads/README.md) to get the Debian SD card image.

#### Create Installation SD Card
Choose host machine to perform installation from:

- [Linux](linux-sd.md)
- [Mac](mac-sd.md)
- [Windows](windows-sd.md)

***

### SD Card Method - Install and boot from SD Card
It is possible to place your entire DragonBoard 410c file system onto a bootable SD Card.  The advantages of doing this may include some or all of the following:

- Instead of being limited to 8GB of internal eMMC for your internal block storage, the user could put a 64GB SDCard(for example) into the system and have that much space for block storage and application installations
- With the entire Root File System on the SD card, the user can now remove the card and move it to another DragonBoard 410c for test purposes
- An additional benefit is the ability to back up the SD Card, thus saving everything on your system down to state (like command history, installed packages, and installed build environments, for example).

A disadvantage may be performance depending upon the application. Access times on the SD Card are slower than the internal eMMC.

Note that this installation option only installs a "developer image," i.e. command line only with no desktop installed.  A user would have to install a desktop post-install if that is desired.

This method requires the following hardware:

- Host machine (Linux, Mac OS X, or Windows)
- MicroSD card with 4GB or more of storage.  A very large MicroSD card is recommended (64GB was used to verify the functionality herein)
- DragonBoard 410c with power supply
     - USB Mouse and/or keyboard
     - HDMI Monitor with full size HDMI cable

#### Download necessary installation image
Go to the [Downloads page](../downloads/README.md) to get your SD card image.

#### Create Bootable SD Card
Choose host machine to perform installation from:

- [Linux](linux-sd-boot.md)
- Mac - tbd
- Windows - tbd
***

### Fastboot Method

Fastboot is supported by the board and can be used for installs. This is for advanced users who are most likely modifying/customizing source code and will need to download such updates to the board for test/execution.

This method requires the following hardware:

- DragonBoard 410c with power supply
- Host machine (Linux, Mac OS X, or Windows)
- USB to microUSB cable
- USB Mouse and/or keyboard (not required to perform flash)
- HDMI Monitor with full size HDMI cable (not required to perform flash)

Go to the [Downloads page](../downloads/) to get your bootloader, boot image, and root file system image (rootfs).

Choose host machine

- [Linux](linux-fastboot.md)

***
