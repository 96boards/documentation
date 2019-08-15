---
title: Installing Ubuntu on Developerbox
permalink: /documentation/enterprise/developerbox/installation/ubuntu.html
---
# Table of Contents

   * [Downloading install media](#downloading-install-media)
   * [Quirks and workarounds](#quirks-and-workarounds)
      * [[Hardware] Enable PCIe transaction size workaround](#hardware-enable-pcie-transaction-size-workaround)
      * [[Install] USB/PCIe networking (18.04 only)](#install-usbpcie-networking-1804-only)
      * [[First boot] Disable splash screen](#first-boot-disable-splash-screen)
      * [[First boot] Enable GT-710 clock mode workaround](#first-boot-enable-gt-710-clock-mode-workaround)

<!-- Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc) -->

# Downloading install media

The following installer images are suitable for use on your Developerbox:

 * [Network installer
   (mini.iso)](http://ports.ubuntu.com/dists/bionic/main/installer-arm64/current/images/netboot/mini.iso)

After downloading an installer image, please carefully study the list of
platform quirks and workarounds below. If you need further information
to complete the install process then there is a Developerbox specific
guide to [Booting an operating system installer](./) which should be
read together with the [Ubuntu Installation Guide for
arm64](https://help.ubuntu.com/lts/installation-guide/arm64/index.html)

# Quirks and workarounds

These quirks and workarounds assume the `O/S Hardware Description`
firmware option is set to its default setting (`<Device Tree>`).

## [Hardware] Enable PCIe transaction size workaround

The current revision of SC2A11 contains PCIe bus integration logic that
does not correctly split certain types of bus transaction. These
transactions are commonly initiated to PCIe devices with on board RAM,
such as graphics cards. The Developerbox firmware is able to partially
workaround this issue by using the virtualization hardware to prohibit
certain types of memory mapping.

See the [Known
Issues](/documentation/enterprise/developerbox/support/known-issues.md##64-bit-pcie-transactions) for more
details.

The firmware workaround is controlled by `DSW3-2`. Ensure this DIP
switch is in the **on** position before starting the installer.

## [Install] USB/PCIe networking (18.04 only)

The kernel used by the 18.04 installer shipped before a last minute
issue with the on board networking was discovered and fixed. This can be
worked around by using an external network device during the install
process.

Both PCIe or USB network devices are suitable for this, although it is
important to select a device that is already supported by the Ubuntu
kernel. If in doubt, please ask on the [Developerbox
forum](https://discuss.96boards.org/c/products/developerbox).

## [First boot] Disable splash screen

The current revision of SC2A11 contains PCIe bus integration logic that
does not correctly split certain types of bus transaction. These
transactions are commonly initiated to PCIe devices with on board RAM,
such as graphics cards. The Developerbox firmware is able to partially
workaround this issue but it is still necessary to disable the Ubuntu
splash screen.

On first boot:

 * Press **Shift** once the `Press ESCAPE for boot options` message
   appears, this will bring up the grub menu
 * Press **e** to edit the commands before booting
 * Use the editor to remove `splash` from the kernel command line (this
   is the line commencing `linux  /boot/vmlinuz...`)
 * Check this document for any other *[First boot]* workarounds. Once
   all kernel arguments are updated, boot the kernel by pressing **F10**.

To make the change permanent:

 * Wait for Ubuntu to boot, then login and start a Terminal application
 * Edit `/etc/default/grub` as root, for example: `sudo nano /etc/default/grub`
 * Remove `splash` from `GRUB_CMDLINE_LINUX_DEFAULT`
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

 * Wait for Ubuntu to boot, then login and start a Terminal application
 * Edit `/etc/default/grub` as root, for example: `sudo nano /etc/default/grub`
 * Add `nouveau.config=NvClkMode=auto` from `GRUB_CMDLINE_LINUX_DEFAULT`
 * Save the file and close the editor
 * Run `sudo update-grub` to regenerate the grub config files
---
## Back to [Download and Installation page](../installation/)
