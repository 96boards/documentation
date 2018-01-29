---
title: Create a Bootable SD Card for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/installation/linux-sd-boot.md.html
redirect_from:
- /db410c-getting-started/Installation/LinuxSDBoot.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Installation/LinuxSDBoot.md.html
---
# Create Bootable SD Card

This section show how to install the Debian operating system that is bootable from the SD Card to your DragonBoard™ 410c on a Linux host computer.

**Prerequisites:**

* A local copy of the `dragonboard410c_sdcard_developer_debian-xyz.zip` where `xyz` will vary based upon the build you are downloading.
     * Instructions [here](../downloads/debian.md)

## Copy the install image onto the SD Card

* Copy the install image downloaded onto the SD Card that will be used by following the [SD Card Method](linux-sd.md) section  and substitute the image file referenced here for the one in those instructions.

## Boot from the SD Card
Now that the image is burned into the SD Card, the user can now boot from the SD Card.  Perform the following steps to do so:

* Assure the DragonBoard™ 410c is powered off
* Set S6 switch on DragonBoard™ 410c to `SD Boot`
     * Set switch to `0-1-0-0`
* Insert the SD Card from the previous step into the DragonBoard™ 410c
* Power on the DragonBoard™ 410c

Upon successful boot, the user will see a command prompt on the HDMI monitor attached to the DragonBoard™ 410c
* `linaro@linaro-developer:~$`

**Congratulations!  You are now booting from the SD Card image.**

## Additional developer notes
Now that the system has booted from the SD Card, all development performed will use the SD Card for the File System just as if it's the internal eMMC or any block storage device. The user can now customize .bashrc, for example, and these changes will be retained.

The user can also remove the SD Card and put it into another DragonBoard™ 410c, and with switch S6 to `SD Boot` as described herein the system will boot seemlessly without knowing that it is running on a different board.

Development can now be done from this portable solution and can easily extend local block storage capacity beyond the internal 8GB of eMMC provided on the DB410c.  

The user can also retain a bootable internal eMMC.  If the user were to remove the SD card and power cycle, for example, the DB410c will boot from the internal emmc (if there was a previous image installed on it).

### Hint: Accessing internal eMMC from SD Card Developer image
If the developer so chooses, the internal eMMC can be accessed as follows when the developer has booted from the SD Card image:

From the command prompt on the HDMI monitor connected to the DB410c, perform the following to see the name of the eMMC and SD card devices.

`sudo fdisk -l`

The user should see two mmc devices.  One will be the internal eMMC and one for the SD Card.  Most likely the internal will be `/dev/mmcblk0` and the SD Card will be `/dev/mmcblk1`

The user can note the `Linux filesystem` partition of the internal eMMC and mount it to access any data the might be there.  For example:
```
sudo mkdir /mnt/Internalemmc
cd /mnt/Internalemmc
sudo mount /dev/mmcblk0p10 /mnt/Internalemmc
```
The user can now navigate into the internal eMMC through the mount point and easily move information between internal eMMC and the SD Card.

#### Creating an image of the internal eMMC
In some cases a developer may be interested in duplicating byte-for-byte the internal eMMC.  This section describes one way to do this.  
Prerequisites:
- This section assumes the developer has installed and is running their file system from the SD Card.  
- This section also assumes that the SD Card has enough free space to create the duplicated image.  8 GB of free space is a good base assumption although the .img file may end up being smaller.

First, make sure the internal eMMC is not mounted:

`df`

If the internal eMMC is mounted, unmount it.  Using the mount point provided as an example from the previous section:

`sudo umount /mnt/Internalemmc`

**Warning:** as always, when executing commands such as `dd`, please triple check to make sure you are copying to the correct device!  Commands such as `lsblk` and `fdisk` should be used and understood to assure you don't overwrite unintended devices. At the time of this writing and for the creation of the example commands below, the internal eMMC was determined to be `/dev/mmcblk0` and the SD Card was `/dev/mmcblk1`.  Please never assume and always verify.

Now you are ready to create an image of the internal eMMC stored as a file on the SD Card. Note that the following commands will take several minutes to execute.

`sudo dd if=/dev/mmcblk0 of=~/internal-emmc-copy.img bs=4M`

In the above example mmcblk0 is the internal eMMC and internal-emmc-copy.img is the arbitrary filename used to copy the eMMC image into.

A file should now exist on your SD Card (internal-emmc-copy.img in this example) that can be used to create an identical image of the eMMC from the current Dragonboard 410c into another Dragonboard 410c.  In this example use-case, the user would power down the current Dragonboard 410c, remove the bootable SD Card, place the SD Card in another Dragonboard 410c configured for SD Card boot, power up, and replicate the eMMC image created in the previous step into the internal eMMC of the new board by executing the command below. This might be beneficial for testing and debugging.  Assuming you have now moved to another Dragonboard 410c that is running out of the SD Card image, execute the following command to re-image the internal eMMC after verifying the eMMC device name is correct:

`sudo dd if=~/internal-emmc-copy.img of=/dev/mmcblk0 bs=4M`
