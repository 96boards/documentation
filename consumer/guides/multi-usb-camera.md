---
title: Using Multiple USB Cameras on a single USB Hub
permalink: /documentation/consumer/guides/multi-usb-camera.md.html
redirect_from: /documentation/ConsumerEdition/guides/multi-usb-camera.md.html
---

# Using Multiple USB Cameras on a single USB Hub

This page provides information to connect and use multiple USB webcams on a single USB port using a USB Hub. This guide assumes that you have installed the latest release of Debian for the Dragonboard 410c.

# Table of Contents

- [1) Update 96Boards system](#1-update-96boards-system)
- [2) Software Required](#2-software-required)
- [3) Hardware Required](#3-hardware-required)
- [4) Using Multiple USB Cameras](#4-using-multiple-usb-cameras)

# 1) Update 96Boards system

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

# 2) Software Required
- Install v4l-utils
```shell
$ sudo apt install v4l-utils
```

- Install vlc
```shell
$ sudo apt install vlc
```

# 3) Hardware Required
- DragonBoard-410c
- USB 2.0 Hub
- 2 or more USB Webcams, Logitech C720 Recommended

# 4) Using Multiple USB Cameras

- The theoretical bandwidth of a USB 2.0 Hub is 480mbps or ~60MBps. Adding a USB HUB divides that bandwidth across our three cameras giving us approximately ~20MBps per camera. S the trick is to make sure we are well within that limit.

- Although this guide follows ```vlc```, the concept can be applied to any other software using v4l2 driver.

- Majority of the webcams are compatible with this guide, although there are some webcams that do not play well and allocate bandwidth for large uncompressed frames regardless of what data they actually transmit. Such webcams will not work with this guide. More info on this bug, where cameras over request bandwidth can be found here: http://www.ideasonboard.org/uvc/faq/#faq7

- On VLC if we directly use ```v4l2:///dev/video0```, we get the RAW and Uncompressed sensor data from the webcam that ends up hogging the bandwidth

- Next step is to use compressed data using ```v4l2:///dev/video0:chroma=mjpg``` which gives us a compressed MJPEG data stream, it is still not enough.

- Next we reduce the resolution using ```v4l2:///dev/video0:chroma=mjpg:width=640:height=480```. This dramatically reduces the bandwidth requirement but it's still only enough for two cameras.

- From this point on we could either keep reducing the resolution or reduce the frame rate in half ```v4l2:///dev/video0:chroma=mjpg:width=640:height=480:fps=15```, this allows me to stream from upto three Webcams.

- Replace video0 with video1, video2 or the device id for your webcam.

> This is a trial an error process and depends upon the exact setup, some more tweaking may be necessary depending upon you setup.

- **References: ** https://wiki.videolan.org/Documentation:Modules/v4l2/
