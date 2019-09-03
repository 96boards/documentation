---
title: Linux Fastboot Installation for Bubblegum-96
permalink: /documentation/consumer/bubblegum-96/installation/linux-fastboot/
redirect_from: /documentation/ConsumerEdition/Bubblegum-96/Installation/LinuxFastboot/
---

## Linux Host

This section show how to install a new operating system to your Bubblegum-96 using the fastboot method on a Linux host computer.

### 1) Enter U-Boot Shell

The following steps assumes that the board is flashed with proper bootloaders.

- Make sure bubblegum-96 board is in power off mode
- Plug in the UART debug board and connect serial console to the host PC
   - Open a Serial Terminal like Minicom
   - Set baud rate as 115200
   - Set (8N1) – [8bit data, No-parity, & 1 stop bit]
- Connect the host PC with Bubblegum-96 USB3.0 port via type USB A-A cable
   - USB3.0 port on Bubblegum96 board is the blue port
   - This cable won’t provide Power, so it will not boot up the board
- Plug in power to the Bubblegum96 board

Open serial terminal and press `Enter` while U-Boot starts to enter the
U-Boot shell with `owl>` prompt.

> Note: If your board is not booting into U-Boot, then you may need to
recover your board by following the [Recovery Guide](./board-recovery/).

### 2) Download required images

Download the boot and root file system images from the [Download page](../downloads/debian/).

Once you have downloaded the appropriate files, continue to next step.

### 3) Enter Fastboot mode

> Note: The Fastboot mode is used to flash the images to on-board eMMC of the
Bubblegum-96 board.

Once you can access the U-Boot shell, execute `run create_gpt` command to
reconstruct the gpt table and it will show

`Writing GPT: success!.` at the serial terminal.

Execute `fastboot  usb` command to access fastboot mode. If the board is in
fastboot-mode, you will see a device ID `18d1:0c02` by entering the command
`lsusb` on host PC.

Now, proceed to the following sections to flash images to eMMC.

### 4) Flash kernel image

The kernel image of 96board is contained in `boot.emmc.img` file.

Please make sure you have already installed fastboot tool on your PC, if not, run the following command:

`$ sudo apt-get install android-tools-fastboot`

After that, continue flashing Bubblegum-96.

`$ sudo fastboot flash BOOT boot.emmc.img`

**Note:** `boot.emmc.img` is a vfat format image, it contains kernel image, initramfs image, device tree blob, logo image used by u-boot

### 5) Flash the root file system (rootfs)

The rootfs image of 96board is named as `bubblegum-jessie_alip_*.emmc.img`

`$ sudo fastboot flash SYSTEM bubblegum-jessie_alip_*.emmc.img`

**This step takes around 2 minutes or more depend on the image size.**

### 6) Create bootloader.img and Flash using fastboot

We need to flash the bootloader onto eMMC by fastboot. First we need to create
the `bootloader.img` image.

Use the following commands on Host pc to create the bootloader.img:

```shell
# Creates a 6MiB empty image.
$ dd if=/dev/zero of=bootloader.img bs=1M count=6
# Place bootloader.bin to correct place.
$ dd conv=notrunc if=bootloader.bin of=bootloader.img seek=4063 bs=512
# Place u-boot-dtb.img to correct place.
$ dd conv=notrunc if=u-boot-dtb.img of=bootloader.img seek=6110 bs=512
```

After preparing the `bootloader.img` image, use fastboot to flash BOOTLOADER
partition.

```shell
$ sudo fastboot flash BOOTLOADER bootloader.img
```

Once all of the above mentioned processes are completed successfully, reboot
the Bubblegum-96 board to boot the installed images!
