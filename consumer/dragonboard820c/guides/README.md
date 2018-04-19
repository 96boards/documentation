---
title: Useful DragonBoard 820c Guides
permalink: /documentation/consumer/dragonboard820c/guides/
---
# Useful Guides

These guides will help to get you started with a variety of available on-boards software

## Onboard storage

The Dragonboard 820c has a 32GB UFS drive and the drive is physically partitioned like this, when using the default UFS provision scheme released by 96boards.

    Disk /dev/sda: 6335488 sectors, 24.2 GiB
    Disk /dev/sdb: 1024 sectors, 4.0 MiB
    Disk /dev/sdc: 1024 sectors, 4.0 MiB
    Disk /dev/sdd: 32768 sectors, 128.0 MiB
    Disk /dev/sde: 1048576 sectors, 4.0 GiB
    Disk /dev/sdf: 393216 sectors, 1.5 GiB

The UFS provisioning is very much tied to some of the proprietary bootloader, and internal SoC ROM code. While it is possible to change the UFS provisioning scheme, it is not recommended for now. For a full description of the default LUNs configuration, you can check https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git/tree/dragonboard820c/ufs-provision_toshiba.xml.

Each *disk* on the provisioned UFS drive is used for various purpose throughout the boot, and each *disk* contain a set of predefined partitions. We release several partition schemes for different use cases.

### Linux default partition scheme

This is the default partition scheme recommended to be used when running a GNU/Linux operating system, such as the reference images released by Linaro, based on Debian or OpenEmbedded. 

The main useful partitions for now are : 

* `/dev/sda1` is `rootfs`. It is ~24GB, and should be used to flash the rootfs
* `/dev/sde17` is `boot`. It should be used to flash the kernel/boot image.

For a complete description of all partitions, for each LUN, please check https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git/tree/dragonboard820c/linux/partition.xml.

### AOSP default partition scheme

This is the default partition scheme recommended to be used when running Android AOSP.

The main useful partitions for now are : 

* `/dev/sda1` is `system`. It is ~4GB
* `/dev/sda2` is `cache`. It is ~1GB
* `/dev/sda3` is `vendor`. It is ~2GB
* `/dev/sda4` is `swap`. It is ~2GB
* `/dev/sda5` is `userdata`. It is ~15GB
* `/dev/sde17` is `boot`. 

For a complete description of all partitions, for each LUN, please check https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git/tree/dragonboard820c/aosp/partition.xml.

## Building the SD rescue image

The scripts to build the SD rescue image can be found here:

* https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-bootloader-dragonboard820c.yaml, where we defined the script parameters and variables
* https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-bootloader/dragonboard820c/builders.sh: where the actual commands are being executed.

It should be fairly straight forward to run these scripts locally and customize then as needed. In case of troubles, feel free to ask support on the 96boards forum.
