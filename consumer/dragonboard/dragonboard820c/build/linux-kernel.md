---
title: Building Linux Kernel for Dragonboard-820c
permalink: /documentation/consumer/dragonboard/dragonboard820c/build/linux-kernel.md.html
redirect_from: /documentation/consumer/dragonboard820c/build/linux-kernel.md.html
---

# Building Linux Kernel for Dragonboard-820c

The following instructions can be used to build Linux Kernel from source for Dragonboard-820c.  Note this is cross-compiled on a host development system.   These instructions assume the host machine is Linux based.

## Install Required Packages

The following command installs packages which are required to build the
kernel on Debian based systems:

```shell
$ sudo apt-get install git build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache
```
> Note: For other distributions, try installing the development packages needed to build a native kernel.

## Set up Toolchain Environment
Create a working directory
```
$ mkdir 820cSourceBuild
$ cd 820cSourceBuild
```

Download the desired toolchain from linaro.org
```
$ mkdir toolchain
$ cd toolchain
$ wget  https://releases.linaro.org/components/toolchain/binaries/latest/aarch64-linux-gnu/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu.tar.xz
```
Unzip the toolchain
```
$ tar -xf gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu.tar.xz
```
Set the host up to point to the newly downloaded toolchain
```
$ export ARCH=arm64
$ export CROSS_COMPILE=$(pwd)/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
```
## Cloning the Kernel Source
The Linux kernel used for DragonBoard 820c can be found in the Linaro Qualcomm Landing Team git repository. It's always a good idea to verify that the latest build was successful prior to cloning.  This can be checked on the Snapdragon 820 project ci dashboard [**here**](https://ci.linaro.org/job/lt-qcom-debian-images-dragonboard820c "820c CI").

Once verified,create a development directory, navigate to it, and clone the repository.
```
$ mkdir 820dev
$ cd 820dev
$ git clone http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
```
## Checkout desired branch
 These instructions describe three options for selecting a branch.
#### Example: Checkout tip
To checkout the tip of Dragonboard 820c kernel code, perform the following from the directory the source was cloned:
```
$ cd kernel
$ git checkout -t origin/release/qcomlt-4.14
```
In the above, `4.14` is the kernel version in the form of x.y.   Replace x and y with kernel major and minor release versions that is desired to be checked out (the latest one being the most up-to-date/recent).
#### Example: Checkout Integration Branch
A developer can checkout the integration-linux-qcomlt branch, which is regularly rebased on recent mainline, and is used by developers.
```
$ cd kernel
$ git checkout integration-linux-qcomlt
```
#### Example: Checkout kernel source from a specific build
Some things to keep in mind when checking out the kernel source from a specific previous build:
 1) As noted earlier, check the Snapdragon 820 project ci dashboard [**here**](https://ci.linaro.org/job/lt-qcom-debian-images-dragonboard820c "820c CI") to verify that the source branch you're checking out built successfully.
 2) To see the snapshot build history, click [**here**](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/debian/ "Build history")
 3) The branch to checkout for a kernel from a specific build is the kernel package version commit id that can be found on the details page for a build that includes the Build Description and the pre-builts for that build.  For example, the Build Description for Build 182 can be seen [**here**](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/debian/ "182 Details")
```
$ git checkout <commit ID>
```

 Using build 182 as an example, the Kernel package version is 4.14.15-00213-g**f5e8b5579a54**-26 and the commit id is in bold.
The kernel commit ID in that string is f5e8b5579a54, and this is the commit id that identifies the correct branch to checkout.
```
git checkout f5e8b5579a54
```
#### Establish a known good install
It's a good idea to first select a prebuilt kernel boot image and rootfs, install these and bring them up on your Dragonboard 820c.  Follow the Dragonboard 820c [Installation page](../installation/ "Installation page") to do this.  Install the kernel boot image and the rootfs from the desired build and boot the board up to verify it's functional.

Note: The latest bootloader should also be installed.  This is found [**here**](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/ "Bootloader latest"), and the instructions to install are also located on the installation page noted above.

Once a baseline build is working, moving forward with a kernel build from source can be verified much easier for correctness. It's important to understand that the kernel image is coupled to it's associated rootfs. The modules are installed with the rootfs, and the kernel then gets these and installs them as needed.

#### Checkout
Assuming that you've installed and booted the pre-existing build  chosen as your baseline, you are ready to checkout a kernel branch, build and install it.

Select which branch to checkout and do so as shown in the examples above

## Build the Kernel
Remaining in the ./kernel directory from the previous section, execute the following:

```
$ make defconfig distro.config
$ let "PROCS=$(nproc)/2"
$ make -j $PROCS Image.gz dtbs KERNELRELEASE=4.14.0-qcomlt-${ARCH}
```
In the above instructions, note that $PROCS is a variable that is loaded with 50% of the available logical CPU cores on the system to be used for the build.  It can be adjusted, but depending on your development system, dedicating too many cores to the build can have adverse effects such as overwhelming your development host.


## Create the Boot Image
Now that the kernel is build, a boot image must be created for the Dragonboard 820c.  The bootable image is composed of three components:

1) The Image file. This file can be found in the  kernel build just completed in the previous step,
2) The device tree blob (dtb).  The files used to create this were also created in the previous section,
3) A ramdisk

To create the boot image, follow the instructions available [**here**](https://github.com/96boards/documentation/wiki/Dragonboard-Boot-Image "Create boot image").

## Install the Kernel Boot Image
Follow the normal fastboot instructions found [**here**](../installation/ "Fastboot install") to install the boot image created in the previous step.   


Congratulation!  You have just built and installed a new kernel on you DragonBoard 820c!
