---
title: Building Android Open Source Project (AOSP) for Dragonboard 820c
permalink: /documentation/consumer/dragonboard820c/guides/aosp/
---
# Building Android Open Source Project (AOSP) for Dragonboard 820c

**NOTE: This page provides instructions to make a build based on AOSP for Dragonboard 820c. This should be considered work-in-progress, and the following page might be updated at any time with newer (and different) instructions. This is not a complete tutorial for AOSP, and the reader is expected to be familiar with building Android in general. For any general Android issue, please refer to Android documentation and guides.**

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
```shell
$ source build/envsetup.sh
$ lunch db820c-userdebug
$ make -j$(nproc)
```

# Flashing the board

While holding the S4 button, power the DragonBoard 410c board to enter fastboot mode.
We can now flash the Android images

```shell
$ sudo ./device/linaro/dragonboard/installer/db820c/flash-all-aosp.sh
```
# Booting into Android

If everything went fine, you can now reboot the board, and it should boot into Android!


# How to contribute and support

The following mailing list can be used for contributions:

https://lists.96boards.org/mailman/listinfo/dragonboard

For support, the 96boards forum can also be used

https://discuss.96boards.org/c/products/dragonboard820c
