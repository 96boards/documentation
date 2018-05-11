---
title: Installing Red Hat Enterprise Linux on Developerbox
permalink: /documentation/enterprise/developerbox/installation/rhel.html
---
# Table of Contents

   * [Downloading install media](#downloading-install-media)
   * [Quirks and workarounds](#quirks-and-workarounds)
      * [[Hardware] USB/PCIe networking](#hardware-usbpcie-networking)
      * [[Hardware] Uninstall the graphics card](#hardware-uninstall-the-graphics-card)
      * [[Firmware] Set O/S Hardware Description to ACPI](#firmware-set-os-hardware-description-to-acpi)
      * [[Install, First boot] Disable incompatible PCIe features](#install-first-boot-disable-incompatible-pcie-features)

<!-- Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc) -->

# Downloading install media

Installer images for Red Hat Enterprise Linux (RHEL for ARM) can be obtained
from Red Hat. If you qualify for the [Red Hat Developer
Program](https://developers.redhat.com/articles/red-hat-developer-program-benefits/)
installer images can be found at (no-cost registration required):
https://developers.redhat.com/products/rhel/download/ .

After downloading an installer image, please carefully study the list of
platform quirks and workarounds below. If you need further information
to complete the install process then there is a Developerbox specific
guide to [Booting an operating system installer](./) which can be read
alongside [the documentation on the Red Hat Customer
Portal](https://access.redhat.com/).

# Quirks and workarounds

These quirks and workarounds assume that users of Red Hat Enterprise
Linux value the enterprise support and/or ISV application certification
associated with the Red Hat ecosystem, and that its users and
administrators are reluctant to rely upon uncertified software from
volunteer maintained sources such as Extra Packages for Enterprise Linux
(EPEL). In such circumstances we can only recommend Developerbox for
headless server applications.

It is possible to use Developerbox as an enterprise workstation (albeit
without hardware accelerated 3D graphics) but this [works best with an
alternative desktop environment from a third
party](centos.md#quirks-and-workarounds-for-workstations) and it is not
documented here.

## [Hardware] USB/PCIe networking

Red Hat Enterprise Linux 7 is based on the v4.11 kernel, released in April 2017.
This kernel version does not include support for the built-in
network interface. This must be worked around by using an external
network device.

Both PCIe or USB network devices are suitable for this, although it is
important to select a device that is already supported by the Red Hat
Enterprise Linux
kernel. If in doubt, please ask on the [Developerbox
forum](https://discuss.96boards.org/c/products/developerbox).

## [Hardware] Uninstall the graphics card

For server applications it is recommend that Developerbox be run as a
headless system with the graphics card be removed entirely. When the
graphics card is removed all console activity (both EDK2 menus and the
Linux console) will automatically switch from using the graphics card to
using the debug UART. The debug UART is connected to the micro-USB
socket behind the I/O shield on the back panel.

The automatic switching of the console means the system maintenance
capabilities via the UART are equivalent to those available via
the graphics card, and the power saved as a result of removing the
graphics card is significant.

## [Firmware] Set O/S Hardware Description to ACPI

Red Hat Enterprise Linux 7 requires that the Developerbox platform hardware be 
described using ACPI. The firmware default is to use device
tree to describe the hardware so this must be changed.

To switch to ACPI mode:

 * Press **Escape** once the `Press ESCAPE for boot options` message
   appears
 * Select **Device Manager** and **SynQuacer Platform Settings**
 * Select **O/S Hardware Description** and choose **ACPI**
 * Press **Escape** and then press **Y** to save and exit
 * Press **Escape** again, to return to the main menu
 * Select **Reset**

## [Install, First boot] Disable incompatible PCIe features

Two features must be disabled to allow PCIe to enumerate and allocate
interrupts correctly. Patches to address the underlying issues are
regarded as bug fixes and will be backported to LTS kernels over time.

If your kernel is affected the workaround is described below

For install **and** first boot:

 * Wait for the grub menu to appear, then press **e** to edit the
   commands before booting
 * Use the editor to add `pcie_aspm=off pci=nomsi` to the kernel command line (this
   is the line commencing with the word `linux`)
 * Check this document for any other *[Install]* or *[First boot]*
   workarounds. Once all kernel arguments are updated, boot the kernel
   by pressing **Ctrl-X**.

To make the change permanent:

 * Wait for Red Hat Enterprise Linux to boot, then login and start a Terminal application
 * Edit `/etc/default/grub` as root, for example: `sudo vi /etc/default/grub`
 * Add `pcie_aspm=off pci=nomsi` to `GRUB_CMDLINE_LINUX`
 * Save the file and close the editor
 * Run `sudo grub2-mkconfig -o /boot/efi/EFI/redhat/grub.cfg` to
   regenerate the grub config files
