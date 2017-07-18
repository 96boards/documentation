---
title: Linux SD for B2260
permalink: /documentation/ConsumerEdition/B2260/Installation/LinuxSD.md/
---
## Linux Host

This section describes the process for installing a new Operating System using the SD Card method on a Linux host machine.

***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Find SD Card Device name
- **Step 3**: Recall Download Location
- **Step 4**: Unzip _SD Card Install Image_
- **Step 5**: Go to directory with _SD Card Install Image_ directory via the commandline
- **Step 6**: Locate SD Card Install Image
- **Step 7**: Install Image onto SD Card
- **Step 8**: Prepare B2260 with SD card

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Find SD Card Device name

- From the host computer open "Terminal" (or equivalent) application
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

- When unzipped, you will have a file:
   - Install Image (.img)

####**Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal

- Open "Terminal" application on host machine
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
- Locate your preferred image file (latest one maybe the best option)

**Unzipped SD Card download will be a file.** Type `ls` from command line :

```shell
ls

#output
b2260-jessie_developer_YYYYMMDD-X.img
```

####**Step 7**: Flash Image onto SD Card

**Checklist:**

- SD card inserted into host computer
- Recall SD card device name from [**Step 2**]()
- Using the Terminal to copy b2260-jessie_developer_YYYYMMDD-X.img image file into SD card by running the following commands:

**Execute:**

```shell
$ sudo dd if=b2260-jessie_developer_YYYYMMDD-X.img of=/dev/XXX bs=4M
$ sudo sync
```

**Note:**

- `if=b2260-jessie_developer_YYYYMMDD-X.img`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the SD Card device name from **Step 2**. Be sure to use the device name without the partition name. For example, 'of=/dev/disk1'
- If you get an error message "Resource Busy", you will need to unmount the SD card without removing it from the host computer.

  Option 1:
  - In the Applications folder, find and click on the Utilities folder.
  - Click on the Disk Utility program to run it
  - Select the device that represents the SD card
  - Click on `unmount` and leave the SD card in the computer
  - Retry the '$ sudo dd if=b2260-jessie_developer_YYYYMMDD-X.img of=/dev/XXX bs=4M'

  Option 2:
  - In the terminal window, enter this command:
```shell
$ sudo umount /dev/<device name>
```

- This command will take some time to execute (a few minutes). Be patient and avoid tampering with the terminal until process has ended.
- Once SD card is done flashing, remove from host computer and set aside for **Step 8**. You may see a popup window that tells you the device is _Not readable by the operating system_. Ignore the message and remove the MicroSD card from the host computer.

####**Step 8**: Prepare B2260 with SD card

- Make sure B2260 is powered off
- Connect an HDMI monitor to the B2260 with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the B2260
- Insert the microSD card into the B2260
- Apply power to B2260, wait for board to boot

**Congratulations! You are now booting your newly installed operating system directly from SD card on the B2260!**
