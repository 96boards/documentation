---
title: BoardRecovery for Bubblegum-96
permalink: /documentation/consumer/bubblegum-96/installation/board-recovery/
---
# Bubblegum-96 Board Recovery

This page outlines steps needed to recover your Bubblegum-96 board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components such as bootloader.

## Installing a Bootloader

For most users a board can be “recovered” from a software failure by reloading the operating system. However, if the primary bootloader in the eMMC flash memory has been corrupted then the bootloader will need to be re-installed. This section describes how to reinstall the primary bootloader.

### 1) Update Host System

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

### 2) Install Host Dependencies

```shell
$ sudo apt-get install git cmake
$ sudo apt-get install libusb-1.0-0
```

### 3) Download, Build, and Install ADFU tool on Host

This repository consists of the proprietary vendor binaries and **ADFU**
source code. By building and installing this tool, the vendor binaries
will be copied to the host and used during recovery process.

```shell
$ git clone https://github.com/96boards-bubblegum/linaro-adfu-tool.git
$ cmake .
$ make
$ sudo make install
```
This will build and install the **ADFU** tool to `/usr/local/share/linaro-adfu-tool`.

### 4) Download recovery image

Apart from the vendor binaries downloaded from the above section, we also
need U-Boot image for recovering the board. The following command downloads
the pre-built U-Boot image.

```shell
$ wget https://releases.linaro.org/96boards/bubblegum/linaro/u-boot/latest/u-boot-dtb.img
```

### 5) Enter ADFU Mode

The following instructions are used to recover board from bricked stage with
the help of ROM bootloader using ADFU tool.

- Make sure bubblegum-96 board is in power off mode
- Plug in the UART debug board and connect serial console to the host PC
   - Set baud rate as 115200
   - Set (8N1) – [8bit data, No-parity, & 1 stop bit]
- Connect the host PC with Bubblegum-96 USB3.0 port via type USB A-A cable
   - USB3.0 port on Bubblegum96 board is the blue port
   - This cable won’t provide Power, so it will not boot up the board
- Hold down the ADFU key on the Bubblegum96 board
- Plug in power to the Bubblegum96 board
- Continue to hold down ADFU down the ADFU key for 2-4 seconds after the power has been plugged in
- Release the ADFU key
- Execute `lsusb` on host PC
   - You will find a device ID 10d6:10d6 if Bubblegum96 board has entered adfu-mode

### 6) Access 96board U-boot shell

While Bubblegum96 board is in ADFU mode, execute the following commands
in linaro-adfu-tool/ directory to access 96board u-boot shell.

`$ sudo linaro-adfu-tool-bg96 u-boot-dtb.img`

**Note:** if you `make install` the ADFU tool as mentioned above, you should be
able to run linaro-adfu-tool from any path, it will search binaries from
certain locations, such as

1. /usr/local/share/linaro-adfu-tool/bg96/firmwares/
2. /usr/share/linaro-adfu-tool/bg96/firmwares/
3. ./firmwares/
4. ../firmwares/

While executing the above steps you can see the log in serial terminal.
And once all the images are flashed, Bubblegum96 board will boot using U-Boot.
Interrupt during the U-Boot booting stage to access the console and it will show
`“owl>”` prompt.

> Note: For now the binaries are only flashed on to RAM, for flashing the
binaries on to eMMC, proceed to [Fastboot Mode](./linux-fastboot.md#enter-fastboot-mode) section.
