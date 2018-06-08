---
title: Qualcomm USB flashing tool


permalink: /documentation/consumer/guides/qdl.md.html
---
# Qualcomm USB flashing tool

Qualcomm MSM based devices contain a special mode of operation, called Emergency Download Mode (EDL). In this mode, the device identifies itself as Qualcomm HS-USB 9008 through USB, and can communicate with a PC host.  EDL is implemented by the SoC ROM code (also called PBL). The EDL mode itself implements the Qualcomm Sahara protocol, which accepts an OEM-digitally-signed programmer over USB. The programmer implements the Firehose protocol which allows the host PC to send commands to write into the onboard storage (eMMC, UFS).

As open source tool (for Linux) that implements the Qualcomm Sahara and Firehose protocols has been developed by Linaro, and can be used for program (or unbrick) MSM based devices, such as Dragonboard 410c or Dragonboard 820c.

# Get the Linux flashing tool

    git clone https://git.linaro.org/landing-teams/working/qualcomm/qdl.git

This is provided in source code, and it needs to be compiled locally. It uses libxml, so on Ubuntu/Debian you will need:

    sudo apt-get install libxml2-dev

To compile qdl project, it should be as simple as running make command in the top level folder of the project.

# Make sure that ModemManager is not running

Some Linux distributions come with ModemManager, a tool for configuring Mobile Broadband.
When the dragonboard is connected in USB mode, it will be identified as a Qualcomm modem,
and ModemManager will try to configure the device. This will interfere with the QDL flashing,
so if you have ModemManager running, you need to disable it before connecting your dragonboard.
If you are using a Linux distribution with systemd, ModemManager can be stopped by:

    sudo systemctl stop ModemManager

If you actually need ModemManager, you can start it again after the flashing is complete.

# Flashing the device

In order to flash the device , ensure the following:
* the device is in EDL mode
* you have access to the proper, device specific, digitally-signed ELF programmer
* you have access to the Firehose XML commands to flash the device, and the corresponding blob/firmware

For Dragonboard 410c, please refer to the [Dragonboard 410c recovery guide](../dragonboard410c/installation/board-recovery.md#using-usb-flashing-tools).
For Dragonboard 820c, please refer to the [Dragonboard 820c recovery guide](../dragonboard820c/installation/board-recovery.md#using-usb-flashing-tools).
