---
title: Mac host installer preparation for Developerbox
permalink: /documentation/enterprise/developerbox/installation/mac-usb.md.html
---
## Mac OS X Host

This section show how to prepare a bootable USB stick.
***

- **Step 1**: Prepare USB stick
- **Step 2**: Find USB stick device name
- **Step 3**: Recall Download Location
- **Step 4**: Go to directory with _USB Stick Install Image_ folder using Terminal
- **Step 5**: Install image onto USB stick

***

#### Step 1: Prepare MicroSD card

- Ensure data from USB stick is backed up
- Everything on USB stick will be lost by the end of this procedure.

#### Step 2: Find USB stick device name

- On the host computer, open "Terminal" application **(Press Command+Space bar and type "Terminal")**
- Remove USB stick from host computer and run the following command:
```shell
diskutil list
```
- Note all recognized disk names (example: /dev/disk1)
- **Insert USB stick** and run the following command (again):
```shell
diskutil list
```
- Note the newly recognized disk. This will be your USB stick.
- **Remember** your USB stick device name, it will be needed in **Step 5**.

#### Step 3: Recall Download Location

- Locate USB stick install file from [Downloads page](../downloads/).
- This file will be needed for the next step.

#### Step 4: Go to directory with _USB Stick Install Image_ folder using Terminal

- On the host computer, open the "Terminal" application **(Press Command+Space bar and type "Terminal")**
- `cd` to the directory containing your install image**

```shell
cd <directory>

#Example:
#<directory> = /Users/YourUserName/Downloads
#For this example we assume the "USB Stick Install Image" is in the Downloads folder.
cd /Users/YourUserName/Downloads
```

#### Step 5: Install image onto USB stick

**Checklist:**

- USB stick inserted into host computer
- Recall USB stick device name from [**Step 2**]()
- From within the installer folder, using the Terminal execute the following commands:

**Execute:**

```shell
$ sudo dd if=YourInstallerImage.iso of=/dev/XXX bs=4m
$ sudo sync
```

**Note:**

- `if=YourInstallerImage.iso`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the USB stick device name from **Step 2**. Be sure to use the device name without the partition name. For example, 'of=/dev/disk1'
- If you get an error message "Resource Busy", you will need to unmount the SD card without removing it from the host computer.
  - Option 1:
  - In the Applications folder, find and click on the Utilities folder.
  - Click on the Disk Utility program to run it
  - Select the device that represents the USB stick
  - Click on `unmount` and leave the USB stick in the computer
  - Retry the '$ sudo dd if=YourInstallerImage.iso of=/dev/XXX bs=4m'
  - Option 2:
  - In the terminal window, enter this command:
```shell
$ sudo umount /dev/<device name>
```

- This command will take some time to execute. Be patient and avoid tampering with the terminal until process has ended.
- Once SD card is done flashing, remove from host computer and set aside.

**Congratulations! Your USB stick is ready. Switch back to the [Installation Guide](README.md#boot-into-the-installer) to boot into the installer!**
