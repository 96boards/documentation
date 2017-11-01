---
title: Generic OpenEmbedded/Yocto Guide for 96Boards Platforms
permalink: /documentation/ConsumerEdition/guides/open_embedded.md.html
---

## OpenEmbedded and Yocto

This page provides the board agnostic instructions to get started with OpenEmbedded and the Yocto project on
96Boards platform.

# Introduction

This wiki is not an introduction on OpenEmbedded or Yocto Project. If you are not familiar with OpenEmbedded and the Yocto Project, 
it is very much recommended to read the appropriate documentation first. For example, you can start with:
* [http://openembedded.org/wiki/Main_Page](http://openembedded.org/wiki/Main_Page)
* [http://yoctoproject.org/](http://yoctoproject.org/)
* [https://www.yoctoproject.org/documentation](https://www.yoctoproject.org/documentation)

In this wiki, we assume that the reader is familiar with basic concepts of OpenEmbedded.

The support for a dedicated board is available in the dedicated BSP Layer. These layers have been tested with OpenEmbedded 
Core layer, and are expected to work with any other standard layers and of course any OpenEmbedded based distributions.

## OE Layers

Below are the list of OpenEmbedded layers used for 96Boards platform.

|   Layer                 |   Description         |
|:-----------------------:|:----------------------|
| oe-core (Base layer)    | This is the main collaboration point when working on OpenEmbedded projects and is part of the core recipes. The goal of this layer is to have just enough recipes to build a basic system, this means keeping it as small as possible. |
| meta-rpb (Distro layer) |   This is a very small layer where the distro configurations live. Currently it houses both Reference Platform Build and Wayland Reference Platform Builds. |
| meta-oe                 | This layer houses many useful, but sometimes unmaintained recipes. Since the reduction in recipes to the core, meta-oe was created for everything else. There are currently approximately 650 recipes in this layer. |
| meta-browser            | This layer holds the recipes for Firefox and Chromium. Both recipes require a lot of maintenance, because of this a seperate layer was created. |
| meta-qt5                | This is a cross-platform toolkit. |
| meta-linaro             | This layer is used to get the Linaro toolchain. |
| meta-linaro-backports   | This is an experimental layer used to get newer versions into the build which were not part of the release.

In addition to the above layers, there are board specific layers present for each 96Boards CE boards:

1. Dragonboard410c - [meta-qcom BSP layer](http://git.yoctoproject.org/cgit/cgit.cgi/meta-qcom)
2. Hikey - [meta-96boards BSP layer](https://github.com/96boards/meta-96boards)

# Package Dependencies

In order to successfully set up your build environment, you will need to install the following package dependencies.

**Step 1**: You will need git installed on your Linux host machine

`$ sudo apt-get install git`

**Step 2**: Visit the OpenEmbedded (Getting Started) wiki to see which distribution specific dependencies you will need

[http://www.openembedded.org/wiki/Getting_started](http://www.openembedded.org/wiki/Getting_started)

**Step 3**: Install 96Boards specific dependencies (Case specific)

Setting up the build environment will first search for `whiptail`, if it is not present then it will search for `dialog`. You only need one of the following packages to ensure your setup-environement runs correctly:

`$ sudo apt-get install whiptail`

or

`$ sudo apt-get install dialog`

**Please Note**: If you are running Ubuntu 16.04 you will need to add the following source to your `/etc/apt/sources.list`. 
`deb http://archive.ubuntu.com/ubuntu/ xenial universe`

Executing the following command will append the source to your sources.list file.

```shell
$ echo "deb http://archive.ubuntu.com/ubuntu/ xenial universe" | sudo tee -a /etc/apt/sources.list
```

All required dependencies should now be installed on your host environment, you are ready to begin your build environment setup.

# Updating eMMC partitions and Bootloader

Before building the OE images, it is important to set up partition layout and flash the bootloader. Follow the below guides to setup
eMMC partitions and update Bootloader for the corresponding boards:

1. [Dragonboard410c](../DragonBoard-410c/BuildSource/open_embedded.md#updating-emmc-partitions-and-bootloader)
2. [Hikey](../HiKey/BuildSource/open_embedded.md#updating-emmc-partitions-and-bootloader)

# Setup the build environment

The BSPs layers can be used with any OE based distribution, such as Poky. The following instructions are provided to get started with OpenEmbedded Reference Software Platforms. 

To manage the various git trees and the OpenEmbedded environment, a repo manifest is provided. If you do not have `repo` installed on your host machine, you first need to install it, using the following instructions (or similar):

```shell
$ mkdir -p ${HOME}/bin
$ curl https://storage.googleapis.com/git-repo-downloads/repo > ${HOME}/bin/repo
$ chmod a+x ${HOME}/bin/repo
$ export PATH=${HOME}/bin:${PATH}
```
To initialize your build environment, you need to run:

```shell
$ mkdir oe-rpb && cd oe-rpb
$ repo init -u https://github.com/96boards/oe-rpb-manifest.git -b morty
$ repo sync
$ source setup-environment <build folder>
```
> Note: <*build folder*> is optional, if missing it will default to `build-$DISTRO`

After finishing the above mentioned steps, choose the board specific instructions below
for setting up the build environment for individual boards:

### Dragonboard410c

 * you will be prompted to choose the target MACHINE, pick `dragonboard-410c`
 * you will be prompted to choose the distro, for now, it is recommended to use `rpb`
 * you will be prompted to read and accept EULA (End User License Agreement), type **y** to read and accept **n** to ignore.

> Note: If you accepted the EULA, when building an image for DragonBoard410c all proprietary firmware are installed automatically
> in `/lib/firmware`, and a copy of the EULA is added as `/etc/license.txt`. If you did not accept the EULA, the firmwares
> are not downloaded, and not installed into the image. You can manually manage the firmware and download them separately 
> from [Qualcomm Developer Network](https://developer.qualcomm.com/download/linux-ubuntu-board-support-package-v1.1.zip).

### Hikey

 * you will be prompted to choose the target MACHINE, pick `hikey`
 * you will be prompted to choose the distro, for now, it is recommended to use `rpb`

The script `setup-environment` will create sane default configuration files in <build folder>/conf, you can inspect them and 
modify them if needed. Note that conf/local.conf and conf/bblayers.conf are symlink , and under source control. So it is 
generally better not to modify them, and use conf/site.conf and conf/auto.conf instead.

# Build a minimal, console-only image

To build a console image, you can run:

```shell
$ bitbake rpb-console-image
```
At the end of the build, your build artifacts will be found under `tmp-rpb-glibc/deploy/images/MACHINE`. The two artifacts you will 
use to update your board are:
* `rpb-console-image-MACHINE.ext4.gz` and
* `boot-MACHINE.uefi.img

> Note: MACHINE corresponds to the name of individual 96Boards

### Flashing build artifacts:

1. [Dragonboard410c](../DragonBoard-410c/BuildSource/open_embedded.md#flashing-build-artifacts)
2. [Hikey](../HiKey/BuildSource/open_embedded.md#flashing-build-artifacts)

# Build a simple X11 image

To build an X11 image with GPU hardware accelerated support, run:

```shell
$ bitbake rpb-desktop-image
```
At the end of the build, the root file system image will be available at `tmp-rpb-glibc/deploy/images/MACHINE/`
as `rpb-desktop-image-MACHINE.ext4`.

### Flashing build artifacts:

1. [Dragonboard410c](../DragonBoard-410c/BuildSource/open_embedded.md#flashing-build-artifacts)
2. [Hikey](../HiKey/BuildSource/open_embedded.md#flashing-build-artifacts)

Then, you can finally start the X server and run any graphical application:

```shell
X&
export DISPLAY=:0
glxgears
```
The default X11 image includes `openbox` window manager, to use it:

```shell
X&
export DISPLAY=:0
openbox &
glxgears
```
Of course, you can easily add another window manager, such as `metacity` in the image. To install `metacity` in the image, add the following to `conf/auto.conf` file:

    CORE_IMAGE_EXTRA_INSTALL += "metacity"

and rebuild the `rpb-desktop-image` image and flash again, it will now include `metacity`, which can be started like this:

```shell
X&
export DISPLAY=:0
metacity&
glxgears
```
# Build a sample Wayland/Weston image

For Wayland/weston, it is needed to change the DISTRO and use `rpb-wayland` instead of `rpb`. The main reason is that in 
the `rpb-wayland` distro, the support for X11 is completely removed. So, in a new terminal prompt, setup a new environment 
and make sure to use `rpb-wayland` for DISTRO, then, you can run a sample image with:

```shell
$ bitbake rpb-weston-image
```
This image includes a few additional features, such as `systemd`, `connman` which makes it simpler to use. 
Once built, the image will be available at `tmp-rpb-glibc/deploy/images/MACHINE/` as 
`rpb-weston-image-MACHINE.ext4`. 

### Flashing build artifacts:

1. [Dragonboard410c](../DragonBoard-410c/BuildSource/open_embedded.md#flashing-build-artifacts)
2. [Hikey](../HiKey/BuildSource/open_embedded.md#flashing-build-artifacts)

If you boot this image on the board, you should get a command prompt on the HDMI monitor. A user called `linaro` exists 
(and has no password). Once logged in a VT, you run start weston with:

    weston-launch

And that should get you to the Weston desktop shell.

