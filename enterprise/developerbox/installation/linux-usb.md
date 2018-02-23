---
title: GNU/Linux Host Installation for Developerbox
permalink: /documentation/enterprise/developerbox/installation/linux-usb.md.html
---
## GNU/Linux Host

This section show how to install an operating system to your
Developerbox.
***

- **Step 1**: Prepare USB Stick
- **Step 2**: Find USB Stick Device name
- **Step 3**: Recall Download Location
- **Step 4**: Go to directory with _ISO Installer Image_ folder using Terminal
- **Step 5**: Install Image onto USB Stick
- **Step 6**: Boot Developerbox from the USB Stick

***

#### Step 1: Prepare USB Stick

- Ensure data from USB Stick is backed up
- Everything on USB Stick will be lost by the end of this procedure.

#### Step 2: Find USB Card Device name

- Use host computer
- Open "Terminal" application
- Remove USB Stick from host computer and run the following command:
```shell
$ lsblk
```
- Note all recognized disk names
- **Insert USB Stick** and run the following command (again):
```shell
$ lsblk
```
- Note the newly recognized disk. This will be your USB Stick.
- **Remember** your USB Stick device name, it will be needed in **Step 5**.

#### Step 3: Recall Download Location

- Locate USB Stick install file from [Downloads page](../downloads/).
- This file will be needed for the next step.

#### Step 4: Go to directory with _USB Stick Install Image_ folder using Terminal

- Use host computer
- Open "Terminal" application
- `cd` to the directory containing your **USB Stick Install Image**

```shell
$ cd <directory>

#Example:
#<directory> = /home/YourUserName/Downloads
#For this example we assume the "USB Stick Install Image" is in the Downloads folder.
$ cd /home/YourUserName/Downloads
```

#### Step 5: Install Image onto USB Stick

**Checklist:**

- USB Stick inserted into host computer
- Recall USB Stick device name from **Step 2**
- From within the correct directory, using the Terminal execute the following commands:

**Execute:**

```shell
$ sudo dd if=YourInstallerImage.iso of=/dev/XXX bs=4M oflag=sync status=noxfer
```

**Note:**

- `if=YourInstallerImage.iso`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the USB Stick device name from **Step 2**. Be sure to use the device name with out the partition.
- This command will take some time to execute. Be patient and avoid tampering with the terminal until process has ended.
- Once USB Stick is done flashing, remove from host computer and set aside for **Step 6**

#### Step 6: Boot Developerbox from the USB Stick

- Make sure Developerbox is unplugged from power
- Connect an monitor to the Developerbox, and power on the monitor
- Plug a USB keyboard and/or mouse into one of the USB connectors on the Developerbox
- Insert the USB Stick the Developerbox
- Plug power adaptor into Developerbox and press Escape to interrupt the
  boot process
- Go to **Boot Manager** and select the appropriate device and press Return

**Congratulations! You are now running your operating system installer. It's time to switch to the Installation Guide for your chosen operating system!**
