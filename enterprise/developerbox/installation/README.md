---
title: Installation for Developerbox
permalink: /documentation/enterprise/developerbox/installation/
redirect_from:

---
# Installation

This guide will help you update your system firmware or boot an
operating system installer on your Developerbox.

To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow instructions

***

## System Firmware Update

Updating the system firmware requires no additional hardware, although
you must have some means of interacting with your Developerbox
(keyboard+monitor, UART, network). All commands must be run on the 
Developerbox so you must have an operating system installed.

Note: *If the board non-functioning and you are unable to install an operating system, try the [board recovery](board-recovery.md) instructions instead.*

### Download necessary installation image

Go to the [Downloads page](../downloads/edk2.md) and get the System
Firmware Capsule.

### Perform a capsule update

Run the following commands on your Developerbox:

~~~
sudo apt install fwupdate
sudo fwupdate --apply {50b94ce5-8b63-4849-8af4-ea479356f0e3} DeveloperBox.Cap
sudo reboot
~~~

During the reboot process EDK II will apply the update and then reboot
as normal.

***

## Booting an operating system installer

Booting an operating system installer requires:

- Developerbox
- USB stick large enough to hold the downloaded image
- USB mouse+keyboard and monitor
  UART
 
### Download necessary installation image

Go to the [Downloads page](../downloads/README.md) to get an ISO image
for your operating system.

### Create Installation USB stick

Choose host machine to perform installation from:

- [GNU/Linux](linux-usb.md)
- Mac - Coming soon...
- Windows - Coming soon...

***
