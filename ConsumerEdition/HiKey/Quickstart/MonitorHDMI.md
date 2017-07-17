---
title: Monitor Guide for HiKey
permalink: /documentation/ConsumerEdition/HiKey/QuickStart/Monitor.md/
---
## Monitor

A standard monitor or TV supporting at least 640x480 resolution is required. Interlaced operation is not currently supported. The maximum resolutions currently supported are 1920x1080p or 1920x1200p.

## HDMI Port

The HDMI port on HiKey supports TVs and Monitors with an HDMI interface at display resolutions of 1920x1080 (or 1920x1200) pixels down to 640x480 pixels. Note that interlaced display modes are not currently supported. **The mobile SoC used on the HiKey board does not have sufficiently flexible clocking arrangements to support all possible HDMI timings specified by monitors.** A list of monitors/TVs can/cannot work with HiKey is stored [here](https://docs.google.com/spreadsheets/d/1aYNUlGx5J8RmfWrtML4lFJ-7tV8u-3AH_3IaiOlWfoE/edit?usp=sharing).

Note also that these modes are preferred and will be tried (in this order) first if they exist in EDID:

Resolution | Ratio | Usually on
---------- | ----- | ----------
1920x1200 | 16:10 | Monitor
1920x1080 | 16:9 | TV
1680x1050 | 16:10 | Monitor
1280x1024 | 5:4 | Monitor
1280x720 | 16:9 | TV
800x600	| 4:3 | TV

### Debian Build

The Debian build uses Linux DRM drivers for the graphics system. When first powered up the board will attempt to read the EDID display data from the attached TV/monitor. It will then select the highest resolution format available up to 1920x1080 pixels. If all is well the selected default will work on your TV/Monitor and no more needs to be done. However, in some cases your monitor may not display correctly on the selected setting because the timing is not exactly correct. In this case we have provided a facility to enable you to cycle through the available EDID modes to find one that works correctly for your TV/Monitor.

After the board has booted the User0 LED should be heartbeating about once per second. Using a connected keyboard cycle through the available EDID modes using the following key sequence: Right_Alt + PrintScr + G

Press the right hand Alt Key then the PrintScr key and then the G key so that finally all the keys are pressed. Each time you enter this sequence the HiKey will switch to the next screen mode. When you find one that works well write down the resolution and frequency from the TV display - for example 1280x1024@75Hz.

Once you have found a working resolution you may edit grub.cfg to make the new mode the default boot mode. Be very careful not to make mistakes editing this file or your kernel may not boot correctly. Note this file needs su privileges to modify:
```
$ sudo vim /EFI/BOOT/grub.cfg
```
Add the chosen display format into the file at the end of the linux line in the following format, replacing 1280x1024 with your selected resolution and 75 with your selected frequency.
```
video=HDMI-A-1:1280x1024@75
```
[Note - at present the desktop screen does not resize correctly for each resolution - this is planned to be fixed in a future release.]

Finally, **if you are still having difficulties you can revert to a built-in 720p mode by starting up the HiKey with no HDMI device attached**. The UI will then come up at a fixed 1280x720 resolution which will be used when you then plug the HDMI monitor in. **Pressing hotkey Alt+PrtScr+g  will switch to a built-in 800x600 mode, then cycle back.**

### Android Build

[Information on Android To Be Written]
At the moment resolution is locked at **1280x720p.**(do not use hotkey Alt+PrtScr+g).<br\>

**NOTE:** the fixed settings may not work on all monitors/TVs but have been demonstrated to work on most.
