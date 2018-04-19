---
title: GNU/Linux installer preparation for Developerbox
permalink: /documentation/enterprise/developerbox/installation/linux-usb.md.html
---
## GNU/Linux Host

This section show how to prepare a bootable USB stick.
***

- **Step 1**: Prepare USB stick
- **Step 2**: Find USB stick device name
- **Step 3**: Recall download location
- **Step 4**: Go to directory with _ISO Installer Image_ folder using Terminal
- **Step 5**: Install image onto USB stick

***

#### Step 1: Prepare USB stick

- Ensure data from USB stick is backed up
- Everything on USB stick will be lost by the end of this procedure.

#### Step 2: Find USB stick device name

- Use host computer
- Open "Terminal" application
- Remove USB stick from host computer and run the following command:
```shell
$ lsblk
```
- Note all recognized disk names
- **Insert USB stick** and run the following command (again):
```shell
$ lsblk
```
- Note the newly recognized disk. This will be your USB stick.
- **Remember** your USB stick device name, it will be needed in **Step 5**.

#### Step 3: Recall Download Location

- Locate USB stick install file from [Downloads page](../downloads/).
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

#### Step 5: Install image onto USB stick

**Checklist:**

- USB stick inserted into host computer
- Recall USB stick device name from **Step 2**
- From within the correct directory, using the Terminal execute the following commands:

**Execute:**

```shell
$ sudo dd if=YourInstallerImage.iso of=/dev/XXX bs=4M oflag=sync status=noxfer
```

**Note:**

- `if=YourInstallerImage.iso`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the USB stick device name from **Step 3**. Be sure to use the device name without the partition.
- This command will take some time to execute. Be patient and avoid tampering with the terminal until process has ended.
- Once USB stick is done flashing, remove from host computer and set aside.

**Congratulations! Your USB stick is ready. Switch back to the [Installation Guide](README.md#boot-into-the-installer) to boot into the installer!**
