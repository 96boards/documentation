## Linux Host

This section shows how to install a new operating system to your HiKey using the SD Card method on a Linux host computer.
***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Find SD Card Device name
- **Step 3**: Recall Download Location
- **Step 4**: Unzip _SD Card Install Image_
- **Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal
- **Step 6**: Install Image onto SD Card
- **Step 7**: Prepare HiKey with SD card
- **Step 8**: Install image onto HiKey

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Find SD Card Device name

- Use host computer
- Open "Terminal" application
- Remove SD card from host computer and run the following command:
```shell
lsblk
```
- Note all recognized disk names
- **Insert SD card** and run the following command (again):
```shell
lsblk
```
- Note the newly recognized disk. This will be your SD card.
- **Remember** your SD card device name, it will be needed in **Step 7**.

####**Step 3**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 4**: Unzip _SD Card Install Image_

- When unzipped, you will have a folder with the following contents:
   - Install Image (.img)
   - Readme

####**Step 5**: Go to directory with _SD Card Install Image_ folder using Terminal

- Use host computer
- Open "Terminal" application
- `cd` to the directory with your unzipped **SD Card Install Image**

```shell
cd <extraction directory>

#Example: 
#<extraction directory> = /home/YourUserName/Downloads
#For this example we assume the "SD Card Install Image" is in the Downloads folder.
cd /home/YourUserName/Downloads
```

####**Step 6**: Install Image onto SD Card

**Checklist:**

- SD card inserted into host computer
- Recall SD Card device name from **Step 2**
- From within the extraction folder, using the Terminal execute the following commands:

**Execute:**

```shell
sudo dd if=hikey-jessie_alip_2015MMDD-nnn.img of=/dev/XXX bs=4M oflag=sync status=noxfer
```

**Note:**

- `if=hikey-jessie_alip_2015MMDD-nnn.img`: should match the name of the image that was downloaded.
- `of=/dev/XXX`: XXX should match the name of the SD Card device name from **Step 2**. Be sure to use the device name with out the partition.
- This command will take some time to execute. Be patient and avoid tampering with the terminal until process has ended.
- Once SD card is done flashing, remove from host computer and set aside for **Step 8**

####**Step 7**: Prepare HiKey with SD card

- Make sure HiKey is unplugged from power
- Connect an HDMI monitor to the HiKey with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the HiKey
- Insert the microSD card into the HiKey
- Plug power adaptor into HiKey, wait for board to boot up.

####**Step 8**: Install image onto HiKey

<img src="http://i.imgur.com/F18wlgU.png" data-canonical-src="http://i.imgur.com/F18wlgU.png" width="400" height="250"/>

- If **Steps 1 - 8** were followed correctly, the above screen should be visible from your HiKey
- Select the image to install and click “Install” (or type “i”). OS will be installed into the eMMC memory
- This process can take a few minutes to complete
- Upon completion, “Flashing has completed and OS has installed successfully....” message will appear.

Before clicking "OK":

- Remove the SD Card
- Now click "OK" button and allow HiKey to reboot.

**Congratulations! You are now booting your newly installed operating system directly from eMMC on the HiKey**
