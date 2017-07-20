# Create Bootable SD Card

This section show how to install the Debian operating system that is bootable from the SD Card to your DragonBoard™ 410c on a Linux host computer.

**Prerequisites:**

* A local copy of the `dragonboard410c_sdcard_developer_debian-xyz.zip` where `xyz` will vary based upon the build you are downloading.
     * Instructions [here](../Downloads/Debian.md)
     
## Copy the install image onto the SD Card

* Copy the install image downloaded onto the SD Card that will be used by following the [SD Card Method](LinuxSD.md) section  and substitute the image file referenced here for the one in those instructions.

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

* from the command prompt on the HDMI monitor connected to the DB410c, perform the following to see the name of the eMMC and SD card devices.
     * `sudo fdisk -l`
     The user should see two mmc devices.  One will be the internal eMMC and one for the SD Card.  Most likely the internal will be `/dev/mmcblk0` and the SD Card will be `/dev/mmcblk1`
     
The user can note the `Linux filesystem` partition of the internal eMMC and mount it to access any data the might be there.  For example:
```
sudo mkdir /mnt/Internalemmc
cd /mnt/internalemmc
sudo mount /dev/mmcblk0p10 /mnt/internalemmc
```
The user can now navigate into the internal eMMC through the mount point and easily move information between internal eMMC and the SD Card.

#### Creating an image of the internal eMMC
In some cases a developer may be interested in duplicating byte-for-byte the internal eMMC.  This section describes one way to do this.  This section assumes the developer has installed and is running their file system from the SD Card.  It also assumes that the SD Card has enough free space to create the duplicated image.

First, make sure the internal eMMC is not mounted:
`df`

If the internal eMMC is mounted, unmount it.  Using the mount point provided as an example from the previous section:
`sudo umount /mnt/Internalemmc`

Now you are ready to create an image of the internal eMMC
`sudo dd if=/dev/mmcblk0 of=~/sd-card-copy.img bs=4M`

A file should now exist on your SD Card (sd-card-copy.img in this example) that can be used to create an identical image another SD Card or placed in another Dragonboard 410c and re-imaging the internal eMMC.  Again assuming you are still on a Dragonboard 410c that is running out of the SD Card image, do the following to re-image the internal eMMC:
`sudo dd if=~/sd-card-copy.img of=/dev/mmcblk0 bs=4M`


       

