---
title: Building Android Open Source Project (AOSP) for Dragonboard 410c
permalink: /documentation/consumer/dragonboard410c/guides/aosp.md.html
redirect_from:
- /db410c-getting-started/Guides/AOSP.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/AOSP.md.html
---
# Building Android Open Source Project (AOSP) for Dragonboard 410c

**NOTE: This page provides instructions to make a build based on AOSP for Dragonboard 410c. This should be considered work-in-progress, and the following page might be updated at any time with newer (and different) instructions. This is not a complete tutorial for AOSP, and the reader is expected to be familiar with building Android in general. For any general Android issue, please refer to Android documentation and guides.**

# Build preparation

The following instructions can be used to attempt a build based on the AOSP master branch. Other branches (such as stable/release branches are not supported).

In this page, we assume that `<ANDROID_TOP>` is the top level folder for your Android environment. e.g.:
```shell
mkdir <ANDROID_TOP>
cd <ANDROID_TOP>
```
Then run:
```shell
repo init -u https://android.googlesource.com/platform/manifest -b master
cd .repo
git clone https://github.com/robherring/android_manifest.git -b master local_manifests
cd ..
repo sync -j24
```
It might take quite a bit of time to fetch the entire AOSP source code!

# Firmware files (Optional)

Download the firmware setup package from here: https://drive.google.com/open?id=0B2zT38Egh-1TVkZoYUliOXdxaUk, and run the following command to prepare the firmware files in your Android environment:
```shell
tar -xf qcom-db410c-NOU.tgz
./extract-qcom-db410c.sh
```
When needed, hit yes, to agree to license.

Note that using this script is a temporary solution until the proper firmware package is published on 96boards website.

# Building AOSP
```shell
source build/envsetup.sh
lunch linaro_arm64-userdebug
make -j24
```

# Building Kernel
```shell
cd ..
git clone https://git.kernel.org/pub/scm/linux/kernel/git/robh/linux.git -b qcom-4.14 <KERNEL_TOP>
cd <KERNEL_TOP>
make ARCH=arm64 db410c_android_defconfig android-base.config android-recommended.config
make CROSS_COMPILE=aarch64-android-gnu- ARCH=arm64 all
cat arch/arm64/boot/Image.gz arch/arm64/boot/dts/qcom/apq8016-sbc.dtb > Image.gz-dtb
mkbootimg --kernel Image.gz-dtb --ramdisk <ANDROID_TOP>/out/target/product/linaro_arm64/ramdisk.img --output boot-db410c.img --pagesize 2048 --base 0x80000000 --cmdline 'androidboot.selinux=permissive firmware_class.path=/system/vendor/firmware/'
```

# Flashing the board

While holding the S4 button, power the DragonBoard 410c board to enter fastboot mode. Before flashing the Android images, we need to flash the bootloaders and GPT. e.g. run the following commands:
```shell
cd ..
mkdir ~/db410-bootlaoder
cd ~/db410-bootlaoder
wget http://builds.96boards.org/snapshots/dragonboard410c/linaro/rescue/latest/dragonboard410c_bootloader_emmc_aosp-*.zip
unzip dragonboard410c_bootloader_emmc_aosp-*.zip
./flashall
```
We can now flash the Android images.
```shell
cd ..
cd <KERNEL_TOP>
fastboot flash boot boot-db410c.img
cd <ANDROID_TOP>
fastboot flash system out/target/product/linaro_arm64/system.img
fastboot flash cache out/target/product/linaro_arm64/cache.img
fastboot flash userdata out/target/product/linaro_arm64/userdata.img
fastboot reboot
```
# Booting into Android

If everything went fine, you can now reboot the board, and it should boot into Android!

# How to contribute and support

The following mailing list can be used for contributions:

https://lists.96boards.org/mailman/listinfo/dragonboard

For support, the 96boards forun can also be used

https://discuss.96boards.org/c/products/dragonboard410c
