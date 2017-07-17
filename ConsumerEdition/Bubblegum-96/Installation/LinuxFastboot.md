---
title: Linux Fastboot Installation for Bubblegum-96
permalink: /documentation/ConsumerEdition/Bubblegum-96/Installation/LinuxFastboot.md/
---
##Linux Host

This section show how to install a new operating system to your Bubblegum-96 using the fastboot method on a Linux host computer.

***

- **Step 1**: Update Host System
- **Step 2**: Download Dependencies
- **Step 3**: Download, Build, and Install linaro-adfu-tool
- **Step 4**: Download required images
- **Step 5**: Enter adfu mode
- **Step 6**: Access 96board U-boot shell
- **Step 7**: Enter Fastboot mode
- **Step 8**: Flash kernel image
- **Step 9**: Flash the root file system (rootfs)
- **Step 10**: Create bootloader.img and flash using fastboot

***




### **Step 1:** Update Host System

The package list and versions on your host machine could be out of date. It is important to run a few commands prior to moving to the next step.

These commands will help us make sure everything on the host machine is current:

- **apt-get update:** Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade:** Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade:** In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

Note: Must be connected to the internet

```shell
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get dist-upgrade
```

### **Step 2:** Download Dependencies

```shell
$ sudo apt-get install git
$ sudo apt-get install libusb-1.0-0
```

### **Step 3:** Download, Build, and Install linaro-adfu-tool

```shell
$ git clone https://github.com/96boards-bubblegum/linaro-adfu-tool.git
$ cmake .
$ make
$ make install
```

### **Step 4:** Download required images

This Fastboot installation process currently works with the following operating systems:

- Debian ([Download page](../Downloads/Debian.md))

Once you have downloaded the appropriate files, continue to **Step 5**

### **Step 5:** Enter adfu mode

- Make sure bubblegum-96 board is in power off mode
- Plug in the UART debug board and connect serial console to the host PC.
   - Set baud rate to be 115200,
   - Set (8N1) – [8bit data, No-parity, & 1 stop bit].
- Connect the host PC with Bubblegum-96 USB3.0 port via type USB A-A cable.
   - USB3.0 port on Bubblegum96 board is the blue port
   - Tthis cable won’t provide Power, so will notwont boot up the board
- Hold down the ADFU key on the Bubblegum96 board while…

- Plug in power to the Bubblegum96 board.
- Continue to hold down ADFU down the ADFU key for 2-4 seconds after the power has been plugged in
- Release the ADFU key
- Execute `lsusb` on host PC.
   - You will find a device ID 10d6:10d6 if Bubblegum96  board has entered adfu-mode
   - If Bubblegum96 board has not entered ADFU mode,  retry step 1-7

### **Step 6:** Access 96board U-boot shell

_**[Host PC]**_

While Bubblegum96 board is in ADFU mode, execute the following commands in /linaro-adfu-tool/ to access 96board u-boot shell.

`$ sudo linaro-adfu-tool-bg96 u-boot-dtb.img`

**Note:** if you `make install` the ADFU tool described in 2.1.4, you should be able to run linaro-adfu-tool from any path, [it will search firmware from certain path, such as

1. /usr/local/share/linaro-adfu-tool/bg96/firmwares/
2. /usr/share/linaro-adfu-tool/bg96/firmwares/
3. ./firmwares/
4. ../firmwares/

_**[Device (96board)]**_

Before doing anythingeverything, please make sure you have already install the serial console. If not, please install that use the following command.

`$sudo apt-get install minicom`

Run another terminal and

`$sudo minicom -s`

In this case, we need to set the minicom,

```shell
Port: ttyUSB0
Bps/Par/Bits: 115200
Hardware control flow: No
```

While in the ADFU mode, Bubblegum96 board can be confirmed to be in “receiving mode” to accept commands from the Host-PC…  
Please press `Enter` when system bootup, and it will show `“owl>”` prompt on serial console.

### **Step 7:** Enter Fastboot mode

_**[ Device (96board)]**_

Execute `run create_gpt` to reconstruct the gpt table and it will show

`Writing GPT: success!.`

Execute `fastboot  usb` to access fastboot mode.
If the board is in fastboot-mode, you will see a device ID `18d1:0c02` by entering the command `lsusb` on host PC.

### **Step 8:** Flash kernel image

The kernel image of 96board is located at boot.emmc.img

_**[Host PC]**_

Please make sure you have already installed fastboot tool on your PC, if not, run the following command:

`$ sudo apt-get install android-tools-fastboot`

After that, continue flashing Bubblegum-96.

`$ sudo fastboot flash BOOT boot.emmc.img`

**Note:** `boot.emmc.img` is a vfat format image, it contains kernel image, initramfs image, device tree blob, logo image used by u-boot

### **Step 9:** Flash the root file system (rootfs)

The rootfs image of 96board is named as bubblegum-jessie_alip_20160224-12_r1.emmc.img
The name could be different from what you have downloaded.

_**[Host PC]**_

`$ sudo fastboot flash SYSTEM bubblegum-jessie_alip_20160224-12_r1.emmc.img`

**This step takes around 2 minutes or more depend on the image size.**

### **Step 10:** Create bootloader.img and flash using fastboot

We need to flash the bootloader by fastboot. First we need to create the “BOOTLOADER” partition.

Use the following commands on Host pc to create the bootloader.img:

```shell
# Creates a 6MiB empty image.
$ dd if=/dev/zero of=bootloader.img bs=1M count=6
# Place bootloader.bin to correct place.
$ dd conv=notrunc if=bootloader.bin of=bootloader.img seek=4063 bs=512
# Place u-boot-dtb.img to correct place.
$dd conv=notrunc if=u-boot-dtb.img of=bootloader.img seek=6110 bs=512
# Use fastboot to flash BOOTLOADER partition
$sudo fastboot flash BOOTLOADER bootloader.img
```

Reboot.
