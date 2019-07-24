---
title: Build AOSP for ROCK960
permalink: /documentation/consumer/rock/build/Android9.md.html
redirect_from: /documentation/consumer/rock960/build/Android9.md.html
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
$ sudo apt-get install openjdk-8-jdk python git-core gnupg flex bison gperf build-essential \
                          zip curl liblz4-tool zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 \
                          lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache \
                          libgl1-mesa-dev libxml2-utils xsltproc unzip mtools u-boot-tools \
                          htop iotop sysstat iftop pigz bc device-tree-compiler lunzip \
                          dosfstools vim-common parted udev lzop
```

Configure the JAVA environment

```shell
$ export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
$ export PATH=$JAVA_HOME/bin:$PATH
$ export CLASSPATH=.:$JAVA_HOME/lib:$JAVA_HOME/lib/tools.jar
```

## Download source code

```shell
$ mkdir rock960-android9
$ cd rock960-android9
```
Then run:

```shell
$ ~/bin/repo init -u https://github.com/96rocks/manifests.git -b rock960-box-9.0 -m rock960_release.xml
$ repo sync -j$(nproc) -c
```
It might take quite a bit of time to fetch the entire AOSP source code(around 86G)!

## Build u-boot

```shell
$ cd u-boot
$ ./make.sh rk3399
$ cd ..
```

The generated images are **rk3399_loader_v_xxx.bin** and **uboot.img**

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
# Tv Box
$ lunch rk3399_box-userdebug
# Tablet
$ lunch rk3399-userdebug
$ make -j$(nproc)
```

It takes a long time, take a break and wait...


## Package images

```shell
$ ln -s RKTools/linux/Linux_Pack_Firmware/rockdev/ rockdev
$ ./mkimage.sh
```

## Generate rkupdate images
Pack all partitions into one image.

```shell
$ cd rockdev
# for rk3399_box
$ ln -s Image-rk3399_box Image
# for rk3399
$ ln -s Image-rk339 Image
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
    IMAGE_LENGTH:9018403
    simg2img system.img
    simg2img vendor.img
    simg2img oem.img
    idbloader       64              16383           8.000000       MB
    Warning: The resulting partition is not properly aligned for best performance.
    uboot           16384           24575           4.000000       MB
    trust           24576           32767           4.000000       MB
    misc            32768           40959           4.000000       MB
    resource        40960           73727           16.000000      MB
    kernel          73728           139263          32.000000      MB
    dtb             139264          147455          4.000000       MB
    dtbo            147456          155647          4.000000       MB
    vbmeta          155648          157695          1.000000       MB
    boot            157696          223231          32.000000      MB
    recovery        223232          354303          64.000000      MB
    backup          354304          583679          112.000000     MB
    security        583680          591871          4.000000       MB
    cache           591872          1640447         512.000000     MB
    system          1640448         6883327         2560.000000    MB
    metadata        6883328         6916095         16.000000      MB
    vendor          6916096         7964671         512.000000     MB
    oem             7964672         9013247         512.000000     MB
    frp             9013248         9014271         0.500000       MB
    userdata        9014272         9014271         0.000000       MB
    Warning: The resulting partition is not properly aligned for best performance.

Will be generated `Image/gpt.img`

Proceed to [Installation Instructions](../installation)
