---
title: Installing Debian on Developerbox
permalink: /documentation/enterprise/developerbox/installation/debian.html
---
# Table of Contents

   * [Downloading install media](#downloading-install-media)
   * [Quirks and workarounds](#quirks-and-workarounds)
      * [[Hardware] Enable PCIe transaction size workaround](#hardware-enable-pcie-transaction-size-workaround)
      * [[Hardware] USB/PCIe networking](#hardware-usbpcie-networking)
      * [[Hardware] Ensure graphics card is in the x16 slot](#hardware-ensure-graphics-card-is-in-the-x16-slot)
      * [[Firmware] Set O/S Hardware Description to ACPI](#firmware-set-os-hardware-description-to-acpi)
      * [[Install, First boot] Disable incompatible PCIe features (&lt;=9.4 only)](#install-first-boot-disable-incompatible-pcie-features-94-only)
      * [[First boot] Enable GT-710 clock mode workaround](#first-boot-enable-gt-710-clock-mode-workaround)

<!-- Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc) -->

# Downloading install media

The following installer images are suitable for use on your Developerbox:

 * [Network installer (mini.iso)](https://www.debian.org/CD/netinst/)

After downloading an installer image, please carefully study the list of
platform quirks and workarounds below. If you need further information
to complete the install process then there is a Developerbox specific
guide to [Booting an operating system installer](./) which should be
read together with the [Debian GNU/Linux Installation Guide for
arm64](https://www.debian.org/releases/stable/arm64/).

# Quirks and workarounds

## [Hardware] Enable PCIe transaction size workaround

The current revision of SC2A11 contains PCIe bus integration logic that
does not correctly split certain types of bus transaction. These
transactions are commonly initiated to PCIe devices with on board RAM,
such as graphics cards. The Developerbox firmware is able to partially
workaround this issue by using the virtualization hardware to prohibit
certain types of memory mapping.

See the [Known
Issues](../support/known-issues.md##64-bit-pcie-transactions) for more
details.

The firmware workaround is controlled by `DSW3-2`. Ensure this DIP
switch is in the **on** position before starting the installer.

## [Hardware] USB/PCIe networking

Debian 9 (stretch) is based on the v4.9 kernel, released at the end
of 2016. The v4.9 kernel does not include support for the built-in
network interface. This must be worked around by using an external
network device.

Both PCIe or USB network devices are suitable for this, although it is
important to select a device that is already supported by the Debian
kernel. If in doubt, please ask on the [Developerbox
forum](https://discuss.96boards.org/c/products/developerbox).

## [Hardware] Ensure graphics card is in the x16 slot

Debian 9 (stretch) is based on a kernel without sufficient support for
Developerbox to access a PCIe graphics card across a bridge.

Both PCIe x1 slots are connected to a bridge. If you have a graphics
card installed in your Developerbox it must use the x16 slot.

## [Firmware] Set O/S Hardware Description to ACPI

Debian 9 (stretch) is based on the v4.9 kernel, released at the end
of 2016. This kernel does not contain sufficient support for boot
Developerbox from a device tree. This is solved by changing the
hardware description from device tree to ACPI.

To switch to ACPI mode:

 * Press **Escape** once the `Press ESCAPE for boot options` message
   appears
 * Select **Device Manager** and **SynQuacer Platform Settings**
 * Select **O/S Hardware Description** and choose **ACPI**
 * Press **Escape** and then press **Y** to save and exit
 * Press **Escape** again, to return to the main menu
 * Select **Reset**

## [Install, First boot] Disable incompatible PCIe features (<=9.4 only)

Two features must be disabled to allow PCIe to enumerate and allocate
interrupts correctly. Patches to address the underlying issues are
regarded as bug fixes and we expect these to be backported to stable
kernels. Once these get into the Debian images (expected in Debian 9.5)
then these features need no longer be explicitly disabled.

If your kernel is affected the workaround is described below

For install and first boot:

 * Wait for the grub menu to appear, then press **e** to edit the commands before booting
 * Use the editor to add `pcie_aspm=off pci=nomsi` to the kernel command line (this
   is the line commencing with the word `linux`)
 * Check this document for any other *[First boot]* workarounds. Once
   all kernel arguments are updated, boot the kernel by pressing **F10**.

To make the change permanent:

 * Wait for Debian to boot, then login and start a Terminal application
 * Edit `/etc/default/grub` as root, for example: `sudo nano /etc/default/grub`
 * Add `pcie_aspm=off pci=nomsi` to `GRUB_CMDLINE_LINUX_DEFAULT`
 * Save the file and close the editor
 * Run `sudo update-grub` to regenerate the grub config files

## [First boot] Enable GT-710 clock mode workaround

The GT-710 graphics card provided in the kit may occasionally freeze.
This is a generic nouveau driver issue that affects many different
kernel versions across both x86 and Arm platforms. It can be worked
around by passing a config option to the nouveau driver.

On first boot:

 * Press **Shift** once the `Press ESCAPE for boot options` message
   appears, this will bring up the grub menu
 * Press **e** to edit the commands before booting
 * Use the editor to add `nouveau.config=NvClkMode=auto` to the kernel
   command line (this is the line commencing `linux /boot/vmlinuz...`)
 * Check this document for any other *[First boot]* workarounds. Once
   all kernel arguments are updated, boot the kernel by pressing **F10**.

To make the change permanent:

 * Wait for Debian to boot, then login and start a Terminal application
 * Edit `/etc/default/grub` as root, for example: `sudo nano /etc/default/grub`
 * Add `nouveau.config=NvClkMode=auto` from `GRUB_CMDLINE_LINUX_DEFAULT`
 * Save the file and close the editor
 * Run `sudo update-grub` to regenerate the grub config files

 # Back to [Download and Installation page](README.md)

