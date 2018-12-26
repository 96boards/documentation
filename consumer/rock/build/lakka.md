---
title: Build Lakka for ROCK960
permalink: /documentation/consumer/rock/build/lakka.md.html
redirect_from: /documentation/consumer/rock960/build/lakka.md.html
---

# Build Lakka for ROCK960

## Build environment setup

- Recommend build host is Ubuntu 16.04 64bit.
- Install dependencies
```
sudo apt update
sudo apt install build-essential swig hexdump flex bison bc git
```

## Download source code

`git clone https://github.com/libretro/Lakka-LibreELEC`

## Build Lakka

```shell
cd Lakka-LibreELEC
PROJECT=Rockchip DEVICE=RK3399 BOARD=ROCK960 ARCH=arm make -j$(nproc) image
```
> This might take a while, get a coffee or something

The generated image is **Lakka-Rockchip.ROCK960.arm-2.2-devel-20181221214123-r28231-g697ea2a.img.gz** in the `target` folder.

## Installation

- The generated image is an sdcard image, and can be simply be flashed using `dd`.
- Insert you sdcard in your host PC, check to see the device name bu running `fdisk -l`
- Uncompress sdcard image: `gunzip Lakka-Rockchip.ROCK960.arm-2.2-devel-20181221214123-r28231-g697ea2a.img.gz`
- Flash sdcard image: `sudo dd if=Lakka-Rockchip.ROCK960.arm-2.2-devel-20181221214123-r28231-g697ea2a.img of=/dev/sdx status=progress`
> Note: failure to assign the correct device name in place of /dev/sdx will result in data loss.

- Insert the sdcard in your Rock960 and boot.

## Fix the Black-Box Issue

- When you boot lakka for the first time, you might get black boxes in place of Icons.
- To fix this issue:
  - Navigate to: `Online Updater`
  - Select: `Update Assets`
- This should fix the black box issue.
