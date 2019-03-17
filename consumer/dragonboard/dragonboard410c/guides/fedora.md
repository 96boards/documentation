---
title: Install Fedora on Dragonboard410c
permalink: /documentation/consumer/dragonboard/dragonboard410c/guides/fedora.md.html
---

# Installing Fedora on DragonBoard410c

## What is Fedora?
Fedora is a Linux distribution developed by the community-supported Fedora Project and sponsored by Red Hat. Fedora contains software distributed under various free and open-source licenses and aims to be on the leading edge of such technologies. Fedora is the upstream source of the commercial Red Hat Enterprise Linux distribution.

## Installation

### Requirements
- DragonBoard410c
- Host system with SDCard slot running Fedora.

### Download Files:
- [Bootloader](https://builds.96boards.org/releases/dragonboard410c/linaro/rescue/17.09/dragonboard410c_bootloader_emmc_linux-88.zip)
- [U-Boot](https://fedora.roving-it.com/qcom-db410c/u-boot.img)
- [LK firmware with display output](https://fedora.roving-it.com/qcom-db410c/emmc_appsboot.mbn)
- [Fedora Aarch64 Build](https://dl.fedoraproject.org/pub/fedora/linux/releases/29/Server/aarch64/images/Fedora-Server-29-1.2.aarch64.raw.xz)

### Flash Bootloader
- Extract rescue zip:
    ```
    unzip dragonboard410c_bootloader_emmc_linux-88.zip
    cd dragonboard410c_bootloader_emmc_linux-88
    ```
- Set Dragonboard410c to fastboot mode
    - Hold down the volume down button, labeled as ‘(-)’ near the middle USB port and then power it on.
    - Wait around 30 seconds to ensure it’s booted to fastboot.
    - You can test this with the `fastboot devices` command.
- Flash firmware:
    ```
    sudo ./flashall
    sudo fastboot flash aboot emmc_appsboot.mbn
    sudo fastboot flash boot u-boot.img
    sudo fastboot oem select-display-panel adv7533_1080p
    ```
- Install arm-image-installer: `sudo dnf install arm-image-installer`
- Insert micro-SDCard in the host machine and run the following command to flash the image:
    ```
    sudo arm-image-installer --target=dragonboard410c --image=Fedora-Server-29-1.2.aarch64.raw.xz --addconsole --norootpass --resizefs --media=/dev/sdX
    ```
    - Replace `/dev/sdX` with the drive name of the SDCard.
- Once the SDCard is flashed, insert it into your DragonBoard410c and reboot.
