---
title: Build Source for Developerbox
permalink: /documentation/enterprise/developerbox/build/
---
# Table of Contents

   * [Build SCP Firmware From Source](#build-scp-firmware-from-source)
      * [Prerequisites and Cloning the Source](#prerequisites-and-cloning-the-source)
      * [Build SCP Firmware](#build-scp-firmware)
      * [Install the SCP Firmware](#install-the-scp-firmware)
   * [Build System Firmware From Source](#build-system-firmware-from-source)
      * [Preparation](#preparation)
      * [Cloning the sources](#cloning-the-sources)
      * [Rebuild Trusted Firmware](#rebuild-trusted-firmware)
      * [Build EDK2](#build-edk2)
      * [Install the System Firmware](#install-the-system-firmware)
   * [Build Linux From Source](#build-linux-from-source)

<!-- Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc) -->

***

# Build SCP Firmware From Source

Developerbox contains a Cortex-M3 System Control Processor(SCP) which manages
system power and is responsible for booting the main processor.

## Prerequisites and Cloning the Source

Follow the SCP-firmware User Guide for required softwares and
cloning the source code.

https://github.com/ARM-software/SCP-firmware/blob/master/user_guide.md

## Build SCP Firmware

SCP Firmware consists of romfw and ramfw. The following build script
make both firmwares and concatenate two binaries into one binary
to easily update NOR Flash of Developerbox.

~~~ sh
#!/usr/bin/env bash

ROOT=./
MODE=debug    # debug or release
CC=arm-none-eabi-gcc
OUT=$ROOT/build/product/synquacer
ROMFW_FILE=$OUT/scp_romfw/$MODE/bin/scp_romfw.bin
RAMFW_FILE=$OUT/scp_ramfw/$MODE/bin/scp_ramfw.bin
ROMRAMFW_FILE=$OUT/scp_romramfw_$MODE.bin

make -f Makefile.cmake CC=$CC PRODUCT=synquacer MODE=$MODE
tr "\000" "\377" < /dev/zero | dd of=${ROMRAMFW_FILE} bs=1 count=196608
dd if=${ROMFW_FILE} of=${ROMRAMFW_FILE} bs=1 conv=notrunc seek=0
dd if=${RAMFW_FILE} of=${ROMRAMFW_FILE} bs=1 seek=65536
~~~
Note: *This manually built SCP Firmware only supports SCMI to communicate with Trusted Firmware-A.
      Clone the [latest Trusted Firmware][2] and add "SQ_USE_SCMI_DRIVER=1" build option
      in building Trusted Firmware.*

[2]: https://github.com/ARM-software/arm-trusted-firmware

## Install the SCP Firmware

You can install SCP firmware using the [Low-level(CM3) firmware recovery](../installation/board-recovery.md#low-level-cm3-firmware-recovery).

***

# Build System Firmware From Source

The System Firmware consists of Trusted Firmware, EDK2 and the
supporting Developerbox drivers and configuration.

Note: *The instructions for building the system firmware will work, 
      without modification, both and x86 PC and on your Developerbox.*


## Preparation

Firstly, in addition to the "normal" build tools you will also need a
few specialist tools. On a Debian or Ubuntu operating system try:

~~~
sudo apt install acpica-tools device-tree-compiler uuid-dev
~~~

Secondly, create a new working directory and store the absolute path to
this directory in an environment variable, `WORKSPACE`. It does not
matter where this directory is created but as an example:

~~~
export WORKSPACE=$HOME/build/developerbox-firmware
mkdir -p $WORKSPACE
~~~

## Cloning the sources

Run the following commands to clone the source code:

~~~
cd $WORKSPACE
git clone git://git.linaro.org/leg/noupstream/arm-trusted-firmware.git -b synquacer
git clone git://git.linaro.org/leg/noupstream/edk2-platforms.git -b developer-box
git clone git://git.linaro.org/leg/noupstream/edk2-non-osi.git -b developer-box
git clone git://git.linaro.org/leg/noupstream/edk2.git -b developer-box --recursive
~~~

## Rebuild Trusted Firmware

Next we may, optionally, compile the EL3 firmware and related
early stage bootloaders for Developerbox. If this step is skipped EDK2
will incorporate a [pre-compiled binary][1] into the resulting
system firmware image.

[1]: https://git.linaro.org/leg/noupstream/edk2-non-osi.git/tree/Platform/Socionext/DeveloperBox/README?h=developer-box
repository.

~~~ sh
cd $WORKSPACE/arm-trusted-firmware
make -j `nproc` \
	CROSS_COMPILE=aarch64-linux-gnu- \
	PLAT=synquacer \
	PRELOADED_BL33_BASE=0x8200000 \
	bl31 fiptool
tools/fiptool/fiptool create \
	--tb-fw ./build/synquacer/release/bl31.bin \
	--soc-fw ./build/synquacer/release/bl31.bin \
	--scp-fw ./build/synquacer/release/bl31.bin \
	../edk2-non-osi/Platform/Socionext/DeveloperBox/fip_all_arm_tf.bin
~~~

## Build EDK2

At this stage we are ready to compile the full firmware image:

~~~ sh
cd $WORKSPACE
export PACKAGES_PATH=$WORKSPACE/edk2:$WORKSPACE/edk2-platforms:$WORKSPACE/edk2-non-osi
export ACTIVE_PLATFORM="Platform/Socionext/DeveloperBox/DeveloperBox.dsc"
export GCC5_AARCH64_PREFIX=aarch64-linux-gnu-
unset ARCH

. edk2/edksetup.sh
make -C edk2/BaseTools

build -p $ACTIVE_PLATFORM -b RELEASE -a AARCH64 -t GCC5 -n `nproc` -D DO_X86EMU=TRUE
~~~

The firmware image, which comprises the option ROM, ARM trusted
firmware and EDK2 itself, can be found
`$WORKSPACE/../Build/DeveloperBox/RELEASE_GCC5/FV/`. Use
`SYNQUACERFIRMWAREUPDATECAPSULEFMPPKCS7.Cap` for UEFI capsule update
and `SPI_NOR_IMAGE.fd` for the serial flasher.

Note #1: *`-t GCC5` can be loosely translated as "enable
         link-time-optimization"; any version of gcc >= 5 will
	 support this feature and may be used to build EDK2*.

Note #2: *Replace `-b RELEASE` with `-b DEBUG` to build a debug.*

## Install the System Firmware

Providing your Developerbox is fully working and has on operating system
installed then you can adopt your the newly compiled system firmware
using the capsule update method:

~~~
sudo apt install fwupdate
sudo fwupdate --apply {50b94ce5-8b63-4849-8af4-ea479356f0e3} \
              SYNQUACERFIRMWAREUPDATECAPSULEFMPPKCS7.Cap
sudo reboot
~~~

Alternatively you can install `SPI_NOR_IMAGE.fd` using the [board recovery method](../installation/board-recovery.md).

***

# Build Linux From Source

Linux v4.16 has comprehensive support for Developerbox (and v4.15 has
support for everything except the on-board network adapter).

With full upstream support already available there are no special
instructions for compiling Linux for Developerbox. If you wish to build
a new kernel for your Developerbox we recommend you follow the
instructions applicable to the distribution you have selected.

Alternatively, advanced users who already have the appropriate compilers
and headers files installed, may find following generic template useful:

~~~
git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
cd linux
make defconfig
scripts/config --enable ARCH_SYNQUACER --enable SNI_NETSEC \
               --enable GPIO_MB86S7X   --enable MMC_SDHCI_F_SDH30
make -j `nproc`
sudo make install modules_install
~~~

The template above assumes a self-hosted build. If you are **not**
building on an AArch64 workstation then you must set `ARCH` and
`CROSS_COMPILE` appropriately.*

Finally, if you' are the kind of kernel hacker that works on code that
might stop the kernel from booting cleanly, early console support can be
enabled on the Developerbox (regardless of whether or not Graphical
console is enabled) with the following options:

~~~
earlycon=pl011,0x2a400000,115200
~~~
