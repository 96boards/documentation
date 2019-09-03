---
title: Known issues with your Developerbox
permalink: /documentation/enterprise/developerbox/support/known-issues.html
---
# Table of Contents

   * [Known hardware issues with your Developerbox](#known-hardware-issues-with-your-developerbox)
      * [64-bit PCIe transactions](#64-bit-pcie-transactions)
      * [GT-710 display freeze](#gt-710-display-freeze)
   * [Common software issues](#common-software-issues)
      * [DHCP failures and/or poor performance with on-board networking](#dhcp-failures-andor-poor-performance-with-on-board-networking)
      * [nouveau with 64k pages](#nouveau-with-64k-pages)

<!-- Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc) -->


# Known hardware issues with your Developerbox

## 64-bit PCIe transactions

The current revision of SC2A11 contains PCIe bus integration logic that
does not correctly split certain types of bus transaction. These
transactions are commonly initiated to PCIe devices with on board RAM,
such as graphics cards. It is possible for other types of device to be
affected if their drivers explicitly initiate 64-bit transactions
(thankfully a scan of the Linux kernel suggests such drivers are fairly
uncommon).

The issue is deterministic and results in the system freezing either as
soon as an affected PCIe card is initialized or when a specific feature
of an affected PCIe card is used for the first time.

It is not possible to entirely workaround this issue but it can be
partially mitigated in a variety of ways:

1. A firmware workaround is available. This will configure the
   virtualization hardware to prohibit certain types of memory
   mapping. The workaround is controlled using `DSW3-2`, and is
   enabled then the DIP switch is **on**.

   The workaround has been tested heavily with the nVidia GT-710
   graphics card found in the Developerbox kit. It allows an
   unmodified nouveau driver to run 3D accelerated programs.

   The workaround is not sufficient to enable all GT-710 features.
   In particular hardware video decode acceleration does not work,
   although the workaround is sufficient to prevent a full system
   freeze (the video decoder application will crash but other
   applications are unaffected). Additionally there may be problems
   associated with the splash screen in some distros. Workarounds
   for splash screen problems are distro dependent, consult the
   [list of third party operating systems](../downloads/) for more
   information.

   Finally, because the workaround is implemented using the
   virtualization hardware, deploying this workaround will automatically
   disable KVM support in the kernel.

2. A kernel patch can be applied. This implements the same workaround
   as the firmware workaround above but it does so without using the
   virtualization hardware which means KVM support will not be disabled.
   This approach requires you to patch and build the kernel yourself.

   We recommend that #1 be used in order to complete the install
   process, it is then possible to transition to this workaround
   instead. We recommend you contact the [Developerbox
   forum](https://discuss.96boards.org/c/products/developerbox) to
   ensure you get the correct patch for your kernel.

3. The nouveau driver can be disabled. When the nouveau driver is
   disabled the kernel will render graphics to the EFI framebuffer
   configured by the firmware. This reduces the graphics card to a
   dumb device that scans out from a fixed frame buffer. Depending
   on your distro, 3D operations will either by unavailable or
   emulated in software running the Cortex-A53 processors. In either
   case adopting a lightweight desktop environment with limited use
   of 3D hardware (e.g. LXDE, XFCE) is strongly recommended.

   To deploy this workaround add the following to your kernel command
   line:

   ~~~
   modprobe.blacklist=nouveau
   ~~~

4. It is possible to run Developerbox headless. If you wish to use
   your Developerbox as a build server or for some similar role, then
   you may prefer to remove the graphics card entirely. When the graphics
   card is removed all console activity (both EDK2 menus and the Linux
   console) will automatically switch from using the graphics
   card to using the debug UART. The debug UART is connected to the
   micro-USB socket behind the I/O shield on the back panel.

   The automatic switching of the console means the system maintenance
   capabilities via the UART are equivalent to those available via the
   graphics card, and the power saved as a result of removing the
   graphics card is significant. For that reason we would recommend
   running Developerbox headless for edge or build server applications
   regardless of whether or not your board is impacted by this issue.

## GT-710 display freeze

The GT-710 graphics card provided in the kit may occasionally freeze.
This is a generic nouveau driver issue that affects many different
kernel versions across both x86 and Arm platforms.

This issue is non-deterministic and the frequency of failure can vary
from anywhere between a few minutes and several days.

It can be worked around by adding the following to your kernel command
line.

~~~
nouveau.config=NvClkMode=auto
~~~

Detailed instructions on how to modify the kernel command line are
distro dependent, consult the [list of third party operating
systems](../downloads/) for more information.


# Common software issues

## DHCP failures and/or poor performance with on-board networking

Early versions of the kernel driver for the on-board networking card
do not configure the interrupts correctly. This can result in DHCP
failures and/or extremely poor performance when using the on-board
networking. This is especially common in installers because they often
configure networking in a subtly different way to the installed OS and
also because they often do not upgrade the kernel as frequently as the
underlying distro.

This is known to impact mainline v4.16(.0) kernels together with
distro kernels that use backported drivers taken from this kernel.

It can be worked around by using an external network device during
the install process. Both PCIe or USB network devices are suitable for
this, although it is important to select a device that is already
supported by your chosen operating system.

## nouveau with 64k pages

The nouveau driver for the GT-710 graphics card included in the kit
will not initialize successfully on systems with 64k pages.

This issue is deterministic and results in a freeze during boot.

It can be worked around either by rebuilding the kernel and switching to
4k pages or by disabling the nouveau driver. When the nouveau driver is
disabled the kernel will render graphics to the EFI framebuffer
configured by the firmware. This reduces the graphics card to a dumb
device that scans out from a fixed frame buffer. Depending on your
distro 3D operations will either by unavailable or emulated in software
running the Cortex-A53 processors. In either case adopting a lightweight
desktop environment with limited use of 3D hardware (e.g. LXDE, XFCE) is
strongly recommended.

To disable the nouveau driver add the following to your kernel command
line:

~~~
modprobe.blacklist=nouveau
~~~

Detailed instructions on how to modify the kernel command line are
distro dependent, consult the [list of third party operating
systems](../downloads/) for more information.
