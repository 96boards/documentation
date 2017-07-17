---
title: Installation for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Installation/
redirect_from: /documentation/ConsumerEdition/HiKey/Installation/README.md/
---
# Installation

Choose and install an operating system on your HiKey. To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow flashing instructions

***

## Methods of Installation

In most cases, you will be presented with one or two options when installing your new operating system onto your HiKey:

- Fastboot Method
- Factory Images Method

Each method has it's own benifits, and requires different levels of experience

***

### Fastboot Method

Fastboot is supported by the board and can be used for installs. This is for advanced users who are most likely modifying/customizing source code and will need to download such updates to the board for test/execution.

This method requires the following hardware:

- HiKey with power supply
- Host machine (Linux, Mac OS X, or Windows)
- USB to microUSB cable
- USB Mouse and/or keyboard (not required to perform flash)
- HDMI Monitor with full size HDMI cable (not required to perform flash)

Go to the [Downloads page](../Downloads/) to get your bootloader, boot image, and root file system image (rootfs).

Choose host machine

- [Linux](LinuxFastboot.md)

***
### Factory Images Method (currently available for AOSP only)

Factory Images are one of the easier way to install a image onto a device, and is reccomended for new users. It is similar to the fastboot method, but all the binary objects and a flashall.sh script are provided in a single zip file, so one doesn't need to make sure they have the right versions of various binary images, nor remember which order might be required to flash images.

This method requires the following hardware:

- HiKey with power supply
- Host machine (Linux, Possibly MacOS?)
- USB to microUSB cable
- HDMI Monitor with full size HDMI cable (not required to perform flash)

Go to the [Downloads page](../Downloads/) to get your Factory Image zip file.

Choose host machine

- [Linux](LinuxFactoryImage.md)

***
