# Installation

This guide will help you choose and install an operating system on your DragonBoard 410c. Please keep in mind, not all DragonBoard 410c are shipped with the same stock operating system. **The standard operating system for this board is Android**, though the availability of DragonBoard 410c kits will allow boards to ship with the an operating system to best complement the kit.

To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow flashing instructions

***

## Methods of Installation

In most cases, you will be presented with two options when installing your new operating system onto your DragonBoard 410c:

- SD Card Method
- Fastboot Method

Each method has it's own benifits, and requires different levels of experience

### SD Card Method

The SD card method allows you to place a microSD card into a DragonBoard™ 410c to automatically boot and install an operating system onto the eMMC of your board. This method is generally simpler than other methods and should be used by beginners.

This method requires the following hardware:

- DragonBoard 410c with power supply
- Host machine (Linux, Mac OS X, or Windows)
- MicroSD card with 4GB or more of storage
- USB Mouse and/or keyboard
- HDMI Monitor with full size HDMI cable

Go to the [Downloads page](../Downloads/README.md) to get your SD card image.

Choose host machine

- [Linux](LinuxSD.md)
- [Mac](MacSD.md)
- [Windows](WindowsSD.md)

***

### Fastboot Method

Fastboot is supported by the board and can be used for installs. This is for advanced users who are most likely modifying/customizing source code and will need to download such updates to the board for test/execution.

This method requires the following hardware:

- DragonBoard 410c with power supply
- Host machine (Linux, Mac OS X, or Windows)
- USB to microUSB cable
- USB Mouse and/or keyboard (not required to perform flash)
- HDMI Monitor with full size HDMI cable (not required to perform flash)

Go to the [Downloads page](../Downloads/README.md) to get your bootloader, boot image, and root file system image (rootfs).

Choose host machine

- [Linux](LinuxFastboot.md)

***

