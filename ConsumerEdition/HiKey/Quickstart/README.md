# Quickstart

Learn about your HiKey board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- [Power adapter](PowerAdapter.md)
   - 96Boards specifications requires a 6.5V-18V with 2000mA Power adapter
- [USB Keyboard and Mouse](USBKeyBoardMouse.md)
   - With two USB-A connectors, all 96Boards can be equiped with a full sized keyboard and mouse
- Full size HDMI Cable
   - All 96Boards are equiped with a full sized HDMI connector
- Monitor
   - HDMI capable monitor is recommended
- Jumpers
   - J15 Header on the HiKey comes with two pin-jumpers

**Optional**
- MicroSD card with adapter
   - For quick and easy switching between operating systems and extra storage
- [Mezzanine Products](../../../MezzanineProducts/README.md)
   - These devices allow you to expand your experience with any 96Boards by adding peripherals and enhancing onboard components
- USB to MicroUSB cable
   - This is needed for serial console interface and fastboot/adb commands
- USB to ethernet adapter and ethernet cable
   - For connecting to a network without using WiFi

***

# Out of the Box

The following subsections should describe how to get started with the HiKey using the release build shipped with the boards. The HiKey board is ready to use “out of the box” with a preinstalled version of the Debian Linux distribution.

## Updating to a new release or change your operating system

If you are already familiar with the HiKey board and would like to change out the stock operating system please proceed to one of the following pages:

- [**Downloads page**](../Downloads/README.md): This page lists all Linaro and 3rd party operating systems available for HiKey
- [**Installation page**](../Installation/README.md): If you already have the images you need, this page has information on how to install the different operating systems onto your HiKey board
- [**Board Recovery**](../Installation/BoardRecovery.md)
   - If at any time your board is having unexplainable issues, it is suggested to attempt a board recovery. These instructions will guide you through a succesfull board recovery.
- [**Troubleshooting**](../Troubleshooting/README.md)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

## Update your system

When keeping the stock image, it is recommended to update your system before adding any new software, you should perform the following commands to make sure everything is up to date:

```
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get dist-upgrade -u
```

Once system has been updated, the following command may be executed to install new packages:

```
sudo apt-get install [package name]
```

You may also search for available packages:

```
sudo apt-cache search [pattern]
```

## Features

|     |     |
|:----|:----|
| SoC |Kirin 620   |
| CPU |ARM® CortexTM-A53 Octa-core 64-bit up to 1.2GHz (ARM v8 instruction set)|
| GPU |ARM Mali 450-MP4, supporting 3D graphics processing, OpenGL ES 1.1/2.0, OpenVG 1.1, 2000Mega@500 MHz, 110M triangle@500 MHz, and 32G flops@500MHz |
| RAM | 1GB LPDDR3 SDRAM @ 800MHz  |
| PMU | HI6553V100|
| Storage |	8GB eMMC on board storage MicroSD card slot  |
| Ethernet Port | USB2.0 expansion |
| Wireless | Wi-Fi 802.11 b/g/n 2.4GHz Dual-mode bluetooth and bluetooth low energy  |
| USB | 2 x USB2.0 Host 1 x USB 2.0 OTG  |
| Display | 1 x HDMI 1.4 (Type A - full) 1 x MIPI-DSI HDMI output up to FHD 1080P|
| Video | 1080p@30 fps HD video encoding, supporting 1080p@30 fps HD camera 1080p@30 fps HD video decoding Supports H.264, SVC, MPEG1/2/4, H.263, VC-1, WMV9, DivX, RV8/9/10, AVS, VP8  |
| Audio | HDMI output|
| Camera | One 4-lane MIPI camera serial interface(CSI), one 2-lane MIPI CSI|
| Expansion Interface |40 pin low speed expansion connector: +1.8V, +5V, SYS_DCIN, GND, UART, I2C, SPI, PCM, PWM,GPIO x12 60 pin high speed expansion connector:   SDIO, MIPI_DSI, MIPI_CSI  |
| LED |	1 x WiFi activity LED（Yellow） 1 x BT  activity LED (Blue) 4 x User LEDs (Green)|
| Button  |Power Button ： Button Power on/off & Reset the system|
| Power Source | 8V~18V@3A, Plug specification is inner diameter 1.7mm and outer diameter 4.8mm|
| OS Support |	Android 4.2/Linux |
| Size |	85mm x 55mm  |

**IMPORTANT NOTES**

- HDMI EDID display data is used to determine the best display resolution. On monitors and TVs that support 1080p (or 1200p) this resolution will be selected. If 1080p is not supported the next available resolution reported by EDID will be used. This selected mode will work with **MOST but not all** monitors/TVs. 
- There are limitations on the usage of the USB ports on the HiKey board.

## Monitor

A standard monitor or TV supporting at least 640x480 resolution is required. Interlaced operation is not currently supported. The maximum resolutions currently supported are 1920x1080p or 1920x1200p.

### Wireless Network

The HiKey board includes built in [2.4GHz IEEE802.11 b/g/n WiFi networking](http://www.ti.com/product/WL1835MOD). The board does not support the 5GHz band. To use the wireless LAN interface for the first time (or to switch wireless networks) you should click on the wireless LAN icon on the bottom right of the desktop display. The yellow LED between the microUSB and the Type A USB on the front board edge indicates wireless network activity.

You can configure the network from UI, or manually from console:

```
$ sudo nmtui
```

Select 'Activate a connection', Choose your WiFi access point (SSID) and fill the relevant information (password, etc...)

You can check network status by issuing this command.

```
$ sudo nmcli dev wifi
```

## Wired Network

You can connect to a wired network by using a USB Ethernet adapter. Supported adapters should automatically work when the adapter is installed.

## Bluetooth

The HiKey board includes built-in Bluetooth 4.0 LE support.

To setup a Bluetooth device open the Bluetooth Manager from the Preferences menu. If a “Bluetooth Turned Off” popup appears then select “Enable Bluetooth”. Click on "Search" to search for devices. Try with your bluetooth audio and bluetooth keyboard/mouse. If you make the device trusted then this should operate over a reboot of the board.

The blue LED between the microUSB and the Type A USB on the front board edge indicates bluetooth activity.

## Audio Device

Bluetooth audio devices are supported on HiKey. Follow normal procedures of connecting a bluetooth device to connect to your board.

**NOTE:** HDMI audio is not supported in this release.

Once Bluetooth sound sink is connected, you can open the LXMusic player from the Sound & Video menu. Create a playlist from your music files. Supported audio formats are .mp3 and .ogg. You should now be able to play from the LXMusic player. 

**NOTE:** LXmusic uses xmms2 as the player backend, you may need to install xmms2 and related plugins if they are not installed, otherwise music may cannot be played.

```
$ sudo apt-get install xmms2 xmms2-plugin-*
```

## File System

HiKey comes with two eMMC size: 4GB and 8GB.

## Logging in

The default user name is "linaro" and the default password for user linaro is also "linaro"

## Clock

The HiKey board does not support a battery powered RTC. System time will be obtained from the network if available. If you are not connecting to a network you will need to manually set the date on each power up or use fake-hwclock:
```
$ sudo apt-get install fake-hwclock
```

## USB

A utility is provided in /home/linaro/bin to change the configuration of the host (Type A and Expansion) and OTG USB ports. By default these ports operate in low/full speed modes (1.5/12 Mbits/s) to support mouse/keyboard devices. Other USB devices such as network or storage dongles/sticks will be limited to full speed mode. Using the usb_speed utility it is possible to support high speed devices (480 Mbits/s) as long as they are not mixed with full/low speed devices.

For information on using the utility do the following:
```
$ sudo usb_speed -h
```

## System and User LEDs

Each board led has a directory in /sys/class/leds. By default the LEDs use the following triggers:

LED | Trigger
--- | -------
wifi_active | phy0tx (WiFi Tx)
bt_active | hci0tx (Bluetooth Tx)
user_led1 | heartbeat
user_led2 | mmc0 (disk access, eMMC)
user_led3 | mmc1 (disk access, microSD card)
user_led4 | CPU core 0 active(not used)

To change a user LED you can do the following as a root user:
```
# echo heartbeat > /sys/class/leds/<led_dir>/trigger      make a LED flash
# cat /sys/class/leds/<led_dir>/trigger                   show triggers
# echo none > /sys/class/leds/<led_dir>/trigger           remove triggers    
# echo 1 > /sys/class/leds/<led_dir>/brightness           turn LED on
# echo 0 > /sys/class/leds/<led_dir>/brightness           turn LED off
```
