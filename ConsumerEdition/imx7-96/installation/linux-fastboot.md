## Linux Host

This section show how to install a new operating system to your Helio X20 using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host Linux computer
- **Step 2**: Make sure xflash.exe is set up on host Linux computer
- **Step 3**: Build Special images
- **Step 4**: Prepare your Linux host machine
- **Step 5**: Download all necessary images
- **Step 6**: Boot device into fastboot mode
- **Step 7**: Prepare Special images and run scatter file
- **Step 8**: Flash images onto Helio X20 and reboot

***

#### **Step 1**: Make sure fastboot is set up on host Linux computer

- Android SDK “Tools only” for Linux can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

#### **Step 2**: Make sure xflash is set up on host Linux computer

???

#### **Step 3**: Build Special images

Execute following commands, build system will automatically create FES folder and come out the special lk.bin, where FES store the needed files for xflash download to target befor entering fastboot mode. 

$ source build/envsetup.sh
$ lunch full_amt6797_64_open-eng
$ make -j16 PLATFORM_FASTBOOT_EMPTY_STORAGE=yes -k 2>&1 | tee build.log

Then, you can find a folder named FES.
PATH: \out\target\product\amt6797_64_open\FES

#### **Step 4**: Prepare your Linux host machine

- xflash
   - \xflash\bin\linux\xflash
- Normal load(Include image files and scatter file etc.)
   - You can put it in anywhere, eg, \xflash\bin\linux\img
- Special images and scatter file
   - You can put it in anywhere, eg, \xflash\bin\linux\FES. How to build it? 
   - Please see “How to build special images”.
- lib.cfg.xml
   - \xflash\bin\linux\config
- fastboot
   - If your OS doesn't support fastboot command, pls install this command frist.
- fastboot command script file
   - Writen by your self, you should put it in normal load folder.


eg:fastboot command script file named xflash.bat

fastboot devices
fastboot flash recovery recovery.img
****
fastboot flash userdata userdata.img
fastboot reboot

#### **Step 5**: Download all necessary images

If you have not already downloaded your fastboot images, please visit the [Downloads page](../Downloads/README.md) for a list of Helio X20 operating systems.

#### **Step 6**: Boot device into fastboot mode

???

#### **Step 7**: Prepare Special images and run scatter file

Run program in command line mode like this:

`$ sudo ./xflash enter-fastboot "/**/xflash/bin/win/FES/MT6797_Android_scatter.txt"`

<Insert image here>

- Then plug in usb to device.
- Xflash will scan and open device COM port and connect it, download some necessary images to devices, then make device to enter fastboot mode.

<Insert image here>

#### **Step 8**: Flash images onto Helio X20

**Commands:**

```shell
fastboot devices`
fastboot flash recovery recovery.img`
fastboot flash scp1 tinysys-scp.bin`
fastboot flash scp2 tinysys-scp.bin`
fastboot flash lk lk.bin`
fastboot flash lk2 lk.bin`
fastboot flash boot boot.img`
fastboot flash logo logo.bin`
fastboot flash tee1 trustzone.bin`
fastboot flash tee2 trustzone.bin`
fastboot flash system system.img`
fastboot flash cache cache.img`
fastboot flash userdata userdata.img`
fastboot reboot`
```

Run the download script, download success.
