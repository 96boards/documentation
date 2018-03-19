---
title: Install Over HTTP
permalink: /documentation/enterprise/developerbox/guides/install-over-http.md
---
# Install Over HTTP

The system firmware of your Developerbox includes a feature called `Ram
Disk Boot from HTTP`. This allows the system firmware to download an ISO
image containing a UEFI-compliant file system. The firmware is able to
boot from the ISO image and, additionally, the ISO image will be mounted
as a RAM disk by HTTP Boot driver, allowing the image to be used in the
subsequent boot process.

The system firmware is preconfigured to obtain a network address using
DHCP and even has boot configuration that can _Install Debian Stretch over HTTP_
installed automatically when the board is manufactured.

## Using _Install Debian Stretch over HTTP_

To boot the installer try:

 * Boot your Developerbox and press `Escape` to enter the EDK2 menu system
 * Select _Boot Manager_
 * Select _Install Debian Stretch over HTTP_

This will launch the installer. Further information on how to install
Debian can be found in the [Debian GNU/Linux Installation Guide][1] or,
alternatively, watch a screen cast of an end-to-end install process:

[![asciicast](https://asciinema.org/a/146683.png)](https://asciinema.org/a/146683)

[1]: https://www.debian.org/releases/stable/arm64/

## Adding alternative boot configurations

To add an additional HTTP Boot Configuration for a different operating
system installer try:

 * Boot your Developerbox and press `Escape` to enter the EDK2 menu system
 * Select _Device Manager_
 * Select _Network Device List_
 * Select your MAC address, for example: _MAC:FC:AF:96:B0:A4:D5_
 * Select _HTTP Boot Configuration_
 * Select _Input the description_ and enter a suitable label, for example: `Boot danix from HTTP`
 * Choose the appropriate _Internet protocol_ (either _IP4_ or _IP6_)
 * Select _Boot URI_ and provide the download location for your ISO image
 * Press `F10` followed by `Y` to save the entry
 * Press `Escape` multiple times until you reach the main menu
 * Select _Boot Manager_
 * Choose you new boot label from the list

[![asciicast](https://asciinema.org/a/169593.png)](https://asciinema.org/a/169593)
