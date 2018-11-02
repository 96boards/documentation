---
title: Debian Downloads for HiKey960
permalink: /documentation/consumer/hikey/hikey960/downloads/Debian.md.html
redirect_from:
- /documentation/ConsumerEdition/HiKey960/Downloads/Debian.md.html
- /documentation/consumer/hikey960/downloads/Debian.md.html
---
# Debian

**Debian for Hikey960** is a console (command line) based development environment derived from Debian GNU/Linux and comprised of some basic programs and utilities. Development can happen directly on the board, and within the OS. While applications and programs can be built directly on the board, they can also be built remotely and cross-compiled for the particular system.

Please take note that **Debian for Hikey960** is an **unreleased snapshot** (of an out-of-hours skunkworks project) rather than a fully featured release. Currently the snapshot does not support HDMI output and must be administered via [LS-UART1](https://www.96boards.org/pinout/). Visit the [96Boards forum](https://discuss.96boards.org/c/products/hikey960) to take part in the community and/or to learn about alternative kernel options the enable graphics.

Warning: *All I/O signals on the Low Speed Connector use 1.8v TTL. Applying a higher voltage could damage your device so always ensure your UART adapter supports 1.8v operation **before** connecting it (mistakes can happen so we strongly recommend you check the adapter even if it came as part of a kit).*

***

## SD Card image

|   SD Card Image   |    [Download](http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest/linaro-stretch-developer-hikey-*.sd.gz) |
|:------------------|:------------------------------------|
|Release Notes:     |[Link](http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest)       |

### Continue to [Installation page](../installation/)

***

## Fastboot files

|   Bootloader    |
|:----------------------------:|
| [l-loader.bin](http://snapshots.linaro.org/96boards/reference-platform/components/uefi-staging/latest/hikey960/debug/l-loader.bin)     |
|  [fip.bin](http://snapshots.linaro.org/96boards/reference-platform/components/uefi-staging/latest/hikey960/debug/fip.bin)              |
| [prm_ptable.img](http://snapshots.linaro.org/96boards/reference-platform/components/uefi-staging/latest/hikey960/debug/prm_ptable.img) |

|   Boot image      |    [Download](http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest/boot-linaro-stretch-developer-hikey-*.img.gz)      |
|:------------------|:-----------------------|
|Release Notes:     |[Link](http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest)      |

|   Rootfs image    |    [Download](http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest/rootfs-linaro-stretch-developer-hikey-*.img.gz)     |
|:------------------|:----------------------------------|
|Release Notes:     |[Link](http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest)      |

### Continue to [Installation page](../installation/)
