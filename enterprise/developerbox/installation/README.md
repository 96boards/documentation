---
title: Installation for Developerbox
permalink: /documentation/enterprise/developerbox/installation/
redirect_from:

---

# Installation

This guide will help you boot an operating system installer or
update the system firmware on your Developerbox.

To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine

***

# Booting an operating system installer

Booting an operating system installer requires:

- Developerbox
- USB stick large enough to hold the downloaded image
- Keyboard and monitor

Note: *As an alternative to a keyboard and monitor is it possible
      to remove the graphics card and to manage the install from another
      computer using the USB serial port behind the I/O panel instead. If the menus do
      not show correctly on the serial port try using screen or
      picocom instead of minicom and ensure the terminal emulator
      window is at least 80x25 characters.*

## Download necessary installation image

Go to the [Downloads page](../downloads/README.md) or to the website
of your chosen operating system to get an ISO image for the installer.

## Create installation USB stick

Choose host machine to perform installation from:

- [GNU/Linux](linux-usb.md)
- Mac - Coming soon...
- Windows - Coming soon...

## Boot into the installer

 1. Insert the USB stick to any of the USB sockets
 2. Turn on or reboot your Developerbox
 3. When the splash screen appears press **Escape**.
 4. Choose **Boot Manager**
 5. From the boot options in the Boot Manager Menu, choose your USB
    device to start the installer.

***

# System firmware update

Updating the system firmware requires no additional hardware, although
you must have some means of interacting with your Developerbox
(keyboard+monitor, UART, SSH). All commands must be run on the 
Developerbox from GNU/Linux shell, so you must have an operating
system installed to update the firmware.

Note: *If the board non-functioning and you are unable to run an
      operating system, try the [board recovery](board-recovery.md)
      instructions instead.*

## Download necessary installation image

Go to the [Downloads page](../downloads/edk2.md) and get the System
Firmware Capsule.

## Perform a capsule update

Run the following commands on your Developerbox:

~~~
sudo apt install fwupdate
sudo fwupdate --apply {50b94ce5-8b63-4849-8af4-ea479356f0e3} DeveloperBox.Cap
sudo reboot
~~~

During the reboot process EDK II will apply the update and then reboot
as normal.
