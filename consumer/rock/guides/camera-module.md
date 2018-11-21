---
title: Using CSI camera with Rock960 family boards
permalink: /documentation/consumer/rock/guides/camera-module.md.html
---

# Using CSI camera

## Introduction

This guide provides information about interfacing MIPI CSI2 camera with Rock960
boards. This guide is applicable for both Rock960 Model A&B and Model C.

## OV5645

The OV5645 is a 5MP MIPI CSI2 camera sensor. The driver supports three sensor modes:

* 2592x1944 15fps (full frame)
* 1920x1080 30fps (cropped from full frame)
* 1280x960 30fps

## Rockchip ISP

Rockchip ISP is the image signalling processor block found in Rockchip SoCs.
This ISP block enables the use of connecting dual MIPI CSI cameras and
processing the data stream. There are two ISP blocks present in RK3399 SoC
and each can handle 14 Megapixel range. However, only ISP0 is tested on
Rock960 boards and the same is documented in this guide.

Below are the major components of the ISP block:

* MIPI Serial Camera interface
* Image Signal Processing unit
* Many Image Enhancement Blocks
* Crop block
* Resize block

The driver implements the V4L2 subdev interface and Media Controller API.
With the goal to model the hardware links between the modules and to expose
a clean, logical and usable interface, the driver is split into V4L2
sub-devices as follows:

* rkisp1_mainpath
* rkisp1_selfpath
* rkisp1-isp-subdev
* rockchip-sy-mipi-dphy
* rkisp1-statistics
* rkisp1-input-params

More information about the ISP can be found in [Rockchip Wiki](http://opensource.rock-chips.com/wiki_Rockchip-isp1).

## [Camera Setup for Rock960 Model A&B](../rock960/guides/camera-setup.md)

## [Camera Setup for Rock960 Model C](../rock960c/guides/camera-setup.md)

## Basic usage

Make sure that the following package is installed:

    sudo apt-get install v4l-utils

To ensure that the sensor is properly connected and detected, you can inspect the output of the following command:

    sudo media-ctl -d /dev/media0 -p

If everything is ok, you should see something like this:
````
- entity 7: ov5645 2-003c (1 pad, 1 link)
            type V4L2 subdev subtype Sensor flags 0
            device node name /dev/v4l-subdev2
	pad0: Source
		[fmt:UYVY8_2X8/1280x960 field:none
		 crop:(0,0)/0x0]
		-> "rockchip-sy-mipi-dphy":0 [ENABLED]
````

### Direct dump to memory

Media controller pipeline will be configured during boot time itself. We
just need to set the resolution as below:

```shell
$ media-ctl --set-v4l2 '"rkisp1-isp-subdev":2[fmt:UYVY8_2X8/1920x1080 field:none]'
$ media-ctl --set-v4l2 '"rkisp1-isp-subdev":0[fmt:UYVY8_2X8/1920x1080 field:none]'
$ media-ctl --set-v4l2 '"ov5645 2-003c":0[fmt:UYVY8_2X8/1920x1080 field:none]'
```

The above commands configures the ISP and Camera sensor to 1920x1080 resolution.

Now enable OV5645 camera sensor for image capture:

```shell
$ media-ctl -l '"ov5645 2-003c":0->"rockchip-sy-mipi-dphy":0[1]'
```

Finally below command can be used to capture image from the camera:

```shell
$ gst-launch-1.0 rkcamsrc device=/dev/video0 ! videoconvert ! video/x-raw,format=NV12,width=1920,height=1080 ! jpegenc ! filesink location=image01.jpg
```
Or you can use GStreamer to show a live preview from the camera:

```shell
$ gst-launch-1.0 rkcamsrc ! 'video/x-raw,format=UYVY,width=1920,height=1080' ! glimagesink
```

> Note: Due to the ISP tuning issues, the captured image may appear greenish.
>       This issue will be resolved soon.
