#Create Bootable SD Card

This section show how to install the Debian operating system that is bootable from the SD Card to your DragonBoard™ 410c on a Linux host computer.

**Prerequisites:**

* A local copy of the `dragonboard410c_sdcard_developer_debian-xyz.zip` where `xyz` will vary based upon the build you are downloading.
     * Instructions [here](https://github.com/dbharbin/documentation/blob/master/ConsumerEdition/DragonBoard-410c/Downloads/Debian.md)
     
##Copy the install image onto the SD Card

* Copy the install image downloaded onto the SD Card that will be used by following the `SD Card Method` section on the [DB410c image installation page](https://www.96boards.org/db410c-getting-started/Installation/README.md/) and substitute the image file referenced here for the one in those instructions.

##Boot from the SD Card
Now that the image is burned into the SD Card, the user can now boot from the SD Card.  Perform the following steps to do so:

* Assure the DB410c is powered off
* Set S6 switch on DragonBoard™ 410c to `SD Boot`
     * Set switch to `0-1-0-0`
* Insert the SD Card from the previous step into the DB410c
* Power on the 410c

Upon successful boot, the user will see a command prompt on the HDMI monitor attached to the DB410c
* `linaro@linaro-developer:~$`

**Congratulations!  You are now booting from the SD Card image.**

##Additional developer notes
Now that the system has booted from the SD Card, all development performed will use the SD Card for storage just as if it's the internal emmc or a hard drive.   The user can now customize .bashrc, for example, and these changes will be retained.

The user can now remove the SD card and put it into another DB410c, set switch S6 to `SD Boot` as described above, and the system will boot as though it's the same system.

Development can now be done from this portable solution and can easily  extend local block storage capacity beyond the internal 8GB of emmc on the DB410c.  

The user can also retain a bootable internal emmc.  If the user were to remove the SD card and power cycle, for example, the DB410c will boot from the internal emmc (if there was a previous image installed on it).

###Accessing internal EMMC from SD Card Developer image
If the developer so chooses, the internal emmc can be accessed as follows when the developer has booted from the SD Card image:

* from the command prompt, perform the following to see the names of the emmc (and SD card).
     * `sudo fdisk -l`
     The user should see two mmc devices.  One will be the internal emmc and one for the SD Card.  Most likely the internal will be `/dev/mmcblk0` and the SD Card will be `/dev/mmcblk1`
     
The user can note the `Linux filesystem` partition of the internal emmc and mount it to access any data the might be there.  For example:
```
sudo mkdir /dev/Internalemmc
cd /dev/internalemmc
sudo mount /dev/mmcblk0p10 /dev/internalemmc
```
 The user can now navigate into the internal emmc through the mount point and easily move information between internal emmc and the SD Card.
       

