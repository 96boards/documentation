---
title: Ubuntu Core Download for Bubblegum-96
permalink: /documentation/ConsumerEdition/Bubblegum-96/Downloads/Ubuntu-Core.md/
---
**About Ubuntu Core**

> Snappy Ubuntu Core is a new rendition of Ubuntu with transactional updates - a minimal server image with the same libraries as today’s Ubuntu, but applications are provided through a simpler mechanism.


----------
##**How To Flash Bubblegum-96 With Ubuntu Core**

The section here will show you how to flash Bubblegum-96 Board with Ubuntu Core on a micro SD card.  

There will be six steps:  
**Step1:** prepare your hardware.    
**Step2:** Update your host pc(Ubuntu System).  
**Step3:** Prepare the software.  
**Step4:** Flash the image into the MicroSD card.  
**Step5:** Clean the emmc.  
**Step6:** Reboot the Bubblegum-96.  


----------
##**Step1: prepare your hardware**
Before everything, please check the following list. They are the equipments you need.  
1. Bubblegum-96 Board  
2. USB cable Type-A to Type-A  
3. A qualified power supply  
4. A Linux computer as a Host PC (Ubuntu 16.04LTS)  
5. A serial console with converter board  
6. A MicroSD card (>=8G)  

##**Step2: Update your host pc(Ubuntu System)**
Because Ubuntu Core only can be flashed on Ubuntu 16.04LTS, you need to make sure the system version.  
If you have already had Ubuntu 16.04LTS, please skip this step, otherwise, please do the following command in a terminal.  
```shell
$sudo apt-get update
$sudo update-manager -d
```
And then, upgrade your system.  

##**Step3: Prepare the software**
When flashing the Ubuntu Core, you need to download:  
ubuntu-core_bubblegum_2016****.img  
(**Please check the md5: d2a047e9f3cfbbd7739c4541c7d11176  ubuntu-core_bubblegum_20160607.img**)

For global users: [https://mega.nz/#!dsplDRbB!X_su5fKFOWeGJ6Yurf7X6wKqnnOPnno-Fw-2smiWrGE][1]  
For Chinese users: [http://pan.baidu.com/s/1mizsWM8][3]  

U-boot-dtb.img: [http://builds.96boards.org/snapshots/bubblegum/linaro/u-boot/latest/u-boot-dtb.img][2]

And create the linaro-adfu-tool with the following command:  
```shell
$ git clone https://github.com/96boards-bubblegum/linaro-adfu-tool.git
$ cmake .
$ make
$ make install
```

##**Step4: Flash the image into the MicroSD card**
Use the following commad:  
```shell
$ sudo dd if=ubuntu-core_bubblegum_20160606.img of=/dev/sd*
```

(sd* means your own sd card name. You can find that with command  
```shell
$ lsblk
```
)  
This step will take a few minutes.  

##**Step5: Clean the emmc**
This step is quite important, because it will boot into the OS which is on the board before. But before you clean the emmc, you need to turn the board into ADFU mode first.  

 1. Turn the board into ADFU mode.  
   - Make sure bubblegum-96 board is in power off mode and the MicroSD card is not in the board.  
- Plug in the UART debug board and connect serial console to the host PC.   
   - Set baud rate to be 115200,   
   - Set (8N1) – [8bit data, No-parity, & 1 stop bit].  
- Connect the host PC with Bubblegum-96 USB3.0 port via type USB A-A cable.  
   - USB3.0 port on Bubblegum96 board is the blue port  
   - Tthis cable won’t provide Power, so will notwont boot up the board  
- Hold down the ADFU key on the Bubblegum96 board while…   

- Plug in power to the Bubblegum96 board.  
- Continue to hold down ADFU down the ADFU key for 2-4 seconds after the power has been plugged in  
- Release the ADFU key  
- Execute `lsusb` on host PC.  
   - You will find a device ID 10d6:10d6 if Bubblegum96  board has entered adfu-mode  
   - If Bubblegum96 board has not entered ADFU mode,  retry step 1-7  

 *Note: About the serial console.Before doing anythingeverything, please make sure you have already install the serial console. If not, please install that use the following command.*  

```shell
$sudo apt-get install minicom
```

Run another terminal and  
```shell
$sudo minicom -s
```

In this case, we need to set the minicom,    
*Port: ttyUSB0  
Bps/Par/Bits: 115200  
Hardware control flow: No*  
While in the ADFU mode, Bubblegum96 board can be confirmed to be in “receiving mode” to accept commands from the Host-PC…  
Please press Enter when system bootup, and it will show “owl>” prompt on serial console.  

2.Run the following command.  
```shell
$sudo ./src/linaro-adfu-tool-bg96 u-boot-dtb.img
```

When seeing u-boot starts running on serial console, press enter to break it and entering the u-boot shell.  
Run following command:  
```shell
$mmc dev 1
$mmc erase 0 100000
```
##**Step6: Reboot the Bubblegum-96**

It will boot into Ubuntu Core.  
```shell
Username: ubuntu
Password: ubuntu
```







  [1]: https://mega.nz/#!dsplDRbB!X_su5fKFOWeGJ6Yurf7X6wKqnnOPnno-Fw-2smiWrGE
  [2]: http://builds.96boards.org/snapshots/bubblegum/linaro/u-boot/latest/u-boot-dtb.img
  [3]: http://pan.baidu.com/s/1mizsWM8
