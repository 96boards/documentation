---
title: Beginner Guide to GPIO for CE Boards
permalink: /documentation/ConsumerEdition/CE-Extras/GPIO/Beginner/
redirect_from: /documentation/ConsumerEdition/CE-Extras/GPIO/Beginner/README.md/
---
# Beginner Guide

96Boards enabled pre-built libraries are easy to get, and in some cases might already be included in your current build image. This beginner's guide will show you how to set up, and use your libraries to program the various GPIO interfaces located on the low-speed expansion header of your 96Boards.

Before jumping into this guide, it is recommended to go through the [Low-Speed Expansion Header](../LSExpansionHeader/) document. Readers can use this document to become more familiar with the physical locations of various GPIO interfaces.

***

## Contents

- Update 96Boards system
- Install Libraries

***

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

Note: If at any point during this process you are prompted with a 'Y/N', select Y and press Enter.

***

## Install Libraries

This sections will show you how to install each library individually. Simple choose the library you wish install and execute the appropriate command

**libsoc** ([Read More](https://github.com/jackmitch/libsoc)):

```shell
$ sudo apt-get install libsoc-dev
```

**MRAA** ([Read More](https://github.com/intel-iot-devkit/mraa)):

```shell
$ sudo apt-get install libmraa-dev
```

**UPM** ([Read More](https://github.com/intel-iot-devkit/upm)):

```shell
$ sudo apt-get install libupm-dev
```

***

Once you have installed these libraries continue to our [Examples and Sample Code](../Examples/) page!
