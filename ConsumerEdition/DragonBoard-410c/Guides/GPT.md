# Dragonboard 410c GPT

This page provides information to create a custom GUID Partition Table(GPT) for DragonBoard 410c. Note that flashing your own GPT will result in loss of data on the eMMC, make sure that you know what you are doing.

The following tool can be used to:
* create a SD card image
* create GPT file to be used with fastboot to flash GPT (e.g. gpt_both0.bin)

# Create a bootable SD card

It is possible to boot the entire OS from the SD card, without modifying the eMMC content, assuming you are using a Linux based system. The instructions in this section will not work with Android (or Windows).

To boot from the SD card, you will need a patched version of the bootloader (LK). Then you will need to create an SD card with a suitable GPT and proper bootloaders.

## Download the _SD boot_ bootloader package

    wget http://builds.96boards.org/snapshots/dragonboard410c/linaro/rescue/latest/dragonboard410c_bootloader_sd_linux-*.zip -O dragonboard410c_bootloader_sd_linux.zip

## Patched bootloader source code

If you want to see the LK changes needed for SD boot:

    # get LK source code
    git clone --depth 1 \
         https://git.linaro.org/landing-teams/working/qualcomm/lk.git \
         -b release/LA.BR.1.1.2-02210-8x16.0+sdboot lk_sdboot

## Create the SD card

To boot on the APQ8016, the boot media is required to have a very specific GPT. The tool below will take care of that. You can inspect the tool to understand the low level details. The SD card will be created with a default partition scheme that includes all the required boot partitions, as well as 2 partitions for the kernel and the rootfs, called 'boot' and 'rootfs'. Once the SD card is create you can load any valid boot image and root fs image into these partitions.

To create the bootable SD card:

    unzip -d qcom_bootloaders dragonboard410c_bootloader_sd_linux.zip
    git clone https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git
    cd db-boot-tools
    sudo ./mksdcard -o /dev/XXX -p dragonboard410c/linux/sdcard.txt \
     -i ../qcom_bootloaders -s 2G

Notes:
* /dev/XXX represents your SD card, plugged to your PC. The SD card will be completely erased during this process.  
* be very cautious about the SD card device name, or you could seriously damage your PC
* 2G is the size of the SD card image. It can be less than the actual SD card size, but not more.

When the command above finishes, your SD card should have the right GPT. You now need to provision a valid boot image and rootfs onto the SD card.

## Boot an OpenEmbedded image from SD card

You can for example boot one of our OpenEmbedded reference image from the SD card. First download the following files:
* http://builds.96boards.org/snapshots/reference-platform/openembedded/morty/dragonboard-410c/rpb/latest/boot--*-dragonboard-410c-*.img
* http://builds.96boards.org/snapshots/reference-platform/openembedded/morty/dragonboard-410c/rpb/latest/rpb-desktop-image-dragonboard-410c-*.rootfs.img.gz

The boot image will by default try to mount the root fs on the eMMC , so we need to modify the root parameter in the bootargs:

    abootimg -u boot-XXX.img -c "cmdline=root=/dev/mmcblk1p9 rw rootwait console=ttyMSM0,115200n8"

You can now write the boot and rootfs image into the SD card:

    sudo dd if=boot-XXX.img of=/dev/XXX7
    sudo dd if=rpb-desktop-image-dragonboard-410c-XXX.rootfs.img of=/dev/XXX9
    
Where:
* /dev/XXX7 represents the 'boot' partition on the SD card
* /dev/XXX9 represents the 'rootfs' partition on the SD card
* you can check the mapping between partition IDs and partition names using `gdisk -l` command

If you insert the SD card into the DragonBoard 410c and set the switch S6-2 (on the back) to ON, you should now be able to boot from SD card.

# Create gpt_both0.bin

gpt_both0.bin is a special format file for GPT that can be used with fastboot on Dragonboard, such as:

    fastboot flash partition gpt_both0.bin

When such command is executed, the GPT will be reflashed on the target, and it is very likely that all data on the eMMC is lost, and all firmware need to be reflashed.

To create gpt_both0.bin, you can run:

    git clone https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git
    # to create an empty image (sd.img) with the partition table from linux.txt
    sudo ./mksdcard -g -o sd.img -p dragonboard410c/linux/partitions.txt
    # create a gpt backup
    sudo sgdisk -bgpt.bin sd.img
    # convert gpt backup into proper 'fastboot' format
    ./mkgpt -i gpt.bin -o gpt_both0.bin

If you want to customize the partition table, you need to edit the file dragonboard410c/linux.txt. You can add partition as needed, change partition sizes, but you should not change the partition UID for the existing partitions that contain the bootloader and firmware, or you might brick your board.

If you want to add a few regular partitions, for example to install two Debian releases, you can do something like this:

    --- a/dragonboard410c/linux/partitions.txt
    +++ b/dragonboard410c/linux/partitions.txt
    @@ -6,4 +6,6 @@ hyp,512,E1A6A689-0C8D-4CC6-B4E8-55A4320FBD8A,hyp.mbn
     sec,16,303E6AC3-AF15-4C54-9E9B-D9A8FBECF401,sec.dat
     aboot,1024,400FFDCD-22E0-47E7-9A23-F16ED9382388,emmc_appsboot.mbn
     boot,65536,20117F86-E985-4357-B9EE-374BC1D8487D,
    +oe,786432
    +sid,2621440
     rootfs,0
