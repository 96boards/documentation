---
title: Board Recovery for HiKey960
permalink: /documentation/consumer/hikey/hikey960/installation/board-recovery/
redirect_from:
- /documentation/ConsumerEdition/HiKey960/Installation/BoardRecovery/
- /documentation/consumer/hikey960/installation/board-recovery/
---
# HiKey960 Board Recovery

This page outlines steps needed to recover your HiKey960 board from a bricked
software state. This instruction set is suggested to those who are experiences
boot issues due to a corrution in the file system and/or other software
components.

## Installing a Bootloader

For most users a board can be “recovered” from a software failure by reloading
the operating system. However, if the primary bootloader has been corrupted
then the bootloader will need to be re-installed. This section describes how
to reinstall the primary bootloader.

### Download the bootloader binaries

The bootloader binaries for HiKey960 can be downloaded
[here](http://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey960/release/).

### Make sure fastboot is set up on host computer

- Android SDK “Tools only” for Linux can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

### Connect a standard Type C cable between the HiKey960 and your Linux PC.

> Note: HiKey960 should **NOT** be power on at this stage

### Set Board Link options

There are two versions of HiKey960: v1 and v2. One important difference you
should know is: v1 is using Jumper (J2001), while v2 is using DIP
switch (SW2201). Both are located in the bottom side of board.

There are two versions of HiKey960  |
----------------------------------- |
v1 uses Jumpers (J2001)             |
v2 uses DIP Switches (SW2201)       |

> Note: Both version of switches are located on the bottom of the board.

Jumper / DIP Switch comparison                    |
------------------------------------------------- |
Jumper Pin 1-2 = DIP switch 1                     |
Jumper Pin 3-4 = DIP switch 2                     |
Jumper Pin 5-6 = DIP switch 3                     |

- To boot into **fastboot mode everytime** set switch 1 & 3 to ON state
  and switch 2 to OFF state.
- To boot into **fastboot mode at every alternate rebooot** set switch 1
  to ON and switch 2 & 3 to OFF state.
- To boot into **recovery mode** set switch 1 & 2 to ON state and switch 3
  to OFF state

Since we are going to flash the bootloader binaries, we need to boot into
**recovery mode** as mentioned above.

### Connect the HiKey960 power supply to the board.

Since USB does **NOT** power the HiKey960 board, you must use an external
power supply.

After powering up the HiKey960, wait about 5 seconds and then check that
the HiKey960 board has been recognized by your Linux PC as follows:

```
$ ls /dev/ttyUSB*
or
$ dmesg
```

### Flash the recovery binaries

Make sure the modem interface is in the right ttyUSB as previously suggested. In this example, `ttyUSB0` is used:

```
$ sudo ./hikey_idt -c config -p /dev/ttyUSB0
```

You should be able to see the following output after executing the tool:

```
Config name: config
Port name: /dev/ttyUSB0
0: Image: hisi-sec_usb_xloader.img Downalod Address: 0x20000
1: Image: hisi-sec_uce_boot.img Downalod Address: 0x6a908000
2: Image: recovery.bin Downalod Address: 0x1ac00000
Serial port open successfully!
Start downloading hisi-sec_usb_xloader.img@0x20000...
file total size 99584
downlaod address 0x20000
Finish downloading
Start downloading hisi-sec_uce_boot.img@0x6a908000...
file total size 23680
downlaod address 0x6a908000
Finish downloading
Start downloading recovery.bin@0x1ac00000...
file total size 1179648
downlaod address 0x1ac00000
Finish downloading
```

The bootloader has now been installed. Now move to the Hikey960 console
and press `f` during UEFI boot. This will allow the board to boot into
fastboot mode. Once the board is in fastboot mode, you should see the ID
of the HiKey960 board using the following command
```
$ sudo fastboot devices
1ED3822A018E3372	fastboot
```

The following fastboot commands loads the **partition table, bootloader,
and other necessary files into the HiKey960 UFS memory**.

```
$ sudo fastboot flash ptable prm_ptable.img
$ sudo fastboot flash xloader hisi-sec_xloader.img
$ sudo fastboot flash fastboot l-loader.bin
$ sudo fastboot flash fip fip.bin
```

Your bootloader has been successfully installed and you are now ready to
install the operating system files into the UFS memory, for this go to
the ([HiKey960 Installation]()) page.

**NOTE**

This bootloader is based on UEFI and includes:
- ARM Trusted Firmware
- UEFI with DeviceTree
- GRUB
- fastboot support
- OP-TEE support
