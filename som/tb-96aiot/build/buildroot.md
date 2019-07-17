---
title: Build Buildroot Linux Source for TB-96AIoT
permalink: /documentation/som/tb-96aiot/build/buildroot.md.html
---

### Download Dependencies (Host machine Ubuntu 16.04)

```
$ sudo apt-get install repo git-core gitk git-gui gcc-arm-linux-gnueabihf u-boot-tools device-tree-compiler gcc-aarch64-linux-gnu mtools parted libudev-dev libusb-1.0-0-dev python-linaro-image-tools linaro-image-tools autoconf autotools-dev libsigsegv2 m4 intltool libdrm-dev curlsed make binutils build-essential gcc g++ bash patch gzip bzip2 perl tar cpio python unzip rsyncfile bc wget libncurses5 libqt4-dev libglib2.0-dev libgtk2.0-dev libglade2-dev cvs git mercurial rsync openssh-client subversion asciidoc w3m dblatex graphviz python-matplotlib libc6:i386 liblz4-tool
```

### Get TB-96AIOT 96Boards source code

```
$ repo init --repo-url http://github.com/aosp-mirror/tools_repo.git -u https://github.com/96boards-tb-96aiot/manifest.git
$ repo sync
```

### Build UBoot

```
$ cd u-boot9
$ ./make.sh rk1808
```

### Build Linux kernel

```
$ cd kernel
$ make rk1808_linux_defconfig
$ make rk1808-evb-v10.img
```

### Build Buildroot

```
$ source buildroot/build/envsetup.sh
Top of tree: /home/lidq/1808
You're building on Linux
Lunch menu...pick a combo:
1. rockchip_px30_32
2. rockchip_px30_64
...
9. rockchip_px3se_recovery
10. rockchip_TB-96AIoT
11. rockchip_TB-96AIoT_compute_stick
...
54. rockchip_rk3399_recovery
55. rockchip_rv1108
Which would you like? [1]:
Choose 10 for TB-96AIoT
$ make
```

### Generate TB-96AIOT 96Boards Linux image for flash download

`$ ./mkfirmware.sh`
