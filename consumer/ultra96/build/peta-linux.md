---
title: PetaLinux Build Guide for Ultra96
permalink: /documentation/consumer/ultra96/build/peta-linux.md.html
---

# PetaLinux

PetaLinux provides a complete, reference Linux distribution that has been integrated and tested for Xilinx devices. The reference Linux distribution includes both binary and source Linux packages including:

- Boot loader
- CPU-optimized kernel
- Linux applications & libraries
- C & C++ application development
- Debug
- Thread and FPU support
- Integrated web server for easy remote management of network and firmware configurations.

[Learn More...](https://www.xilinx.com/products/design-tools/embedded-software/petalinux-sdk.html)

# Download Required Files

Download the following files from [Xilinx Download Page](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html). You will need to create a Xilinx account.

- 1) PetaLinux 2018.2 Installer
- 2) Ultra96 BSP

# System Requierments

- Host OS: Ubuntu 16:04 LTS
- CPU: 4 core or more recommended
- RAM: Minimum 8GB
- Storage: 30GB or more
- Internet Connection

# Install PetaLinux SDK

- Run the installer:
  ```
  $ ./petalinux-v2018.2-final-installer.run <install-directory-of-choice>/peta
  ```
- Accept License Agreements when prompted.
- Done!

# Build The PetaLinux Distribution

## Create a new project
- Setup PetaLinux Environment
  ```
  $ cd <petalinux-install-directory>
  $ source peta/settings.sh
  ```
- Create Project from Ultra96 BSP
  ```
  $ petalinux-create -t project -s <path-to>/xilinx-ultra96-reva-v2018.2-final.bsp
  ```

## Start the Build
```
$ cd xilinx-ultra96-reva-2018.2/
$ petalinux-build
```
- Grab a cup of coffee... this might take a while.

## Create BOOT.BIN

```
$ petalinux-package --boot --fsbl components/plnx_workspace/fsbl/fsbl/Release/fsbl.elf --fpga hardware/xilinx-ultra96-reva-2018.2/xilinx-ultra96-reva-2018.2.runs/impl_1/design_1_wrapper.bit --pmufw components/plnx_workspace/pmu-firmware/pmu-firmware/Release/pmu-firmware.elf --u-boot
```

# Flash micro-SDCard

**All files required for this step will be present at <project-dir>/images/linux/ once the build is completed**

- Format the SD Card with the following layout. To do this you can use tools such as fdisk, GParted, gnome-disks etc.
  - Partition 1:
    - Format: FAT32
    - Size: 1GB
    - Label: boot
  - Partition 2:
    - Format: ext4
    - Size: 4GB or more
    - Label: rootfs

- Copy Boot files
  ```
  $ cd <project-dir>/images/linux/
  $ cp BOOT.BIN <mount-point-for-boot>
  $ cp image.ub <mount-point-for-boot>
  ```
- Flash rootfs Partition
  ```
  $ sudo dd if=rootfs.ext4 of=/dev/sdX2
  $ sync
  ```

***

#### Once the installation is complete safely remove the sdcard and insert into your Ultra96 and power-on, you should see PetaLinux boot.

#### For a more detailed look at PetaLinux SDK take a look at [this documentation from Xilinx](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2018_2/ug1144-petalinux-tools-reference-guide.pdf).

#### Also take a look at a Video Tutorial of this entire process:

{% include media.html media_url="https://youtu.be/x6xbFGmwxoQ" %}
