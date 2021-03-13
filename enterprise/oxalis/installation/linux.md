---
title: Oxalis Linux Installation
permalink: /documentation/enterprise/oxalis/installation/linux.md.html
---
# Installation

### 1) Hardware Requirement
- Oxalis board
- LS1012A SoM mounted onto the Oxalis
- 12V / 3A DC power supply
- Micro-USB cable
- USB Stick or MicroSD-Card
- A Windows, Linux or Mac computer with your favorite terminal software

### 2) Enter U-Boot
- Connect your computer to the Micro-USB port (X7) of the Oxalis via the Micro-USB cable.
- Start a terminal software on your computer (e.g. putty or minicom) with following settings
  - BAUDRATE 115200
  - 8-N-1 (8 data bits - no parity bit - one stop bit)
- Connect the Oxalis to the 12 Volt Power supply and switch it on
- Watch the LED next to the MicroUSB Connector X7
  - During a data transmission, this LED flashes.
- On your terminal program you see the Oxalis going through the boot process
- By default, Oxalis will stop at the u-boot prompt.

### 3) Prepare Storage medium
Use your PC to prepare the storage medium as described below:
- Format the storage medium (SD-Card or USB-Memory-Stick) with `Fat32` filesystem.
- Download the prebuilt image from [Downloads page](../downloads/linux.md).
- Copy and rename the downloaded `kernel_stable_xxxxxxxx.itb` image to `kernel.itb` and place it in the root folder of the storage medium.
- Ensure that the image has been fully written. Use Safe remove on Windows and the `sync` command on the linux console.

Now you have a bootable Linux storage medium.

### 4) Load the Linux image into Oxalis’s RAM
- Power down your Oxalis
- Insert the medium in the appropriate slot
- Enter U-Boot as stated above in step 2.
- Load the Kernel ramdisk into RAM:
  - SDard: `fatload mmc 0 0x96000000 kernel.itb`
  - USB Stick: `usb start; fatload usb 0 0x96000000 kernel.itb`

### 5) Boot Linux From RAM
If the loading was successful, you can now boot directly with following commands: `pfe stop; bootm 0x96000000`

- Now linux boots the minimal ramdisk environment and the login prompt will appear.
- Login with `root` and press enter. No password is required.
> Note: Why the `pfe stop` command? The packet forwarding engine (PFE) is part of the hardware
accelerated Ethernet subsystem of the LS1012A. It needs to be shut down before Kernel boot,
so the Kernel code can reinitialize PFE for itself.

### 6) Transfer Linux image from RAM to Flash and Configure Auto Boot

If your `kernel.itb` image size is less than 50MB you can set up autobooting on the Oxalis, without any external
storage devices necessary. This is possible by writing the image to Oxalis’s onboard flash
memory and configure U-Boot to automatically load the image from there and boot it.

- Press the reset button and Load Linux into RAM as shown in step 4. But DO NOT boot Linux yet.
- Flash it to the on-board QSPI flash memory using `sf probe; sf write 0x500000 0x96000000 $filesize`
- Set boot command environment variable:
  - ```setenv bootcmd “run oxalissettings; run ramargs; pfe stop; sf probe; sf read 0x96000000 0x500000 $filesize; bootm 0x96000000”s```
  - ```saveenv```

Press the reset button and watch Oxalis autobooting.

> Note: The default downloaded image will not fit into QSPI flash memory.
