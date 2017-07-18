---
title: Hardware Notes for HiKey
permalink: /documentation/ConsumerEdition/HiKey/HardwareDocs/HardwareNotes.md/
---
# Hardware Notes

### CPU Load

The current supplied Linux 3.18-based kernel supports the thermal protection framework and DVFS. This will cause the HiKey CPU core frequencies to be reduced from the maximum 1.2GHz if the thermal setpoint of the SoC is reached. In an extreme case thermal shutoff will occur if DVFS has not been effective at reducing the SoC temperature to an acceptable level.

Higher performance may be obtained by using forced air (fan) cooling on the HiKey board.

<a name="section-52"></a>
### HDMI Port
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

**Debian Build**

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

**Android Build**

[Information on Android To Be Written]
At the moment resolution is locked at **1280x720p.**(do not use hotkey Alt+PrtScr+g).<br\>

**NOTE:** the fixed settings may not work on all monitors/TVs but have been demonstrated to work on most.

<a name="section-53"></a>
### USB Ports

There are multiple USB ports on the HiKey board:
- One microUSB OTG port on the front edge of the board
- Two Type A USB 2.0 host ports on the front edge of the board
- One USB 2.0 host port on the high-speed expansion bus

Please read the HiKey Board Hardware User Guide for more information on the following hardware restrictions:

1. The microUSB OTG port may be used (in host or slave mode) OR the Type A host ports may be used. They may not both be used simultaneously. If a cable is inserted into the OTG port then the Type A ports and the expansion bus port will be automatically disabled.
2. For the microUSB OTG port a single Low Speed (1.5Mbit/sec), Full Speed (12Mbit/sec) or High Speed (480Mbit/sec) device is supported.
3. For the USB host ports all attached USB devices MUST be one of the following two options:
    - Low Speed (1.5Mbit/sec) and Full Speed (12Mbit/sec) devices, or
    - High Speed devices (480Mbit/sec)

If a mixture of High Speed and Low/Full speed devices are attached the devices will not operate correctly. This also applies if any hubs are attached to the ports.

The reason for this limitation is that USB 2.0 split transfers are not supported by the mobile-targeted SoC hardware USB implementation.

In order to address this limitation the USB ports are by default configured into Low/Full speed operation.

In Debian the `usb_speed utility` (use `-h` option for help) is provided to switch the USB ports between modes (see [Other Useful Information](#section-15) above for details on this utility).

In the AOSP build a small application is provided (usb-speed-switch) to change between High Speed and Full Speed operation.

<a name="section-54"></a>
### UART Ports

In Debian, the two 96Boards expansion IO UART serial ports will appear as `/dev/ttyAMA2` and `/dev/ttyAMA3` and are configured at 115200 baud by default. Note: UEFI and kernel console are directed to /dev/ttyAMA3.

Alternatively, you can modify grub.cfg in the boot image to switch to other UART.

* /EFI/BOOT/grub.cfg (linux boot line) <br\>
`linux /boot/Image console=tty0 console=ttyAMA3,115200 root=/dev/disk/by-partlabel/system rootwait rw quiet efi=noruntime`

**NOTE:** the LS expansion port I/O pins on the 96Boards 2mm header, including the UART signals, are at **1.8V** logic levels.

***

## Known Issues

The following are known issues on the current release.

1. **Not Yet Supported**
    - HDMI and Expansion bus audio. (At present only Bluetooth audio is supported)
    - Some video formats are not decoded in Android, and will not be played with the current release
    - HDMI hotplug detection (HPD) is not supported. (Note: You can still plug in HDMI cable after the board booted, which make HDMI work through two candidate modes: 1280x720p and 800x600p. However these are not HPD, they is built-in default.)
    - Behaviors of power on button not following hardware user guide. [bug #160](https://bugs.96boards.org/show_bug.cgi?id=160)
    - HDMI display sometimes goes off when in AOSP. See [bug #136](https://bugs.96boards.org/show_bug.cgi?id=136)
2. **USB gives occasional non-fatal kernel trace messages**
`usb usb1: clear tt 1 (9032) error -22`
This is under current investigation.
3. **Apple Bluetooth Keyboards/Mice/Trackpads do not work**
This is under current investigation.
4. **Attempting BT file transfer on the Debian build freezes the board.**
This is under current investigation.
5. **Switching user may cause a blank screen**
Clicking on the Switch User button can cause the screen to go blank.
This is being investigated.
6. **Iceweasel browser exits after file download complete.**
When downloading a file using Iceweasel, the download works but the browser exits.
7. **Debian ALIP image: Viewing JPG images with 'Image Viewer' show incorrect colors.**
This is being investigated.
8. **Fastboot flashing on Windows is not supported. Only Linux PC is supported.**
9. **AOSP build can only work at 720p mode. When using 1080p mode, the color scheme is not stable.**
10. **Shutdown not working - executing 'reboot -p' from serial console will shutdown the board very quickly, but cannot turn off HDMI monitor, and the signal is still there.**
11. **UEFI may hang occasionally when the uSD card is present.**
12. **Hot plugging an SD card may not work on some UHS class 1 SD cards on AOSP build.**
13. **Display sleep may not always work on AOSP build.**

***

## Report a Bug

To report new issues with the HiKey please use the [96Boards Bug Tracker](https://bugs.96boards.org).

To view the open bugs, click [here](https://bugs.96boards.org/buglist.cgi?bug_status=__open__&list_id=144&order=Importance&product=HiKey&query_format=specific).  Alternatively go to the [site](https://bugs.96boards.org/), click on the Search menu item, select HiKey in the product dropdown list and click the search button.

To add a new bug, click [here](https://bugs.96boards.org/enter_bug.cgi?product=HiKey) and fill in the form.  Alternatively go to the [site](https://bugs.96boards.org/), click on the New menu item, then click on Consumer Edition Boards, then click on HiKey, and finally fill in the form.

***
