---
title: Building Android Open Source Project (AOSP) for Dragonboard
permalink: /documentation/consumer/dragonboard/guides/aosp/
redirect_from:
- /documentation/consumer/dragonboard820c/guides/aosp/
- /documentation/consumer/dragonboard/dragonboard820c/guides/aosp/
- /documentation/consumer/dragonboard/dragonboard410c/guides/aosp/
---
# Building Android Open Source Project (AOSP) for Dragonboard 410c and 820c Family

**NOTE: This page provides instructions to make a build based on AOSP for Dragonboard Family. This should be considered work-in-progress, and the following page might be updated at any time with newer (and different) instructions. This is not a complete tutorial for AOSP, and the reader is expected to be familiar with building Android in general. For any general Android issue, please refer to Android documentation and guides.**

# Build preparation

The following instructions can be used to attempt a build based on the AOSP master branch. Other branches (such as stable/release branches are not supported).

In this page, we assume that `<ANDROID_TOP>` is the top level folder for your Android environment. e.g.:
```shell
$ mkdir <ANDROID_TOP>
$ cd <ANDROID_TOP>
```
Then run:
```shell
$ repo init -u https://android.googlesource.com/platform/manifest -b master
$ git clone https://android-git.linaro.org/git/platform/manifest.git .repo/local_manifests -b dragonboard
$ repo sync -j$(nproc) -c
```
It might take quite a bit of time to fetch the entire AOSP source code!

# Building AOSP
- Setup Environment Variables: `source build/envsetup.sh`
- Run the Lunch Command:
  - DragonBoard-410c: `lunch db410c32_only-userdebug`
  - DragonBoard-820c: `lunch db820c-userdebug`
- Build: `make -j$(nproc)`


# Flashing the board

While holding the S4 button, power the DragonBoard boards to enter fastboot mode.
We can now flash the Android images

For the 410c: `sudo ./device/linaro/dragonboard/installer/db410c/flash-all-aosp.sh`
For the 820c: `sudo ./device/linaro/dragonboard/installer/db820c/flash-all-aosp.sh`

# Building the Kernel for 410c
If you want to build your own kernel for DragonBoard 410c, follow these steps:

```shell
$ cd <ANDROID_TOP>
$ git clone http://git.linaro.org/landing-teams/working/qualcomm/kernel -b release/android/qcomlt-4.14 db410c-kernel
$ cd db410c-kernel
$ rm arch/arm64/configs/defconfig
$ wget http://snapshots.linaro.org/96boards/dragonboard410c/linaro/aosp/kernel/latest/defconfig -P arch/arm64/configs/
$ make ARCH=arm64 defconfig
$ make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j$(nproc)
$ cat arch/arm64/boot/Image.gz arch/arm64/boot/dts/qcom/apq8016-sbc.dtb > db410c-qcomlt-4.14.gz-dtb
$ cp db410c-qcomlt-4.14.gz-dtb device/linaro/dragonboard-kernels/
$ cd ..
$ make -j$(nproc) bootimage
# Put board into fastboot mode
$ sudo fastboot flash boot out/target/product/b410c32_only/boot.img
#Reboot the board after flashing
```

# Booting into Android

If everything went fine, you can now reboot the board, and it should boot into Android!


# How to contribute and support

The following mailing list can be used for contributions:

https://lists.96boards.org/mailman/listinfo/dragonboard

For support, the 96boards forum can also be used

https://discuss.96boards.org/c/products/dragonboard820c
https://discuss.96boards.org/c/products/dragonboard410c
