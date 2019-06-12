---
title: Expand Root Filesystem on Rock960 Ubuntu Images
permalink: /documentation/consumer/rock/guides/expand-rootfs.md.html
---

# Expand Root Filesystem Size under Ubuntu for Rock960

After a fresh install you may notice that your `root` partition is only around 1.5GB in size, even if the emmc or sdcard is much larger.

To expand the size of the rootfs in order to fill up the emmc or sdcard, we need to perform the foloowing steps.

Run the following commands on a Rock960 with Ubuntu installed

- `parted /dev/mmcblk1`
- Print Current Partition Table: `(parted) p`
- If asked, select `Fix`
- It should show a list of partitions
```
Number Start End Size File system Name Flags
1 32.8kB 4129kB 4096kB loader1
2 8389kB 12.6MB 4194kB loader2
3 12.6MB 16.8MB 4194kB trust
4 16.8MB 134MB 117MB fat16 boot boot, esp
5 134MB 1.5GB 1.5GB ext4 rootfs
(parted)
```
- Resize root partition: `(parted) resizepart 5`
- When prompted with `End?`, Enter `-34s`. 34 sector is for the GPT backup 4 at the end of the disk.
- Check the new partition table now: `(parted) p`
- The rootfs should now have expanded `5 134MB 31.3GB 31.1GB ext4 rootfs`
- Quit Parted: `(parted) quit`
- Extend the filesystem: `root@linaro-alip:~# resize2fs /dev/mmcblk1p5`

Done.
