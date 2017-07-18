---
title: Create Swap Space on an SD Card
permalink: /documentation/ConsumerEdition/CE-Extras/Configuration/SDSwapSpace.md/
---
# Create Swap Space on an SD Card

## Hardware

- 96Boards Consumer Edition board
- microSD Card with 8GB or more

**Insert blank microSD Card into the SD Card clot on your 96Boards, partition and mount**

## Software

- Linaro Debian Operating system

## Steps

### Format microSD Card

The following command and prompt will allow you to format your microSD card, this will prepare it to be used as swap space

```shell
$ sudo gdisk /dev/mmcblk1
```

You will be presented with the following prompts. Use provided inputs. Where an input is not offered, simply press < Enter >

```shell
Command (? for help): o
This option deletes all partitions and creates a new protective MBR.
Proceed? (Y/N): y

Command (? for help): n
Partition number (1-128, default 1): <Enter>
First sector (34-123764702, default = 2048) or {+-}size{KMGTP}: <Enter>
Last sector (2048-123764702, default = 123764702) or {+-}size{KMGTP}: 8G
Current type is 'Linux filesystem'
Hex code or GUID (L to show codes, Enter = 8300): 8200
Changed type of partition to 'Linux swap'

Command (? for help): n
Partition number (1-128, default 2): <Enter>
First sector (34-123764702, default = 16779264) or {+-}size{KMGTP}: <Enter>
Last sector (2048-123764702, default = 123764702) or {+-}size{KMGTP}: <Enter>
Current type is 'Linux filesystem'
Hex code or GUID (L to show codes, Enter = 8300): <Enter>
Command (? for help): w
Final checks complete. About to write GPT data. THIS WILL OVERWRITE EXISTING
PARTITIONS!!
Do you want to proceed? (Y/N): y
```
               

### Reboot and setup swap space

```shell
$ sudo reboot now
$ sudo mkfs –t ext4 /dev/mmcblk1p2
$ sudo mkswap /dev/mmcblk1p1
```

### Edit /etc/fstab and add the following line

```shell
$ sudo vim /etc/fstab

## Add the following line
/dev/mmcblk1p1 none swap sw 0 0

## this will save and exit you out of vim
<esc>:wq
```

### Reboot and run the following command

```shell
## Ensure swap is mounted

$ sudo reboot now
$ free
```
