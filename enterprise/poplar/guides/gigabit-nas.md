---
title: Create a Gigabit NAS
permalink: /documentation/enterprise/poplar/guides/gigabit-nas.md.html
redirect_from: /documentation/EnterpriseEdition/Poplar/Guides/gigabit-nas.md.html
---

# Create a Gigabit Network Attached Storage using Poplar
This page provides the instructions for creating a smb(Samba) based NAS leveraging the USB3.0 and Gigabit Ethernet capabilities of the Poplar board for a high speed NAS.

# Table of Contents

- [1) Hardware Required](#1-hardware-required)
- [2) Software Required](#2-software-required)
- [3) Software Setup](#3-software-setup)
- [4) Conclusion](#4-conclusion)

# 1) Hardware Required
- [Poplar Enterprise Edition Board](https://www.96boards.org/product/poplar/)
- Gigabit Capable Router
- CAT 6 RJ45 LAN Cable(s)
- External Hard Drive
- External Powered Hard drive Dock: Tested on [QuantumZero](https://www.quantumzero.in/quantumzero%E2%84%A2-qz-hd01-usb-30-sata-hard-drive-dock-with-dust-protection-cover.html)
- 12v Power Adapter

> Note: For best performance make sure all the nodes are connected to your router using a CAT 6 cable.

# 2) Software Required

We need Debian installed on the poplar to get our NAS running, there are two ways to install Debian:
- 1 [Official Build Instructions](https://github.com/96boards-poplar/Documentation/blob/master/debian_build_instructions.md)
- 2 [Daniel Thompson's USB Image Creator](https://github.com/daniel-thompson/poplar-usbstick)

> Note: Since OS installation is out of the scope for this guide, feel free to ask around the [96boards forum](https://discuss.96boards.org/) or on IRC freenode #96boards

# 3) Software Setup

1. **Format as Ext4:** WARNING! You will loose all data from your external drive.
  - ``` sudo fdisk /dev/sda ```
  - If all goes well, by pressing ```N```, you will be given the option of creating a new partition in the empty space. If the only unallocated space is the one you want to use, the default choices should be fine and you can just let fdisk choose.
  - Since you want to create an ```ext``` partition, you don't need to do anything. If you wanted to create a different type (swap or NTFS or whatever) you would need to use t to change the partition type. I am mentioning this just in case.
  - Check that your changes are what you expected by hitting ```P``` to print the partition table.
  - If everything is OK, write the new partition table to the disk (```W```) and exit (```Q```).
  - Now that you have your new, empty partition, you can create its filesystem. ``` sudo mkfs.ext4 /dev/sda1 ```
2. **Mount at boot using fstab:** In order to mount our external driver correctly on every boot we need to create an fstab entry
  - Check the UUID for you partition:
    - ```ls -l /dev/disk/by-uuid/```
    - Output should be:
    ```shell
    total 0
    lrwxrwxrwx 1 root root 10 Jan  2 20:59 4119fd58-05cd-448c-a8d7-7dfc34e5e913 -> ../../sda1
    lrwxrwxrwx 1 root root 15 Nov  3  2016 4653-BB13 -> ../../mmcblk0p2
    lrwxrwxrwx 1 root root 15 Nov  3  2016 b61297cd-63ae-4ea6-a61e-52400d884884 -> ../../mmcblk0p3
    ```
    - In this case the UUID is ```4119fd58-05cd-448c-a8d7-7dfc34e5e913```
  - Add the fstab entry
    - ```sudo vi /etc/fstab```
    - Add the following line to the end
    - ``` UUID="4119fd58-05cd-448c-a8d7-7dfc34e5e913" /media/hdd/ ext4 rw,user,noatime 0 0 ```
    - Replace UUID with your value.
  - Create Mount Point
    - ```sudo mkdir -p /media/hdd/data```
  - Reboot to check if the mount works.
3. **Setup SAMBA:** We will be using the SMB protocol to make it compatible with Windows based systems as well.
  - Install samba package
    - ```sudo apt install samba```
  - Add samba configuration
    - Move older config: ```sudo mv /etc/samba/smb.conf /etc/samba/smb.conf.bak```
    - create new config: ```sudo  vi /etc/samba/smb.conf```
    - Add the following lines:
     ```shell
    [GHOST]
    comment = ghost drive
    path = /media/hdd/data
    valid users = @users
    force group = users
    create mask = 0660
    directory mask = 0771
    read only = no
    ```

  - Add new user:
    - ```sudo useradd ghost -m -G users```
    - Set Password for the new user: ```sudo passwd ghost```
    - Set samba share password: ```sudo smbpasswd -a ghost``` > This will be used while accessing the NAS
4. **Finalize**: Set permissions
  - ```sudo chmod 771 /media/hdd/```
  - Now you can reboot and test the network share, to check the IP address of the Poplar, just run ```sudo ifconfig```

# 4) Conclusion

- Static IP: Since Poplar resets MAC on every boot, so does the IP address. You may want to consider setting up a static IP address following [Debian's Guide.](https://wiki.debian.org/NetworkConfiguration#Configuring_the_interface_manually)
- Speed: On my Windows based system I am getting transfer speeds greater than 100MB/s. However, on the same hardware running Linux I get around ~50-80MB/s and this is because of software overhead cased by samba. To overcome this you may want to look into creating [NFS Share](https://help.ubuntu.com/lts/serverguide/network-file-system.html)
- Download Server: Another functionality that I usually like to be added to my NAS is a download server. IMO [pyLoad](https://pyload.net/) is a great application to provide such functionality.
