---
title: Linux Host Installation for ROCK960
permalink: /documentation/consumer/rock/rock960/installation/linux-sd.md.html
redirect_from: /documentation/consumer/rock960/installation/linux-sd.md.html
---

## Linux Host

This section show how to install an operating system to your ROCK960 using the SD Card method on a Linux host computer.
***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Find SD Card Device name
- **Step 3**: Recall Download Location
- **Step 4**: Unzip _SD Card Install Image_
- **Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal
- **Step 6**: Locate SD Card Install Image
- **Step 7**: Install Image onto SD Card
- **Step 8**: Prepare ROCK960 with SD card

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Find SD Card Device name

- Use host computer
- Open "Terminal" application
- Remove SD card from host computer and run the following command:
```shell
$ lsblk
```
- Note all recognized disk names
- **Insert SD card** and run the following command (again):
```shell
$ lsblk
```
- Note the newly recognized disk. This will be your SD card.
- **Remember** your SD card device name, it will be needed in **Step 7**.

####**Step 3**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 4**: Unzip _SD Card Install Image_

- When unzipped, you will have a folder with the following contents:
   - Loader (rk3399_loader_v1.08.106.bin) we don't need it for SD card writing here.
   - Install Image (system.img)
   - readme.md

####**Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal

- Use host computer
- Open "Terminal" application
- `cd` to the directory with your unzipped **SD Card Install Image**

```shell
$ cd <extraction directory>

#Example:
#<extraction directory> = /home/YourUserName/Downloads
#For this example we assume the "SD Card Install Image" is in the Downloads folder.
$ cd /home/YourUserName/Downloads
```

####**Step 6**: Locate SD Card Install Image

- Make sure you are in the extraction directory

**Unzipped SD Card download will be a folder. This folder should be listed in your directory. Type `ls` from command line for a list of files that can be found in your current directory**:

```shell
$ ls

#output
rock960_ubuntu_server_16.04_arm64_20180115
```

- Unzipped folder should be called rock960_YY_arm64_XX, where Y can be Android of Debian and XX represents the release number
- `cd` into this directory

```shell
$ cd rock960_ubuntu_server_16.04_arm64_20180115
```

- Inside this folder you will find the install image
   - `system.img`
- This `.img` file is what will be flashed to your SD Card.

####**Step 7**: Install Image onto SD Card

**Checklist:**

- SD card inserted into host computer
- Recall SD Card device name from **Step 2**
- From within the rock960_YY_arm64_XX folder, using the Terminal execute the following commands:

**Execute:**

```shell
$ sudo dd if=system.img of=/dev/XXX bs=4M oflag=sync status=noxfer
```

**Note:**

- `if=system.img`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the SD Card device name from **Step 2**. Be sure to use the device name with out the partition.
- This command will take some time to execute. Be patient and avoid tampering with the terminal until process has ended.
- Once SD card is done flashing, remove from host computer and set aside for **Step 8**

####**Step 8**: Prepare ROCK960 with SD card

- Make sure ROCK960 is unplugged from power
- Connect an HDMI monitor to the ROCK960 with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the ROCK960
- Insert the microSD card into the ROCK960
- Plug power adaptor into ROCK960, wait for board to boot up.

**Congratulations! You are now booting your newly installed operating system running on SD card on the ROCK960!**
