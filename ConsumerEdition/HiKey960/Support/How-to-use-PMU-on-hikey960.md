---
title: How to use PMU hardware events of ARM architecture on HiKey960
permalink: /documentation/ConsumerEdition/HiKey960/Support/How-to-use-PMU-on-hikey960.md/
---
This application note describes how to use PMU hardware events of ARM architecture on HiKey960.

Written by: Jumana MP <Jumana.MP@arm.com>

## Source code
1. ```CONFIG_HW_PERF_EVENTS``` must be enabled in the kernel config when you build the kernel.
2. Add dts node for armv8 pmu. Example for v4.4 kernel can be found [here](https://android.googlesource.com/kernel/hikey-linaro/+/2169b8455a332aa287a4eda6b15f7eec9c1873da%5E%21/#F0). You can do similar for other kernel versions.

## Install ```Perf```
For testing, get ```perf``` binary for ARM on the target device.
Perf binary can be obtained from:
https://github.com/ARM-software/workload-automation/tree/master/wlauto/instrumentation/perf/bin

## Usage
Example test would be checking if PMU events get counted on the device.
To make sure that kernel supports generating perf data, run the following on the device as root:
```
echo -1 > /proc/sys/kernel/perf_event_paranoid
echo 0 > /proc/sys/kernel/kptr_restrict
```

Then, run ```perf``` from device at the location where perf is copied to:
```perf stat -a -e r8,r11 sleep 10```
r8 is the PMU event for INSTRUCTION COUNT and r11 is the hardware event for CPU_CYCLES on ARM CPUs.

This should give the event count numbers once perf run finishes.
Expected output gives the counters if the patch is applied correctly, as shown below:

Performance counter stats for 'system wide':
```
  21663586606      r8
  14839358570      r11
```
