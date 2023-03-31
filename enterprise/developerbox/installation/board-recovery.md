---
title: Developerbox Board Recovery
permalink: /documentation/enterprise/developerbox/installation/board-recovery.md.html
---
# Table of Contents

   * [Serial flasher update](#serial-flasher-update)
      * [prepare USB flash drive](#prepare-usb-flash-drive)
      * [run linux for updating serial flasher](#run-linux-for-updating-serial-flasher)
      * [update serial flasher](#update-serial-flasher)
      * [run serial flasher](#run-serial-flasher)
   * [System firmware recovery](#system-firmware-recovery)
      * [Update using serial flasher](#update-using-serial-flasher)
      * [Resetting the NVRAM](#resetting-the-nvram)
   * [Low-level (CM3) firmware recovery](#low-level-cm3-firmware-recovery)
      * [Update using serial flasher](#update-using-serial-flasher-1)
      * [JTAG recovery](#jtag-recovery)

<!-- Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc) -->

***

# Serial flasher update

This section is for the people who do not have UART mezzanine.
Updating the serial flasher, you can use serial flasher without a UART mezzanine.

Here's how to update the serial flasher which uses the micro-B USB port on DeveloperBox as an UART port.

## prepare USB flash drive

Download [flash-update.tar.gz](flash-update.tar.gz)

Extract flash-update.tar.gz and write the flash-update.iso to a USB flash drive.

~~~sh
$ sudo dd if=/path/to/flash-update.iso of=/dev/sdX/
$ sync
~~~

## run linux for updating serial flasher

Plug the USB flash drive to your Developerbox and power it on.
When the following message is displayed, press ESCAPE for boot option.

~~~
Tianocore/EDK2 firmware version 1024
Press ESCAPE for boot option ...
~~~

Select Boot Manager.
From the Boot Manager Menu, select the item corresponding to the USB flash drive in which flash-update.iso is written.

Select "flash-update" entry on Grub.

~~~
F/W Upgrade Run - flash-update
~~~

Then, Linux is going to boot.

## update serial flasher

After booting Linux, run the following command.

~~~
~ # flash-update
~~~

When you see the following and come back to the command prompt, the update is complete.

~~~
Writing F/W @70000 ...
~~~

## run serial flasher

See [Update using serial flasher](#update-using-serial-flasher) section.

***

# System firmware recovery

This section outlines steps needed to recover your Developerbox from a
bricked software state. These instructions are suggested to those who
are experiences boot issues due to a corruption of the NOR FLASH.

In all other cases is it **strongly** recommended to use [Capsule Update](README.md) instead.

## Update using serial flasher

The serial flasher can be enabled in two ways.

1. Turn the board off, set DSW2-7 to on and turn the board
   on again. The flasher program will be started automatically;
   don't forget to turn the switch off again after flashing.
2. Send a keypress to LS-UART0 shortly after turning on the
   power to the board and enter `update firmware` at the
   resulting command prompt. In some systems the timeout to
   enter the initial keypress is *very* short meaning it is best to
   send repeated keypresses commencing before you turn the board on
   (a.k.a. keyboard auto-repeat).

Note: *The pre-installed CM3 firmware supports both flashing methods but, currently, the [upstream SCP firmware](../build/README.md#build-scp-firmware-from-source) only supports the DSW2-7 method.*

When the serial flasher is running correctly is will show the following
boot messages shown via LS-UART0:

~~~
/*------------------------------------------*/
/*  SC2A11 "SynQuacer" series Flash writer  */
/*                                          */
/*  Version: cd254ac                        */
/*  Build: 12/15/17 11:25:45                */
/*------------------------------------------*/

Command Input >
~~~

Once the flasher tool is running we are ready flash the UEFI image:

~~~
flash rawwrite 180000 280000
>> Send SPI_NOR_IMAGE.fd-RELEASE via XMODEM (Control-A S in minicom) <<
~~~

## Resetting the NVRAM

Occasionally it is necessary to reset the platform's "NVRAM", a special
section on the NOR flash which holds the UEFI variable store.

The simplest way to reset the NVRAM is to set DSW3-1 to on and reboot
the system. Be sure to remember to set the switch back to the default
(off) position, before the next reboot!

Alternatively it is possible to wipe the varstore when updating the UEFI
image using the serial flasher, try (note the change if size, from 28000
to 2b0000, compared to a normal flash write operation):

~~~
flash rawwrite 180000 2b0000
>> Send SPI_NOR_IMAGE.fd via XMODEM (Control-A S in minicom) <<
~~~

***

# Low-level (CM3) firmware recovery

Very occasionally it may be required to update the low-level board
firmware, sometimes called the CM3 firmware.

## Update using serial flasher

Be aware that THE SERIAL FLASHER HAS THE CAPABILITY TO SOFT-BRICK YOUR
BOARD. In particular the implementation of the XMODEM protocol is easily
confused by extra keystrokes and runs *after* the FLASH has been erased.
For example sending *Control-A Control-S* rather than *Control-A S* from
minicom risks soft-bricking the board. It is possible to recovery a
soft-bricked board using a JTAG programmer (see below).

The serial flasher can be enabled in two ways.

1. Turn the board off, set DSW2-7 to on and turn the board
   on again. The flasher program will be started automatically;
   don't forget to turn the switch off again after flashing.
2. Send a keypress to LS-UART0 shortly after turning on the
   power to the board and enter `update firmware` at the
   resulting command prompt. In some systems the timeout to
   enter the initial keypress is *very* short meaning it is best to
   send repeated keypresses commencing before you turn the board on
   (a.k.a. keyboard auto-repeat).

Note: *The pre-installed CM3 firmware supports both flashing methods but, currently, the [upstream SCP firmware](../build/README.md#build-scp-firmware-from-source) only supports the DSW2-7 method.*

When the serial flasher is running correctly is will show the following
boot messages:

~~~
/*------------------------------------------*/
/*  SC2A11 "SynQuacer" series Flash writer  */
/*                                          */
/*  Version: cd254ac                        */
/*  Build: 12/15/17 11:25:45                */
/*------------------------------------------*/

Command Input >
~~~

Once the flasher tool is running we are ready flash the CM3 firmware image:

~~~
flash write cm3
>> Send new CM3 firmware via XMODEM <<
~~~

The currently recommended firmware is available seperately:
`ramfw_20171102.bin` (sha1sum: `6dad40f7d055346a7cd095ed432c677bf2509c8e`).

### Example session log

Full log of a low-level firmware upgrade is shown below. The serial
flasher was entered using the keystroke method:

~~~
[SYSTEM] Entered SynQuacer Firme
[SYSTEM] chip version 2.
[SYSTEM] Firmware mode Master
[SYSTEM] Platform: Socionext ARM Server
[SYSTEM] Configuration: 5
[SYSTEM] v1.15.1
[SYSTEM] Build: 09/22/17 19:42:53
[SYSTEM] git revision f4de521
[SYSTEM] Initializing power domain
[PowerDomain] Socionext-PPU initialize .
[PowerDomain] Socionext-PPU initialize end .
[PowerDomain] PowerDomain All-ON start.
[PowerDomain] PowerDomain All-ON finished .
[SYSTEM] Finished initializing power domain
[SYSTEM] Initializing NIC SECURE
[SYSTEM] Finished initializing NIC SECURE
[SYSTEM] Starting irq enabele
[SYSTEM] Finished starting irq enabele
[SYSTEM] Initializing maintenance network
[COMLIB] Initializing NETSEC hardware
[COMLIB] NETSEC found. Hardware version: 00050041
[COMLIB] Finished initializing NETSEC hardware
[COMLIB] Microcode version: 100005D5
[COMLIB] Initializing external Ethernet PHY device
[COMLIB] Finished initializing external Ethernet PHY device
[SYSTEM] Finished initializing maintenance network
To enter debug mode, please press any key.

/*------------------------------------------*/
/* uart input mode (state : P_IDLE)         */
/*------------------------------------------*/

Command Input >update firmware
update firmware

/*------------------------------------------*/
/*  SC2A11 "SynQuacer" series Flash writer  */
/*------------------------------------------*/

Command Input >flash write p-master-cm3
Command'flash'Start...
HsspiSoftwareReset()...RDSR=40
[INFO] ManufacturerID=C2 DeviceID=25 RDSR=00
[INFO] DeviceName=MX66U1G45G (256bytes per programmable page)
Showing status registers. RDSR = 0x00000040, Enter 4-byte mode
HsspiSectorErase. Please wait...
 End.SectorErase(7/7)...
Writing data at offset 0x00000000, max_size 0x00080000
Waiting to receive the data in XMODEM protocol (128bytes check-sum)...

>>>>> Send firmware via XMODEM when non-ASCII characters appear <<<<<

[SUCCESS] 0x0001ec80 bytes written
Exit 4-byte mode
Showing status registers. RDSR = 0x00000042, Return Val = '0'
Command'flash'End...
Command Input >
~~~

## JTAG recovery

The JTAG recovery process allows the serial flasher to be run from SRAM,
thus allowing the NOR to be updated.

To recovery the board you will need a suitable JTAG programmer. The
SC2A11 is interfaced using 1.8v TTL logic. Your programmer must support
1.8v signalling and, if the programmer supports powering the target
device, this feature **must** be disabled before you connect the
programmer to the board (many programmers provide a 3.3v power supply
and applying this voltage could damage the board).

These instructions assume you have a [Bus Blaster](https://www.seeedstudio.com/Bus-Blaster-v3-p-1415.html) running
using a [KT-Link compatible buffer](https://github.com/bharrisau/busblaster) and with the **power
supply jumper removed** (as discussed above). In the instructions below,
replace `interface/ftdi/dp_busblaster_kt-link.cfg` with whatever is
appropriate for your programmer.

Note: *If you have purchased a Bus Blaster device to perform the
recovery, it will not have been shipped with a KT-Link compatible buffer
(they are usually shipped with selftest firmware). To update the buffer,
try `git clone https://github.com/bharrisau/busblaster` followed by
`openocd -f board/dp_busblaster_v3.cfg -c "adapter_khz 1000; init; svf
synthesis/system.svf; shutdown"`*

Firstly we must create a configuration file to describe the board:

~~~
cat > sc2a11.cfg <<EOF
###########################################
set _CHIPNAME sc2a11
set _TARGETNAME \$_CHIPNAME.m3
adapter_khz 1000

if { [info exists ENDIAN] } {
   set _ENDIAN \$ENDIAN
} else {
   set _ENDIAN little
}

set _M3_JTAG_TAPID 0x6ba00477

jtag newtap auto0 tap -irlen 4 -expected-id 0x6ba00477

target create \$_TARGETNAME cortex_m -endian \$_ENDIAN -chain-position auto0.tap
EOF
~~~

If your board was bricked by a failed attempt to update the CM3 firmware
then the flasher tool is still present in NOR but there is no bootloader
to launch it. Try:

~~~
openocd \
        -f interface/ftdi/dp_busblaster_kt-link.cfg \
        -f sc2a11.cfg \
        -c "init" \
        -c "reset halt" \
        -c "mwb 0x48100000 3" \
        -c "resume 0x8fe0050" \
        -c "exit"
~~~

Alternatively, if your NOR has been totally erased (this is unlikely,
but certainly possible) then you may have to load a flasher tool into
RAM:

~~~
openocd \
        -f interface/ftdi/dp_busblaster_kt-link.cfg \
        -f sc2a11.cfg \
        -c "init" \
        -c "reset halt" \
        -c "mwb 0x48100000 3" \
        -c "load_image flash-writer-maverick-evb-4bytemode.axf-cd59a5d" \
        -c "resume 0x800051" \
        -c "exit"
~~~

Whichever approach is used, at this point the SC2A11 Flash writer should
be running on the CM3 console and NOR can be updated:

~~~
flash write s-mir-cm3
>> Send new option ROM via XMODEM <<
flash write p-master-cm3
>> Send new CM3 firmware via XMODEM <<
~~~

---

Back to [Download and Installation page](../installation/)
