---
title: Build Linux Host Computer
permalink: /documentation/consumer/dragonboard820c/installation/build-linux-host.md.html
redirect_from:

---
## Build Linux Host Computer

This section shows how to install **Ubuntu Desktop** on a **Linux host** computer to be able to use it to **flash the bootloader** and **use fastboot** to load boot and rootfs images onto the DragonBoard 820c.

## Hardware

As a Windows user I prefer software that I can run on my Windows 10 laptop either on the host OS, WSL, Ubuntu VM or Debian VM.
Flashing the bootloader and using fastboot require serial communication from linux.
I did not find a sulution to be able to do this in WSL, Ubuntu VM or Debian VM (Hyper-V).

> **CTA** How do we setup WSL, Ubuntu VM or Debian VM (Hyper-V) to be able to flash the bootloader and using fastboot.  

Most likely you are like me and have couple of old laptops and PCs laying around. I took an 11 years old HP laptop and installed **[Ubuntu Desktop](http://releases.ubuntu.com/16.04.4/ubuntu-16.04.4-desktop-amd64.iso)** on it. Follow the **[Installation Guide](https://tutorials.ubuntu.com/tutorial/tutorial-install-ubuntu-desktop#0)**.

## Packages
After logging into your Linux host do the usual dance moves and update/upgrade your system.

```shell
$ sudo apt-get update
$ sudo apt-get upgrade -y
$ sudo apt-get dist-upgrade -u -y
$ sudo apt autoremove -y
```

**The Android Tools and Fastboot are prerequisites.**

```shell
$ sudo apt install -y android-tools-adb android-tools-fastboot libxml2-dev
```

## Building Qualcomm Download (QDL) tool
The script downloads and builds QDL.

```shell
$ mkdir DB820c
$ cd DB820c
$ git clone https://git.linaro.org/landing-teams/working/qualcomm/qdl.git
$ cd qdl
$ make
$ cd ..
```

## Prepare the bootloader package
The script downloads the latest build and prints the BUILD number for your information.

```shell
$ BUILD=$(curl http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/ | grep -oP '(?<=/)\d{2}(?=/")')
$ echo "BUILD=$BUILD"
$ wget http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/dragonboard-820c-bootloader-ufs-linux-*.zip
$ unzip dragonboard-820c-bootloader-ufs-linux-*.zip
$ rm dragonboard-820c-bootloader-ufs-linux-*.zip
$ mv dragonboard-820c-bootloader-ufs-linux-$BUILD bootloader-ufs-linux
$ cd ~/DB820c/bootloader-ufs-linux
```

## Flashing the bootloader

At this point you are setup to Flashing the bootloader and use fastboot to load boot and rootfs images onto your DragonBoard 820c.
Please continue to the **[Fastboot Method](linux-fastboot.md)** to continue the installation. You can skip to the line that calls QDL.

```shell
$ sudo ~/DB820c/qdl/qdl prog_ufs_firehose_8996_ddr.elf rawprogram.xml patch.xml
```

  
