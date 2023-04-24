---
title: Build Source for Developerbox
permalink: /documentation/enterprise/developerbox/build/
---
# Table of Contents

   * [Build SCP Firmware From Source](#build-scp-firmware-from-source)
      * [Prerequisites and Cloning the Source](#prerequisites-and-cloning-the-source)
      * [Build SCP Firmware](#build-scp-firmware)
      * [Install the SCP Firmware](#install-the-scp-firmware)
   * [Build System Firmware From Source (U-Boot)](#build-system-firmware-from-source-u-boot)
      * [Preparation](#preparation)
      * [Cloning the sources](#cloning-the-sources)
      * [Build OP-TEE](#build-op-tee)
      * [Build TF-A](#build-tf-a)
      * [Build FIP image](#build-fip-image)
      * [Build U-Boot](#build-u-boot)
      * [Install the System Firmware](#install-the-system-firmware)
         * [UART connection](#uart-connection)
         * [DIP Switch](#dip-switch)
         * [Install firmware via NOR flash writer](#install-firmware-via-nor-flash-writer)
         * [Write the images via NOR flash writer](#write-the-images-via-nor-flash-writer)
      * [Post installation and update](#post-installation-and-update)
   * [Build System Firmware From Source (EDK2)](#build-system-firmware-from-source-edk2)
      * [Preparation](#preparation-1)
      * [Cloning the sources](#cloning-the-sources-1)
      * [Rebuild Trusted Firmware](#rebuild-trusted-firmware)
      * [Build EDK2](#build-edk2)
      * [Install the System Firmware](#install-the-system-firmware-1)
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
OUT=$ROOT/build/synquacer/GNU/$MODE
ROMFW_FILE=$OUT/firmware-scp_romfw/bin/synquacer-bl1.bin
RAMFW_FILE=$OUT/firmware-scp_ramfw/bin/synquacer-bl2.bin
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

# Build System Firmware From Source (U-Boot)

The System Firmware consists of Trusted Firmware, U-Boot and the
supporting Developerbox drivers and configuration.

Note: *This instruction manual expects the host machine is x86-64 PC with Ubuntu 20.04 LTS.
Usually required storage size for build is less than 3GB.*

## Preparation

Firstly, in addition to the "normal" build tools you will also need a
few specialist tools. On a Ubuntu operating system try:

~~~ sh
sudo apt install python python3 python3-distutils bison flex buildessential \
gcc-aarch64-linux-gnu uuid-dev acpica-tools doxygen python3-pyelftools \
python3-pycryptodome efitools python3-openssl minicom git curl ninja-build
~~~

Secondly, create a new working directory and store the absolute path to
this directory in an environment variable, `WORKSPACE`. It does not
matter where this directory is created but as an example:

~~~ sh
export WORKSPACE=$HOME/build/developerbox-firmware
mkdir -p $WORKSPACE
~~~

## Cloning the sources

Run the following commands to clone the source code:

~~~ sh
cd $WORKSPACE
git clone https://github.com/OP-TEE/optee_os.git -b 3.15.0 --depth=1
git clone https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git -n
git clone https://source.denx.de/u-boot/u-boot.git -n

cd $WORKSPACE/trusted-firmware-a
git checkout f7f5d2c4cd209c2d21244da4fa442050eb4531ab
cd $WORKSPACE/u-boot
git checkout 0171d056ec8b9be9d90af64adce54c6a5571dd15
~~~

## Build OP-TEE

Build OP-TEE OS from source as below.

~~~ sh
cd $WORKSPACE/optee_os
OPTEE_CROSS_COMPILE=aarch64-linux-gnu-
make -j`nproc` PLATFORM=synquacer ARCH=arm CFG_ARM64_core=y \
 CFG_CORE_ARM64_PA_BITS=48 CFG_CORE_HEAP_SIZE=524288 \
 CFG_CORE_DYN_SHM=y \
 CFG_CRYPTO_WITH_CE=y CFG_TEE_CORE_LOG_LEVEL=1 \
 CFG_TEE_TA_LOG_LEVEL=1 \
 CROSS_COMPILE=${OPTEE_CROSS_COMPILE} \
 CROSS_COMPILE64=${OPTEE_CROSS_COMPILE}

cp out/arm-plat-synquacer/core/tee-pager_v2.bin $WORKSPACE/tee-pager_v2.bin
~~~

Then, you'll get "$WORKSPACE/tee-pager_v2.bin", which is the OP-TEE OS image.
(This is finally embedded in the FIP image with TFA.)

## Build TF-A

Build TF-A from source as below.

~~~ sh
cd $WORKSPACE/trusted-firmware-a
make CROSS_COMPILE=aarch64-linux-gnu- -j`nproc` PLAT=synquacer \
 SQ_USE_SCMI_DRIVER=1 PRELOADED_BL33_BASE=0x8200000 \
 RESET_TO_BL31=1 SPD=opteed bl31 fiptool
~~~

## Build FIP image

Packaging TF-A and OP-TEE in a FIP image.

~~~ sh
cd $WORKSPACE/trusted-firmware-a
dd if=/dev/zero of=dummy.bin bs=4 count=1
tools/fiptool/fiptool -v create \
 --tb-fw ./build/synquacer/release/bl31.bin \
 --soc-fw dummy.bin \
 --scp-fw dummy.bin \
 --tos-fw $WORKSPACE/tee-pager_v2.bin \
 $WORKSPACE/fip_all_arm_tf.bin
~~~

Finally, you'll get a FIP image "$WORKSPACE/fip_all_arm_tf.bin" for writing on the flash.

## Build U-Boot

Build U-Boot bootloader from source as below.

~~~ sh
cd $WORKSPACE/u-boot
export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
make synquacer_developerbox_defconfig
make -j `nproc`
cp u-boot.bin $WORKSPACE/SPI_NOR_UBOOT.fd
truncate -s `expr 1024 \* 1024` $WORKSPACE/SPI_NOR_UBOOT.fd
~~~

Then, you'll get "$WORKSPACE/SPI_NOR_UBOOT.fd", 1MB raw flash image.

## Install the System Firmware

### UART connection

Connect the Developerbox and host PC.

* [AP UART] Connect a micro USB on the back-panel of Developerbox.
   * There is a micro USB port behind the back panel (remove the back panel).
* [SCP UART] Connect a 96boards UART mezzanine to the 96board LS connector (40pin connector next to the DIMM4 slot) on the board.
   * Install the mezzanine card with the micro USB port facing the DIMM slot (you might need to remove the DIMM from DIMM4 slot, or you can use "L" type micro USB connector).
   * The jumper pins on the mezzanine must choose UART0 (To select UART0: place jumpers between pins 1--3 and 2--4).

Both UART serial settings are same, 115200 8N1. No flow control.

We call the back-panel UART as AP UART, and 96boards UART as SCP UART.

### DIP Switch

Developerbox has 4 Dip Switch(DSW) modules.

You can find DSW modules next to the DIMM4 slot.
From the PCIe slot side, there are DSW4, DSW1, DSW2, and DSW3.
(the name is printed on the board)

DSW2 is used from bootstrap, DSW3 is used from SCP firmware and TF-A.
By default, the DSW3-3 is off, but please set the DSW3-3 on for enabling OP-TEE.

| DSW  | Configure(0=off, 1=on) | Description |
| :--- | :--- | :--- |
| 1 | 00000000 | Reserved |
| 2 | 00111100 | Boot mode selector<br> DSW 2-7 boots NOR flash writer |
| 3 | 00000100 | Software mode selector<br> DSW 3-3 enables OP-TEE support |
| 4 | 00000000 | Reserved |

### Install firmware via NOR flash writer
Initially install the firmware (U-Boot), you have to use the NOR flash writer via SCP UART.
If your Developerbox already uses U-Boot, you can use capsule update method.

List of images

There are 3 image files to be written via NOR flash writer.

| File | Image | Write command |
| :--- | :--- | :--- |
| scp_romramfw_debug.bin or scp_romramfw_release.bin | SCP firmware image | flash write cm3 |
| fip_all_arm_tf.bin | FIP image (TF-A and OP-TEE) | flash rawwrite 180000 78000 |
| SPI_NOR_UBOOT.fd | U-Boot image | flash rawwrite 200000 100000 |

### Write the images via NOR flash writer

1. Open the terminal soft on SCP-UART (e.g. ttyUSB0) on host PC
    ~~~
    minicom -D /dev/ttyUSB0
    ~~~
2. Set DSW 2-7 on
3. Power on (or reset) the Developerbox
4. You'll see the NOR flasher on the terminal
    ~~~
    /*------------------------------------------*/
    /* SC2A11 "SynQuacer" series Flash writer */
    /* */
    /* Version: cd254ac */
    /* Build: 12/15/17 11:25:45 */
    /*------------------------------------------*/
    Command Input >
    ~~~
5. Write the images with X-modem.
    Run following command,
    ~~~
    flash write cm3
    ~~~
    push "Ctrl+a s" and choose "xmodem", and choose "scp_romramfw_debug.bin"
    or "scp_romramfw_release.bin"
6. Run following command,
    ~~~
    flash rawwrite 180000 78000
    ~~~
    push "Ctrl+a s" and choose "xmodem", and choose "fip_all_arm_tf.bin"
7. Run following command,
    ~~~
    flash rawwrite 200000 100000
    ~~~
    push "Ctrl+a s" and choose "xmodem", and choose "SPI_NOR_UBOOT.fd"
8. Set DSW 2-7 off
9. Power off the Developerbox (Press and hold the power button for 5 seconds)

## Post installation and update
After installing (or updating) the U-Boot, at the first boot time, you may
need to reset the environmental variables as below.
(Of course if you want to keep your original settings, you can skip this)

~~~
(uboot)=> env default -a
(uboot)=> env save
~~~

# Build System Firmware From Source (EDK2)

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

build -p $ACTIVE_PLATFORM -b RELEASE -a AARCH64 -t GCC5 -n `nproc` -D X64EMU_ENABLE=TRUE
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
