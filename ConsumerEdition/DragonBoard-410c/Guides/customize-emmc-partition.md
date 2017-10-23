---
title: Customizing eMMC partition in Linux
permalink: /documentation/ConsumerEdition/DragonBoard-410c/Guides/customize-emmc-partition.md.html
---
# Customizing eMMC partition in Linux for Dragonboard410c

This page provides information on Customizing eMMC partition in Linux for Dragonboard410c. This will allow us to host different Linux distributions in same eMMC.

# Table of Contents

- [1) Customizing Partition table](#1-customizing-partition-table)
- [2) Flashing Partition table](#2-flashing-partition-table)

***

# 1) Customizing Partition table

Customizing eMMC partition in Linux requires modification to the eMMC partition table. This can be done by the following steps:

First clone the Dragonboard boot tools
```shell
$ git clone https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git
$ cd db-boot-tools
```
Then add new partitions to the partition table in *dragonboard410c/linux/partitions.txt* file.
```shell
--- a/dragonboard410c/linux/partitions.txt
+++ b/dragonboard410c/linux/partitions.txt
@@ -6,4 +6,6 @@ hyp,512,E1A6A689-0C8D-4CC6-B4E8-55A4320FBD8A,hyp.mbn
sec,16,303E6AC3-AF15-4C54-9E9B-D9A8FBECF401,sec.dat
aboot,1024,400FFDCD-22E0-47E7-9A23-F16ED9382388,emmc_appsboot.mbn
boot,65536,20117F86-E985-4357-B9EE-374BC1D8487D,
+oe,786432
+sid,2621440
rootfs,0
```

The above diff shows that there are two partitions added to the partition table, *oe* and *sid*. You can add partition as needed, change partition sizes, but you should not change the partition UID for the existing partitions that contain the bootloader and firmware, or you might brick your board.

# 2) Flashing Partition table

After customizing the partition table, we need to create GPT binary compatible with fastboot and flash that onto Dragonboard410c.

Create an empty image (sd.img) with the modified partition table

	$ sudo ./mksdcard -g -o sd.img -p dragonboard410c/linux/partitions.txt
Create a gpt backup

	$ sudo sgdisk -bgpt.bin sd.img
Convert gpt backup into proper 'fastboot' format

	$ ./mkgpt -i gpt.bin -o gpt_both0.bin
Flash the partition table using fastboot

	$ fastboot flash partition gpt_both0.bin

> Note: Board needs to be in fastboot mode before executing the fastboot command

Now, eMMC is flashed with the custom partition table. Next step is to flash the required images into the corresponding partitions.

For instance, the following command flashes an image onto *oe* partition:

	$ flastboot flash oe rpb-desktop-image-dragonboard-410c-XXX.rootfs.img
