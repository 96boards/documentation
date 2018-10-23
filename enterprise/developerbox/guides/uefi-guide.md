---
title: UEFI user guide
permalink: /documentation/enterprise/developerbox/guides/uefi-guide.md.html
---
# Table of Contents

  * [UEFI boot menu tree](#uefi-boot-menu-tree)
  * [Configure boot options](#configure-boot-options)
    * [Add boot option](#add-boot-option)
    * [Delete boot option](#delete-boot-option)
    * [Change boot order](#change-boot-order)
  * [Configure platform settings](#configure-platform-settings)
    * [Set eMMC enable](#set-emmc-enable)
    * [Select hardware description](#select-hardware-description)

<a name="uefi-boot-menu-tree"></a>
# UEFI boot menu tree

  * Device Manager
    * Driver Health Manager
    * RAM Disk Configuration
    * Tls Auth Configuration
    * SynQuacer Platform Settings
      * PCIe x4 slot max speed
      * PCIe x1 slot 1 max speed
      * PCIe x1 slot 2 max speed
      * Enable on-board eMMC
      * O/S Hardware Description
    * Console Preference Selection
    * 96boards Mezzanine options
    * iSCSI Configuration
    * Network Device List
  * Boot Manager
  * Boot Maintenance Manager
    * Boot Options
      * Add Boot Option
      * Delete Boot Option
      * Change Boot Order
    * Driver Options
    * Console Options
    * Boot From File

<a name="configure-boot-options"></a>
# Configure boot options

<a name="add-boot-option"></a>
## Add boot option
To add new grub boot option:

* Select **Boot Maintenance Manager** and **Boot Options**
* Select **Add Boot Option**
* Select entry at **File Explorer**, note that only FAT/VFAT partition
  is listed here
* Find EFI grub application and select
* Select **Input the description** and enter boot option label
* Select **Commit Changes and Exit**

<a name="delete-boot-option"></a>
## Delete boot option

* Select **Boot Maintenance Manager** and **Boot Options**
* Select **Delete Boot Option** from the Boot Options menu
* Select **Debian**, then press F10
* Select **Commit Changes and Exit**

<a name="change-boot-order"></a>
## Change boot order

* Select **Boot Maintenance Manager** and **Boot Options**
* Select **Change Boot Order**
* Select the boot option list
* Change order with "+" or "-"
* Make sure if the order changed and select **Commit Changes and Exit**

<a name="configure-platform-settings"></a>
# Configure platform settings

<a name="set-emmc-enable"></a>
## Set eMMC enable

* Select **Device Manager** and **SynQuacer Platform Settings**
* Select **Enable on-board eMMC** and choose **Enabled**
* Press **Escape** and then press **Y** to save and exit
* Press **Escape** again, to return to the main menu
* Select **Reset**

<a name="select-hardware-description"></a>
## Select hardware description

* Select **Device Manager** and **SynQuacer Platform Settings**
* Select **O/S Hardware Description** and choose **ACPI** or **Device Tree**
* Press **Escape** and then press **Y** to save and exit
* Press **Escape** again, to return to the main menu
* Select **Reset**
