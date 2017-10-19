---
title: Guides
permalink: /documentation/ConsumerEdition/guides/mraa/install.md.html
---

# Installation guide for MRAA library on 96Boards CE

Following instructions provides information about installing the MRAA library as a package and building from source.

## Update 96Boards system

The image on your board might be out of date. This is possible even when using the stock image (the operating system your board was shipped with), or a newly flashed version from the 96Boards.org website.

A few useful commands will help us make sure everything on the board is current:

- **apt-get update**: Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade**: Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade**: In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt-get update

$ sudo apt-get upgrade

$ sudo apt-get dist-upgrade
```

> Note: If at any point during this process you are prompted with a 'Y/N', select Y and press Enter.

## Install as a package

The following command installs MRAA library as a package.
```shell
$ sudo apt-get install libmraa-dev
```

## Build from source

Following instructions specifies installing MRAA library from source.

```shell
$ git clone https://github.com/intel-iot-devkit/mraa.git<Enter>
$ mkdir -p mraa/build<Enter>
$ cd mraa/build<Enter>
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ..<Enter>
$ make <Enter>
$ sudo make install<Enter>
$ sudo ldconfig /usr/local/lib<Enter>
```

Once you have successfully built the library you can reset the system to pick up all of the changes.

**Commands:** Reset the system

```shell
$ sudo reboot<Enter>
```
