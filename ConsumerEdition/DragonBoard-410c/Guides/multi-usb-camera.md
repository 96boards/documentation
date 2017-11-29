---
title: Using Multiple USB Cameras on a single USB Hub
permalink: /documentation/ConsumerEdition/DragonBoard-410c/Guides/multi-usb-camera.md.html
---

# Using Multiple USB Cameras on a single USB Hub

This page provides information to connect and use multiple USB webcams on a single USB port using a USB Hub. This guide assumes that you have installed the latest release of Debian for the Dragonboard 410c.

# Table of Contents

- [1) Software Required](#1-software-required)
- [2) Hardware Required](#2-hardware-required)
- [3) Using Multiple USB Cameras](#3-using-multiple-usb-cameras)
- [4) Footnotes](#4-footnotes)

# 1) Software Required
- Install v4l-utils
```shell
$ sudo apt install v4l-utils
```

- Install vlc
```shell
$ sudo apt install vlc
```

# 2) Hardware Required
- DragonBoard-410c
- USB 2.0 Hub
- 2 or more USB Webcams, Logitech C720 Recommended

# 3) Using Multiple USB Cameras

- The theoretical bandwidth of a USB 2.0 Hub is 480mbps or ~60MBps. Adding a USB HUB divides that bandwidth across our three cameras giving us approximately ~20MBps per camera. S the trick is to make sure we are well within that limit.

- On VLC if we directly use ```v4l2:///dev/video0```, we get the RAW and Uncompressed sensor data from the webcam that ends up hogging the bandwidth

- Next step is to use compressed data using ```v4l2:///dev/video0:chroma=mjpg``` which gives us a compressed MJPEG data stream, it is still not enough.

- Next we reduce the resolution using ```v4l2:///dev/video0:chroma=mjpg:width=640:height=480```. This dramatically reduces the bandwidth requirement but it's still only enough for two cameras.

- From this point on we could either keep reducing the resolution or reduce the frame rate in half ```v4l2:///dev/video0:chroma=mjpg:width=640:height=480:fps=15```, this allows me to stream from upto three Webcams.

- NOTE: replace video0 with video1, video2 or the device id for your webcam.

# 4) Footnotes

- **Note 1:** Although this guide follows ```vlc```, the concept can be applied to any other software using v4l2 driver.
- **Note 2:** Majority of the webcams are compatible with this guide, although there are some webcams that do not play well with v4l2 and will send uncompressed data stream irrespective of the command. Such webcams will not work with this guide.
- **Note 3** This is a trial an error process and depends upon the exact setup, some more tweaking may be necessary depending upon you setup.

- **References: ** https://wiki.videolan.org/Documentation:Modules/v4l2/
