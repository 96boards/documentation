---
title: OpenOCD JTAG Guide for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Guides/JTAG/
redirect_from: /documentation/ConsumerEdition/HiKey/Guides/JTAG/README.md/
---
# OpenOCD JTAG and HiKey

Hikey provides an unpopulated JTAG connector on its underside. It is relatively easy to hand solder on a proper connector and to use inexpensive JTAG interfaces to communicate with the board.

Currently the open-source JTAG debugging solutions are fairly immature for 64-bit ARM platforms. In general the Hikey should be considered a tool to help develop OpenOCD on rather than considering OpenOCD a tool to help you develop on a Hikey!

This page documents the current status, and provide instructions on to to get setup and working.

## Soldering on the connector
The first step is to solder on the JTAG connector. The unpopulated header is at J10 on the underside of the circuit board. The connector that you need to buy is a "FTSH-105-01-L-DV". It can be purchased from Farnell here (note the image is for a larger connector).

http://uk.farnell.com/samtec/ftsh-105-01-l-dv/header-1-27mm-smd-10way/dp/1667759﻿

Once the connector is soldered on it should look something like this

![](https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey/Configuration/JTAG/Screenshot%20(180).png?raw=true)

## JTAG interfaces

OpenOCD supports many different JTAG interface. The list of devices known to work with the HiKey board includes:

 * [Bus Blaster v3 from Dangerous Prototypes](http://dangerousprototypes.com/docs/Bus_Blaster). Set `INTERFACE=interface/ftdi/dp_busblaster_kt-link.cfg` for this adapter. Before connecting the BBv3 to the HiKey ensure the interface is not configured to provide power to the target (JP4, the target power select jumper, **must** be disconnected) otherwise the HiKey could be damaged. The BBv3 buffer logic must be programmed with SVF from https://github.com/bharrisau/busblaster .
 * [Flyswatter2 from Tin Can Tools](http://www.tincantools.com/JTAG/Flyswatter2.html). Set `INTERFACE=interface/ftdi/flyswatter2.cfg` for this adapter.
 * [J-Link from Segger](https://www.segger.com/jlink-debug-probes.html). Set `INTERFACE=interface/jlink.cfg`.

Most JTAG interfaces provide a standard ARM 20 pin socket (2x10 2.54mm) meaning an adapter board is required to convert from this to the SWD (2x5 1.27mm). This are available from a variety of sources including:

 * [ARM-JTAG-20-10 from Olimax](https://www.olimex.com/Products/ARM/JTAG/ARM-JTAG-20-10/). This board includes the 10-pin SWD cable and has a female 20 pin IDC connector allowing it to connect directly to most JTAG interfaces without any additional cabling.
 * [JTAG to SWD Cable Adapter Board](http://www.adafruit.com/products/2094) and [150mm 2x5 SWD cable](https://www.adafruit.com/product/1675) from Adafruit Industries. This board has a male IDC connector meaning an additional 20 pin IDC cable is required to connect to most JTAG interfaces.

Once this is all connected it should look something like thisFT2232H

![](https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey/Configuration/JTAG/Screenshot%20(181).png?raw=true)

## OpenOCD source code
The armv8 code isn't currently merged to mainline, the latest code I've found is on the following gerrit http://openocd.zylin.com/#/c/2523/.

A GIT repo which is based off this gerrit which also includes a includes a hi6220 configuration file can be cloned here

    git clone ssh://git@git.linaro.org:/people/peter.griffin/openocd-code
    cd openocd-code
    git checkout armv8
    git submodule update --init --recursive
    autoreconf -iv

## Compiling OpenOCD

Install any pre-requisite libraries (e.g. FTDI libs if your JTAG is FTDI based)

    cd openocd-code
    export PKG_CONFIG_PATH=/usr/lib/x86_64-linux-gnu/pkgconfig/  # Needed for Debian derived distros
    ./configure --enable-ftdi
    make
    make install

## Running OpenOCD

Firstly ensure everything is connected like the photo above, and power on the board. Then issue the following command

    src/openocd -f ./tcl/$INTERFACE -f ./tcl/target/hi6220.cfg

If all goes well you should see trace like the following: -

    Open On-Chip Debugger 0.9.0-dev-00241-gd356c86-dirty (2015-07-10-08:20)
    Licensed under GNU GPL v2
    For bug reports, read
	    http://openocd.sourceforge.net/doc/doxygen/bugs.html
    adapter speed: 10 kHz
    Error: session transport was not selected. Use 'transport select <transport>'
    Info : session transport was not selected, defaulting to JTAG
    jtag_ntrst_delay: 100
    trst_and_srst combined srst_gates_jtag trst_push_pull srst_open_drain connect_deassert_srst
    hi6220.cpu
    Info : clock speed 10 kHz
    Info : JTAG tap: hi6220.dap tap/device found: 0x5ba00477 (mfg: 0x23b, part: 0xba00, ver: 0x5)
    Info : hi6220.cpu: hardware has 6 breakpoints, 4 watchpoints

If you see trace like this:

    Open On-Chip Debugger 0.9.0-dev-00241-gd356c86-dirty (2015-07-10-08:20)
    Licensed under GNU GPL v2
    For bug reports, read
	    http://openocd.sourceforge.net/doc/doxygen/bugs.html
    adapter speed: 10 kHz
    Error: session transport was not selected. Use 'transport select <transport>'
    Info : session transport was not selected, defaulting to JTAG
    jtag_ntrst_delay: 100
    trst_and_srst combined srst_gates_jtag trst_push_pull srst_open_drain connect_deassert_srst
    hi6220.cpu
    Info : clock speed 10 kHz
    Error: JTAG scan chain interrogation failed: all ones
    Error: Check JTAG interface, timings, target power, etc.
    Error: Trying to use configured scan chain anyway...
    Error: hi6220.dap: IR capture error; saw 0x0f not 0x01
    Warn : Bypassing JTAG setup events due to errors
    Warn : Invalid ACK 0x7 in JTAG-DP transaction

... then check the following:
* Soldering of the JTAG connector
* The cables are plugged in securely
* The board is correctly powered.
* Everything is connected like in the photo above

## Using OpenOCD Telnet interface
Once openocd has connected to the target you can connect via the telnet interface.

    telnet localhost 4444
    Trying 127.0.0.1...
    Connected to localhost.
    Escape character is '^]'.
    Open On-Chip Debugger
    > halt
    number of cache level 2
    cache l2 present :not supported
    hi6220.cpu cluster 0 core 0 multi core
    target state: halted
    target halted in ARM64 state due to debug-request, current mode: EL2H
    cpsr: 0x800003c9 pc: 0x3ef7e908
    MMU: disabled, D-Cache: disabled, I-Cache: disabled

## What works?

### Dumping the processor registers

This command was issued whilst sat at the u-boot prompt.

    > reg
    ===== arm v8 registers
    (0) r0 (/64): 0x0000000000000090 (dirty)
    (1) r1 (/64): 0x00000000F8015000
    (2) r2 (/64): 0x000000003EF9C000
    (3) r3 (/64): 0x0000000000000018
    (4) r4 (/64): 0x000000003EFA3B88
    (5) r5 (/64): 0x0000000000000100
    (6) r6 (/64): 0x0000000000000000
    (7) r7 (/64): 0x0000000000000001
    (8) r8 (/64): 0x000000003EF9BC50
    (9) r9 (/64): 0x0000000009F61000
    (10) r10 (/64): 0x000000003E75C468
    (11) r11 (/64): 0x000000003EF8F000
    (12) r12 (/64): 0x000000000000000F
    (13) r13 (/64): 0x0000000000000000
    (14) r14 (/64): 0x0000000000000000
    (15) r15 (/64): 0x0000000000000000
    (16) r16 (/64): 0x0000000000000000
    (17) r17 (/64): 0x0000000000000000
    (18) r18 (/64): 0x000000003E75EE38
    (19) r19 (/64): 0x000000003EFBACF0
    (20) r20 (/64): 0x000000003EFBACF0
    (21) r21 (/64): 0x0000000000000009
    (22) r22 (/64): 0x000000003EF99799
    (23) r23 (/64): 0x000000003EF90C00
    (24) r24 (/64): 0x000000003EFBA000
    (25) r25 (/64): 0x0000000000000000
    (26) r26 (/64): 0x0000000000000001
    (27) r27 (/64): 0x0000000000000000
    (28) r28 (/64): 0x000000003EF8E000
    (29) r29 (/64): 0x000000003E75EBE0
    (30) r30 (/64): 0x000000003EF77798
    (31) sp (/64): 0x000000003E75EBE0
    (32) pc (/64): 0x000000003EF7E908
    (33) xPSR (/64): 0x00000000800003C9

### Setting a breakpoint

_Currently it is not possible to resume the target once Linux has booted (although it can be halted and examined). At present preakpoints are only effective for bootloader development._

    > bp 0x35000000 4 hw
    breakpoint set at 0x        35000000
    > resume

and in u-boot force the processor to jump to this address (which is the start of u-boot)

    INFO:    BL3-1: Preparing for EL3 exit to normal world
    INFO:    BL3-1: Next image address = 0x35000000
    INFO:    BL3-1: Next image spsr = 0x3c9
    U-Boot 2015.04-00007-g1b3d379-dirty (May 27 2015 - 10:18:16) hikey_aemv8a
    DRAM:  1008 MiB
    MMC:   sd_card_detect: SD card present
    HiKey DWMMC: 0, HiKey DWMMC: 1
    In:    serial
    Out:   serial
    Err:   serial
    Net:   Net Initialization Skipped
    No ethernet found.
    Hit any key to stop autoboot:  0
    # go 0x35000000
    ## Starting application at 0x35000000 ...

you can see in OpenOCD telnet we hit the breakpoint

    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x35000000
    MMU: disabled, D-Cache: disabled, I-Cache: disabled

now remove the breakpoint so we can try single stepping

    rbp 0x35000000

### Single stepping

_Currently it is not possible to resume the target once Linux has booted (although it can be halted and examined). At present single stepping is only effective for bootloader development._

    > step
    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x35000028
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    timeout waiting for target halt
    in procedure 'step'
    > step
    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x3500002c
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    timeout waiting for target halt
    in procedure 'step'
    > step
    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x35000030
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    timeout waiting for target halt
    in procedure 'step'
    <snip>
    > step
    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x35000074
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    timeout waiting for target halt
    in procedure 'step'
    > step
    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x35000084
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    timeout waiting for target halt
    in procedure 'step'
    > step
    target state: halted
    target halted in ARM64 state due to breakpoint, current mode: EL2H
    cpsr: 0x600003c9 pc: 0x35000090
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    timeout waiting for target halt
    in procedure 'step'

We can validate the last few single steps, with a disassembly of the u-boot binary. You can see that that to validate what happened

    0000000035000028 <reset>:
        35000028:   10003ec0        adr     x0, 35000800 <vectors>
        3500002c:   d5384241        mrs     x1, currentel
        35000030:   f100303f        cmp     x1, #0xc
        35000034:   540000a0        b.eq    35000048 <reset+0x20>
        35000038:   f100203f        cmp     x1, #0x8
        3500003c:   54000160        b.eq    35000068 <reset+0x40>
        35000040:   f100103f        cmp     x1, #0x4
        35000044:   540001a0        b.eq    35000078 <reset+0x50>
        35000048:   d51ec000        msr     vbar_el3, x0
        3500004c:   d53e1100        mrs     x0, scr_el3
        35000050:   b2400c00        orr     x0, x0, #0xf
        35000054:   d51e1100        msr     scr_el3, x0
        35000058:   d51e115f        msr     cptr_el3, xzr
        3500005c:   580005a0        ldr     x0, 35000110 <c_runtime_cpu_setup+0x3c>
        35000060:   d51be000        msr     cntfrq_el0, x0
        35000064:   14000008        b       35000084 <reset+0x5c>
        35000068:   d51cc000        msr     vbar_el2, x0
        3500006c:   d2867fe0        mov     x0, #0x33ff                     // #13311
        35000070:   d51c1140        msr     cptr_el2, x0
        35000074:   14000004        b       35000084 <reset+0x5c>
        35000078:   d518c000        msr     vbar_el1, x0
        3500007c:   d2a00600        mov     x0, #0x300000                   // #3145728
        35000080:   d5181040        msr     cpacr_el1, x0
        35000084:   94000003        bl      35000090 <apply_core_errata>
        35000088:   9400000b        bl      350000b4 <lowlevel_init>
        3500008c:   940004d7        bl      350013e8 <_main>

    0000000035000090 <apply_core_errata>:
        35000090:   aa1e03fd        mov     x29, x30
        35000094:   d5380000        mrs     x0, midr_el1

### Writing to memory

    > halt
    number of cache level 2
    cache l2 present :not supported
    hi6220.cpu cluster 0 core 0 multi core
    target state: halted
    target halted in ARM64 state due to debug-request, current mode: EL2H
    cpsr: 0x800003c9 pc: 0x3ef7e908
    MMU: disabled, D-Cache: disabled, I-Cache: disabled
    > mww 0x36000000 0xdeadbeef
    > resume

and then validate with u-boot

    # md 0x36000000
    36000000: deadbeef 555555d5 5c355555 5575555d    .....UUUUU5\]UuU

### Reading from memory

target state: halted
target halted in ARM64 state due to debug-request, current mode: EL2H
cpsr: 0x800003c9 pc: 0x3ef7e908
MMU: disabled, D-Cache: disabled, I-Cache: disabled

    > mdw 0x35000000 10
    0x35000000: 1400000a d503201f 35000000 00000000 00042938 00000000 00042938 00000000
    0x35000020: 0009e030 00000000
    > resume

and then validate with u-boot

    # md.l 0x35000000 10
    35000000: 1400000a d503201f 35000000 00000000    ..... .....5....
    35000010: 00042938 00000000 00042938 00000000    8)......8)......
    35000020: 0009e030 00000000 10003ec0 d5384241    0........>..AB8.
    35000030: f100303f 540000a0 f100203f 54000160    ?0.....T? ..`..T


### Debugging U-Boot with GDB

If U-Boot is sat at the prompt, then it has been relocated from its
statically linked address 0x35000000. On my system it gets relocated to
0x3ef47000.

    (gdb) aarch64-linux-gnu-gdb
    (gdb) add-symbol-file build-hikey/u-boot 0x3ef47000
    (gdb) hbreak do_version
    Hardware assisted breakpoint 1 at 0x3ef4cc80: file ../common/cmd_version.c, line 19.
    (gdb) c
    Continuing.

    <uboot> => version

    Breakpoint 1, do_version (cmdtp=0x3ef8c0c0, flag=0, argc=1, argv=0x3e746850) at ../common/cmd_version.c:19
    19	{
    (gdb) bt
    #0  do_version (cmdtp=0x3ef8c0c0, flag=0, argc=1, argv=0x3e746850) at ../common/cmd_version.c:19
    #1  0x000000003ef604a8 in cmd_call (argv=0x3e746850, argc=1,

## What isn't working

Probably lots of things - add issues here when you find them :)

Better still debug and fix it!

Sometimes I hit the following GDB assertion when doing a backtrace in U-Boot
* /cbuild/slaves/oorts/crosstool-ng/builds/aarch64-linux-gnu-linux/.build/src/gdb-linaro-7.6.1-2013.10/gdb/regcache.c:178: internal-error: register_size: Assertion `regnum >= 0 && regnum < (gdbarch_num_regs (gdbarch) + gdbarch_num_pseudo_regs (gdbarch))' failed.
