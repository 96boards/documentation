---
title: Installation for Developerbox
permalink: /documentation/enterprise/developerbox/installation/
---
# Table of Contents

   * [Installation Overview](#installation-overview)
   * [Booting an operating system installer](#booting-an-operating-system-installer)
	   * [Download necessary installation image](#download-necessary-installation-image)
	   * [Create installation USB stick](#create-installation-usb-stick)
	   * [Boot into the installer and install OS](#boot-into-the-installer-and-install-os)
   * [System firmware update](#system-firmware-update)
	   * [Download necessary installation image](#download-necessary-installation-image)
	   * [Perform a capsule update](#perform-a-capsule-update)
   
# Installation Overview

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

The Developerbox comes pre-installed with system firmware (based on 
Trusted Firmware and EDK2) but without an operating system installed.
This section provides links to the latest software downloads for
Developerbox.  

### Linaro supported operating systems based on Debian

 * [Enterprise Reference Platform, based on Debian](../downloads/debian.md)

 

### Third Party Operating Systems

Other operating systems with support for Developerbox.

 * [CentOS 7 and later](../installation/centos.md)
 * [Debian 9 and later](../installation/debian.md)
 * [Red Hat Enterprise Linux 7 and later](../installation/rhel.md)
 * [Ubuntu 18.04 and later](../installation/ubuntu.md)



## Create installation USB stick

Choose host machine to create the USB stick from:

- [GNU/Linux (including other Developerbox)](linux-usb.md)
- [Mac](mac-usb.md)
- [Windows](windows-usb.md)

## Boot into the installer and install OS

 1. Insert the USB stick to any of the USB sockets
 2. Turn on or reboot your Developerbox
 3. When the splash screen appears press **Escape**.
 4. Choose **Boot Manager**
 5. From the boot options in the Boot Manager Menu, choose your USB
    device to start the installer.

**Note: Some operating systems may require workarounds to fix known installation problems. See the links under Third Party Operating Systems section for more detailed information or, if your OS not listed, the [Known Issues](../support/known-issues.html) for more details.**

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

Linaro supported System Firmware:

Go to the [EDK2 downloads page](../downloads/edk2.md) and get the System
Firmware Capsule.

## Perform a capsule update

Run the following commands on your Developerbox:

~~~
sudo apt install fwupdate
sudo fwupdate --apply {50b94ce5-8b63-4849-8af4-ea479356f0e3} DeveloperBox.Cap
sudo reboot
~~~

During the reboot process EDK2 will apply the update and then reboot
as normal.
