# HiKey Board Recovery

This page outlines steps needed to recover your HiKey board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

### Installing a Bootloader 

For most users a board can be “recovered” from a software failure by reloading the operating system. However, if the primary bootloader in the eMMC flash memory has been corrupted then the bootloader will need to be re-installed. This section describes how to reinstall the primary bootloader. 
 
#### Step 1: Choose your Operating System and download the following files

Build Folders ( <a href="http://builds.96boards.org/releases/hikey/linaro/binaries/latest/" target="_blank">Debian</a> / <a href="http://builds.96boards.org/releases/hikey/linaro/binaries/latest/" target="_blank">AOSP</a> )


|  Debian                      |        AOSP                     |
|:----------------------------:|:-------------------------------:|
| [l-loader.bin](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/l-loader.bin)             |   [l-loader.bin](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/l-loader.bin)              |
|  [fip.bin](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/fip.bin)                 |   [fip.bin](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/fip.bin)                   |
| [nvme.img](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/nvme.img)                 |  [nvme.img](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/nvme.img)                   |
| [ptable-linux-4g.img](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/ptable-linux-4g.img) or [ptable-linux-8g.img](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/ptable-linux-8g.img)     |    [ptable-aosp-4g.img](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/ptable-aosp-4g.img) or [ptable-aosp-8g.img](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/ptable-aosp-8g.img)      |

You will also need the boot partition for the OS Image you want to run
* [boot-fat.uefi.img for Debian] (https://builds.96boards.org/releases/hikey/linaro/debian/latest/boot-fat.uefi.img.gz)
* [boot_fat.uefi.img for AOSP](https://builds.96boards.org/releases/hikey/linaro/aosp/latest/boot_fat.uefi.img.tar.xz)

You can do this from your browser or from the command prompt:
For example, to download the latest UEFI build and boot partition for Debian do:

```shell
$ wget https://builds.96boards.org/releases/hikey/linaro/binaries/latest/l-loader.bin
$ wget https://builds.96boards.org/releases/hikey/linaro/binaries/latest/fip.bin
$ wget https://builds.96boards.org/releases/hikey/linaro/debian/latest/ptable-linux-4g.img
$ wget https://builds.96boards.org/releases/hikey/linaro/debian/latest/ptable-linux-8g.img
$ wget https://builds.96boards.org/releases/hikey/linaro/binaries/latest/nvme.img
$ wget https://builds.96boards.org/releases/hikey/linaro/debian/latest/boot-fat.uefi.img.gz
```

Uncompress the boot image as follows:
```shell
$ gunzip boot-fat.uefi.img.gz
```

You will also need the fastboot application installed on your Linux PC – if this is not installed then follow the instructions [at the end of this section](#section-42). 

Connect a standard microUSB cable between the HiKey microUSB and your Linux PC. Do not power up the HiKey board yet.

**Set Board Link options**

For flashing the bootloader, the top two links should be installed (closed) and the 3rd link should be removed (open):

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | closed
GPIO3-1 | Link 5-6 | open

Link 1-2 causes HiKey to auto-power up when power is installed. Link 3-4 causes the HiKey SoC internal ROM to start up in at a special "install bootloader" mode which will install a supplied bootloader from the microUSB OTG port into RAM, and will present itself to a connected PC as a ttyUSB device.

Please refer to the [Hardware User Guide](https://www.96boards.org/wp-content/uploads/2015/02/HiKey_User_Guide_Rev0.2.pdf) (Chapter 1. Settings Jumper) for more information on the HiKey link options.

Now connect the HiKey power supply to the board.

**NOTE:** USB does NOT power the HiKey board. You must use an external power supply.

**NOTE:** The HiKey board will remain in USB load mode for 90 seconds from power up. If you take longer than 90 seconds to start the install then power cycle the board before trying again.

Wait about 5 seconds and then check that the HiKey board has been recognized by your Linux PC:
```
$ ls /dev/ttyUSB*
or
$ dmesg
```
[hisi-idt.py](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/hisi-idt.py) is the download tool for the HiKey. This is used to install the bootloader as follows:

Execute the following commands as a script or individually:

First, get the script that is needed to load the initial boot software:
```
$ wget https://raw.githubusercontent.com/96boards/burn-boot/master/hisi-idt.py
```
Run the script to initially prepare fastboot (make sure the modem interface is in the right ttyUSB as previously suggested. In this example, use ttyUSB0):
```
$ sudo python hisi-idt.py -d /dev/ttyUSB0 --img1=l-loader.bin
```
After the python command has been issued you should see the following output. If you do not then see the "Problems with Python Downloader" section below
```
+----------------------+
 Serial:  /dev/ttyUSB0
 Image1:  l-loader.bin
 Image2:  
+----------------------+

Sending l-loader.bin ...
Done
```
**NOTE:** You may see the word “failed” before Done. This is under investigation but is not fatal. As long as the “Done” is printed at the end you may proceed.

The bootloader has now been installed into RAM. Wait a few seconds for the fastboot application to actually load. The following fastboot commands then load the partition table, the bootloader and other necessary files into the HiKey eMMC flash memory (4GB or 8GB). Taking 8GB as example.

**NOTE:** the ptable must be flashed first. Wait for a few seconds after the reboot command to allow the bootloader to restart using the new partition table. (Example goes with 8G)


```
$ sudo fastboot flash ptable ptable-linux-8g.img
$ sudo fastboot reboot
$ sudo python hisi-idt.py -d /dev/ttyUSB0 --img1=l-loader.bin (again, remember ttyUSB* can change)
$ sudo fastboot flash fastboot fip.bin
$ sudo fastboot flash nvme nvme.img
$ sudo fastboot flash boot boot-fat.uefi.img
```

Once this has been completed the bootloader has been installed into eMMC.
Power off the HiKey board by removing the power supply jack.

Next change the link configuration as follows:

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | open
GPIO3-1 | Link 5-6 | closed

Now connect power supply jack to your HiKey again.

Check that the HiKey board is detected by your Linux PC

Wait about 10 seconds.

You should see the ID of the HiKey board returned
```
$ sudo fastboot devices
0123456789abcdef fastboot
```

Your bootloader has been successfully installed and you are now ready to install the operating system files into the eMMC flash memory, for this go to the ([HiKey Crossroads](https://github.com/96boards/documentation/wiki/HiKey-Crossroads#choose-your-build-operating-system-and-install-method)).

**NOTE:**

This bootloader is based on UEFI and includes:
- ARM Trusted Firmware
- UEFI with DeviceTree
- GRUB
- fastboot support
- OP-TEE support
