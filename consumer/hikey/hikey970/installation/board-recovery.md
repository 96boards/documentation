---
title: BoardRecovery for HiKey970
permalink: /documentation/consumer/hikey/hikey970/installation/board-recovery.md.html
redirect_from:  /documentation/consumer/hikey970/installation/board-recovery.md.html
---
# HiKey970 Board Recovery

This page outlines steps needed to recover your HiKey970 board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

## Installing a Bootloader

For most users a board can be “recovered” from a software failure by reloading the operating system. However, if the primary bootloader in the UFS flash memory has been corrupted then the bootloader will need to be re-installed. This section describes how to reinstall the primary bootloader.

#### Build Recovery Binaries

Following instructions are used to build the recovery binaries for Hikey970.

##### Install dependencies

Following dependencies needs to be installed for building the bootloader binaries
and the instructions are specified for debian based systems.

```shell
sudo apt-get install libssl-dev python-pip uuid-dev 
pip install pycrypto
```
##### Clone the repositories

```shell
git clone https://github.com/96boards-hikey/arm-trusted-firmware -b hikey970_v1.0
git clone https://github.com/96boards-hikey/edk2 -b hikey970_v1.0
git clone https://github.com/96boards-hikey/OpenPlatformPkg -b hikey970_v1.0
git clone https://github.com/96boards-hikey/l-loader -b hikey970_v1.0
git clone https://github.com/Mani-Sadhasivam/uefi-tools -b hikey970_v1.0
git clone https://github.com/96boards-hikey/tools-images-hikey970
```

##### Perpare a shell script

Copy the below contents and prepare a shell script as `build_bootloader.sh`.


```shell
#!/bin/sh

BUILD_OPTION=DEBUG
export AARCH64_TOOLCHAIN=GCC5
export BUILD_PATH=${PWD}
export UEFI_TOOLS_DIR=${BUILD_PATH}/uefi-tools
export EDK2_DIR=${BUILD_PATH}/edk2
EDK2_OUTPUT_DIR=${EDK2_DIR}/Build/HiKey970/${BUILD_OPTION}_${AARCH64_TOOLCHAIN}

# Build UEFI & Trusted Firmware-A
echo "#### Building UEFI and Trusted Firmware images"
cd ${EDK2_DIR}
ln -sf ../OpenPlatformPkg
${UEFI_TOOLS_DIR}/uefi-build.sh -b ${BUILD_OPTION} -a ../arm-trusted-firmware hikey970

# Generate l-loder.bin
echo "#### Generating l-loader.bin"
cd ${BUILD_PATH}/l-loader
ln -sf ${EDK2_OUTPUT_DIR}/FV/bl1.bin
ln -sf ${EDK2_OUTPUT_DIR}/FV/bl2.bin
ln -sf ${EDK2_OUTPUT_DIR}/FV/fip.bin
ln -sf ${EDK2_OUTPUT_DIR}/FV/BL33_AP_UEFI.fd
make hikey970

# Copy generated binaries to tools-images-hikey970
echo "#### Copying generated binaries"
cp ${EDK2_OUTPUT_DIR}/FV/fip.bin ${BUILD_PATH}/tools-images-hikey970
cp ${BUILD_PATH}/l-loader/l-loader.bin ${BUILD_PATH}/tools-images-hikey970
```

##### Build the Bootloader binaries

Next step is to build the bootloader binaries using the shell script prepared above.

```shell
$ ./build_bootloader.sh
```

Once the script gets executed successfully, the bootloader binaries will
get generated.

#### Make sure fastboot is set up on host computer

- Android SDK “Tools only” for Linux can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

#### Connect your Linux PC and HiKey970 using USB Type-A to Type-C cable.

Now, connect PC's USB port to Type-C port available in between HDMI and USB
port on the HiKey970 board using Type-A to Type-C USB cable.

HiKey970 should **NOT** be power on at this stage

> Note: There are two Type-C ports on the board and, during recovery, both will enumerate
>       as serial ports. It is important to use the correct port otherwise the recovery tools
>       will not work correctly. The one available on the Left hand side, below Low Speed
>       expansion header is for accessing **Debug UART** and the one between HDMI and USB port
>       is used for **Recovery**.

#### Set Board Switch options

Name          | Switch   | State
------------- | -------- | ----------
Auto Power up | Switch 1 | closed / ON
Recovery      | Switch 2 | closed / ON
Fastboot      | Switch 3 | closed / ON

Switch 1 causes HiKey970 to auto-power up when power is installed. Switch 2 causes the HiKey970 SoC internal ROM to start up in at a special "install bootloader" mode which will install a supplied bootloader from the Type-C port into RAM, and will present itself to a connected PC as a ttyUSB device.

#### Connect the HiKey970 power supply to the board.

**NOTE:** USB does NOT power the HiKey970 board. You must use an external power supply.

#### Wait about 5 seconds and then check that the HiKey board has been recognized by your Linux PC:

```
$ ls /dev/ttyUSB*
or
$ dmesg
```

#### Run the script to initially prepare fastboot

Now, move into the `tools-images-hikey970` directory and execute the recovery script.
Make sure the modem interface is in the right ttyUSB as previously suggested. In this
example, `ttyUSB0` is used:

```
$ cd tools-images-hikey970
$ sudo python hisi-idt.py -d /dev/ttyUSB0 --img1 ./sec_usb_xloader.img --img2 ./sec_usb_xloader2.img --img3 ./l-loader.bin
```

> Note: This script only works with Python2.7

You should see the following output on PC after executing the above command:

```
+----------------------+
(' Serial: ', '/dev/ttyUSB0')
(' Image1: ', './sec_usb_xloader.img')
(' Image2: ', './sec_usb_xloader2.img')
+----------------------+

('Sending', './sec_usb_xloader.img', '...')
Done

('Sending', './sec_usb_xloader2.img', '...')
Done

('Sending', './l-loader.bin', '...')
Done

```

The bootloader has now been installed into RAM. Wait a few seconds for the fastboot application to actually load. The following fastboot commands

```
$ sudo fastboot flash fastboot l-loader.bin
$ sudo fastboot flash fip fip.bin
```

Once this has been completed the bootloader has been installed into UFS.

#### Power off the HiKey970 board by removing the power supply jack and change the link configuration as follows:

Name          | Switch   | State
------------- | -------- | ----------
Auto Power up | Switch 1 | closed / ON
Recovery      | Switch 2 | open / OFF
Fastboot      | Switch 3 | closed / ON

#### Connect power supply jack to your HiKey970 again

Check that the HiKey board is detected by your Linux PC

Wait about 10 seconds.

You should see the ID of the HiKey970 board returned

```
$ sudo fastboot devices
0123456789abcdef fastboot
```

Your bootloader has been successfully installed and you are now ready to install the operating system files into the UFS memory, for this go to the ([HiKey970 Installation](README.md)) page.

**NOTE:**

This bootloader is based on UEFI and includes:
- ARM Trusted Firmware
- UEFI with DeviceTree
- GRUB
- fastboot support
