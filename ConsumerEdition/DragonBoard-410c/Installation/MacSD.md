## Mac OS X Host

This section show how to install an operating system to your DragonBoard™ 410c using the SD Card method on a Mac OS X host computer.
***

- [**Step 1**: Prepare MicroSD card](#step-1-prepare-microsd-card)
- [**Step 2**: Find SD Card Device name](#step-2-find-sd-card-device-name)
- [**Step 3**: Recall Download Location](#step-3-recall-download-location)
- [**Step 4**: Unzip _SD Card Install Image_](#step-4-unzip-sd-card-install-image)
- [**Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal](#step-5-go-to-directory-with-sd-card-install-image-folder-using-terminal)
- [**Step 6**: Locate SD Card Install Image](#step-6-locate-sd-card-install-image)
- [**Step 7**: Install Image onto SD Card](#step-7-install-image-onto-sd-card)
- [**Step 8**: Prepare DragonBoard™ 410c with SD card](#step-8-prepare-dragonboard-410c-with-sd-card)
- [**Step 9**: Install image onto DragonBoard™ 410c](#step-9-install-image-onto-dragonboard-410c)

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Find SD Card Device name

- Use host computer
- Open "Terminal" application **(Press Command+Space bar and type "Terminal")**
- Remove SD card from host computer and run the following command:
```shell
diskutil list
```
- Note all recognized disk names
- **Insert SD card** and run the following command (again):
```shell
diskutil list
```
- Note the newly recognized disk. This will be your SD card.
- **Remember** your SD card device name, it will be needed in **Step 7**.

####**Step 3**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 4**: Unzip _SD Card Install Image_

- When unzipped, this download will be a folder with the falling contents
   - Install Image (.img)
   - Readme

####**Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal

- Use host computer
- Open "Terminal" application **(Press Command+Space bar and type "Terminal")**
- `cd` to the directory with your unzipped **SD Card Install Image**

```shell
cd <extraction directory>

#Example: 
#<extraction directory> = /Users/YourUserName/Downloads
#For this example we assume the "SD Card Install Image" is in the Downloads folder.
cd /Users/YourUserName/Downloads
```

####**Step 6**: Locate SD Card Install Image

- Make sure you are in the extraction directory

**Unzipped SD Card download will be a folder. This folder should be listed in your directory. Type `ls` from command line for a list of files that can be found in your current directory**:

```shell
ls

#output
dragonboard410c_sdcard_install_Y-XX
```

- Unzipped folder should be called dragonboard410c_sdcard_install_Y-XX, where Y can be Android of Debian and XX represents the release number
- `cd` into this directory

```shell
cd dragonboard410c_sdcard_install_Y-XX
```

- Inside this folder you will find the install image
   - `db410c_sd_install_Y.img`
- This `.img` file is what will be flashed to your SD Card.

####**Step 7**: Install Image onto SD Card

**Checklist:**

- SD card inserted into host computer
- Recall SD Card device name from [**Step 2**]()
- From within the dragonboard410c_sdcard_install_Y-XX folder, using the Terminal execute the following commands:

**Execute:**

```shell
$ sudo dd if=db410c_sd_install_Y.img of=/dev/XXX bs=4m
$ sudo sync
```

**Note:**

- `if=db410c_sd_install_Y.img`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the SD Card device name from **Step 2**. Be sure to use the device name with out the partition.
- This command will take some time to execute. Be patient and avoid tampering with the terminal until process has ended.
- Once SD card is done flashing, remove from host computer and set aside for **Step 8**

####**Step 8**: Prepare DragonBoard 410c with SD card

- Make sure DragonBoard™ 410c is unplugged from power
- Set S6 switch on DragonBoard™ 410c to `0-1-0-0`, "SD Boot switch" should be set to "ON".
   - Please see "1.1 Board Overview" on page 7 from [DragonBoard™ 410c Hardware Manual](http://linaro.co/96b-hwm-db) if you cannot find S6
- Connect an HDMI monitor to the DragonBoard™ 410c with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the DragonBoard™ 410c
- Insert the microSD card into the DragonBoard™ 410c
- Plug power adaptor into DragonBoard™ 410c, wait for board to boot up.

####**Step 9**: Install image onto DragonBoard 410c

<img src="http://i.imgur.com/F18wlgU.png" data-canonical-src="http://i.imgur.com/F18wlgU.png" width="400" height="250"/>

- If **Steps 1 - 8** were followed correctly, the above screen should be visible from your DragonBoard™ 410c
- Select the image to install and click “Install” (or type “i”). OS will be installed into the eMMC memory
- This process can take a few minutes to complete
- Upon completion, “Flashing has completed and OS has installed successfully....” message will appear.

Before clicking "OK":

- Remove the SD Card
- Set S6 switch on DragonBoard™ 410c to `0-0-0-0`, all switches should be set to "OFF"
- Now click "OK" button and allow DragonBoard™ 410c to reboot.

**Congratulations! You are now booting your newly installed operating system directly from eMMC on the DragonBoard™ 410c!**
