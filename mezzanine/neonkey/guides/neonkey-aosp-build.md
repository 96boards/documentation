---
title: Instructions to Build AOSP for Hikey and Hikey960 with Neonkey Enabled
permalink: /documentation/mezzanine/neonkey/guides/neonkey-aosp-build.md.html
---

# Instructions to Build AOSP for Hikey and Hikey960 with Neonkey Enabled

This instruction will show you how to build AOSP for the Hikey and Hikey960 with
the Neonkey sensor mezzanine enabled. This allows Android apps to access the
Neonkey's sensors as they would on a regular smartphone that runs Android.

## Step 1: Establishing the build environment and downloading the source code

- Follow the Official AOSP Guide:
  [Establishing a Build Environment](https://source.android.com/source/initializing)
- To download the source code follow the Official AOSP Guide specific to your
  board: [Using Reference Boards](https://source.android.com/source/devices)
- NOTE: Please make sure you have about 200GB of free space an at least 8GB of
free RAM.

## Step 2: Build the source code:
 - Build and Flash AOSP
    ```shell
    $ cd <source directory>
    $ source build/envsetup.sh
    $ lunch hikey960-userdebug # or $ lunch hikey-userdebug
    $ make TARGET_SENSOR_MEZZANINE=neonkey -j$(nproc)
    ```
    This process can take anywhere from 1 to 6 hours or even more depending on
    your hardware configuration.

    My Intel Core i3 2120 takes 6 hours and my Xeon E3-1535M v6 takes 1.5 hours.

    ***Following this process flash the build to you board as described in: [Using Reference Boards](https://source.android.com/source/devices)***

- Build and Flash Neonkey Firmware: Follow the Official AOSP Documentation:
  [Neonkey SensorHub](https://source.android.com/source/devices#neonkey)

  NOTE: In order to flash using the Hikey960 replace /dev/ttyAMA2 with /dev/ttyAMA3

## Step 3: Test

  - Reboot the board.

  - Use any application like Aida64 or Sensor Box to test the implementation.
  Feel free to tryout some motion sensing games as well.
