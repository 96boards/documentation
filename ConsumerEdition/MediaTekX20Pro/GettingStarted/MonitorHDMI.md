## Monitor

A standard monitor or TV supporting at least 640x480 resolution is required. Interlaced operation is not currently supported. The maximum resolutions currently supported are 1920x1080p or 1920x1200p.

The image resolution of monitor should be bigger than what you set for X20 Board(720P default).

## HDMI

What you need are a Full size HDMI Cable and a HDMI capable monitor.

- The 96Boards specification calls for an HDMI port to be present on the board. The MT6797 doesn’t include a built-in HDMI interface.
- The Helio X20 Development Board deploys the built-in DPI interface as the source for the HDMI output. A peripheral Bridge IC (U6502, MT8193) performs this task and it supports a resolution from 480i to 1080p at 30Hz. 

The HDMI port on Helio X20 Development Board supports TVs and Monitors with an HDMI interface at display resolutions of 1920*1080 pixels down to 640*480 pixels. Note that interlaced display modes are not currently supported. The mobile SoC used on the Helio X20 Development Board does not have sufficiently flexible clocking arrangements to support allpossible HDMI timings specified by monitors. 

> Note: These modes are preferred and will be tried (in this order) first if they exist in EDID:

|   Resolution            |    Ratio               |    Usually on          |
|:------------------------|:-----------------------|:-----------------------|
| 1920*1080               | 16:9                   | TV                     |           
| 1280*720                | 16:9                   | TV                     |           
| 720*480                 | 4:3                    | Monitor                |           

*** 

