---
title: Build Android from Source for TB-96AI
permalink: /documentation/som/tb-96ai/build/android/
---

### Download GNU cross-toolchain binaries and Installing required packages(Host machine Ubuntu 14.04 or Ubuntu 16.04)

```
$ sudo apt-get install git-core gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip liblz4-tool

```

### Install JDK and configues Java environment

```
$ sudo apt-get install openjdk-8-jdk
$ export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
$ export PATH=$JAVA_HOME/bin:$PATH
$ export CLASSPATH=.:$JAVA_HOME/lib:$JAVA_HOME/lib/tools.jar
```

###  Get TB-96AI 96Boards Android source code

```
$ repo init --repo-url http://github.com/aosp-mirror/tools repo.git -u http://github.com/rockchip-toybrick/manifest.git -b master -m TB-96AI-96ai.xml
$ repo sync
```

###  Build Uboot

```
$ cd u-boot
$ make rk3399pro_defconfig
$ ./mkv8.sh
```

###  Build Linux kernel

```
$ cd kernel
$ ./make.sh android 96ai
```

###  Build Android

```
$ source build/envsetup.sh
$ ./build.sh -b 96ai
```

### Generate TB-96AI 96Boards Android image for flash download

`$ ./mkimage.sh ota`
