---
title: Build AOSP for ROCK960
permalink: /documentation/consumer/rock/build/Android7-TV.md.html
redirect_from: /documentation/consumer/rock960/build/Android7-TV.md.html
---

# Build AOSP for ROCK960

## Build environment setup

Recommend build host is Ubuntu 16.04 64bit, for other hosts, refer official Android documents [Establishing a Build Environment](https://source.android.com/setup/build/initializing).


```shell
$ mkdir -p ~/bin
$ wget 'https://storage.googleapis.com/git-repo-downloads/repo' -P ~/bin
$ chmod +x ~/bin/repo
```

Android's source code primarily consists of Java, C++, and XML files. To compile the source code, you'll need to install OpenJDK 8, GNU C and C++ compilers, XML parsing libraries, ImageMagick, and several other related packages.


```shell
$ sudo apt-get update
$ sudo apt-get install openjdk-8-jdk android-tools-adb bc bison build-essential curl flex g++-multilib gcc-multilib gnupg gperf imagemagick lib32ncurses5-dev lib32readline-dev lib32z1-dev libesd0-dev liblz4-tool libncurses5-dev libsdl1.2-dev libssl-dev libwxgtk3.0-dev libxml2 libxml2-utils lzop pngcrush rsync schedtool squashfs-tools xsltproc yasm zip zlib1g-dev
```

Configure the JAVA environment

```shell
$ export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
$ export PATH=$JAVA_HOME/bin:$PATH
$ export CLASSPATH=.:$JAVA_HOME/lib:$JAVA_HOME/lib/tools.jar
```

## Download source code

```shell
$ mkdir rock960-android
$ cd rock960-android
```
Then run:

```shell
$ ~/bin/repo init -u https://github.com/96rocks/manifests.git -b rock960-box-7.1 -m rock960_box_7.1_release.xml
$ repo sync -j$(nproc) -c
```
It might take quite a bit of time to fetch the entire AOSP source code(around 86G)!

## Build u-boot

```shell
$ cd u-boot
$ make rk3399_box_defconfig
$ ./mkv8.sh
$ cd ..
```

The generated images are **rk3399_loader_v_xxx.bin** and **uboot.img** and **idbloader.img**

## Building kernel

```shell
$ cd kernel
$ make rockchip_defconfig
# rock960 mode ab
$ make rk3399-rock960-model-ab.img -j$(nproc)
# rock960 mode c
$ make rk3399-rock960-model-c.img -j$(nproc)
$ cd ..
```

The generated images are **kernel.img** and **resource.img**:

- kernel.img, kernel with rkcrc checksum
- resource.img, contains dtb and boot logo, Rockchip format resource package

## Building AOSP

```shell
$ source build/envsetup.sh
$ lunch rk3399_box-userdebug
$ make -j$(nproc)
```

It takes a long time, take a break and wait...


## Package images

```shell
$ ln -s RKTools/linux/Linux_Pack_Firmware/rockdev/ rockdev
$ ./mkimage.sh
```

The generated images under rockdev/Image-rk3399_box are

    boot.img    MiniLoaderAll.bin  parameter.txt        pcba_whole_misc.img  resource.img  trust.img
    kernel.img  misc.img           pcba_small_misc.img  recovery.img         system.img    uboot.img

They can be flashed with fastboot or Rockchip upgrade_tool.

## Generate rkupdate images

Pack all partitions into one image.

```shell
$ cd rockdev
$ ln -s Image-rk3399_box Image
$ ./mkupdate.sh
```

    Start to make update.img...
    Android Firmware Package Tool v1.62
    ------ PACKAGE ------
    Add file: ./package-file
    Add file: ./Image/MiniLoaderAll.bin
    Add file: ./Image/parameter.txt
    Add file: ./Image/trust.img
    Add file: ./Image/uboot.img
    Add file: ./Image/misc.img
    Add file: ./Image/resource.img
    Add file: ./Image/kernel.img
    Add file: ./Image/boot.img
    Add file: ./Image/recovery.img
    Add file: ./Image/system.img
    Add CRC...
    Make firmware OK!
    ------ OK ------
    ********RKImageMaker ver 1.63********
    Generating new image, please wait...
    Writing head info...
    Writing boot file...
    Writing firmware...
    Generating MD5 data...
    MD5 data generated successfully!
    New image generated successfully!
    Making update.img OK.

**update.img** is the packed image with all partitions.

## Generate gpt images
Pack all partitions into one gpt image.
```shell
$ cd rockdev
$ ./android-gpt.sh
```
    IMAGE_LENGTH:4984867
    simg2img system.img
    idbloader       64              16383           8.000000       MB
    Warning: The resulting partition is not properly aligned for best performance.
    uboot           16384           24575           4.000000       MB
    trust           24576           32767           4.000000       MB
    misc            32768           40959           4.000000       MB
    resource        40960           73727           16.000000      MB
    kernel          73728           122879          24.000000      MB
    boot            122880          188415          32.000000      MB
    recovery        188416          253951          32.000000      MB
    backup          253952          483327          112.000000     MB
    cache           483328          745471          128.000000     MB
    system          745472          4939775         2048.000000    MB
    metadata        4939776         4972543         16.000000      MB
    baseparamer     4972544         4980735         4.000000       MB
    userdata        4980736         4980735         0.000000       MB

Will be generated `Image/gpt.img`

Proceed to [Installation Instructions](../installation)
