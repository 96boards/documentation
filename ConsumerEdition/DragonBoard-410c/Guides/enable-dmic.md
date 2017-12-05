---
title: Instructions for Enabling DMIC support in Dragonboard410c
permalink: /documentation/ConsumerEdition/DragonBoard-410c/Guides/enable-dmic.md.html
---

# Instructions for Enabling DMIC support in Dragonboard410c

This document provides instructions for enabling DMIC support in Dragonboard410c.

# Table of Contents

- [1) DMIC in Dragonboard410c](#1-dmic-in-dragonboard410c)
- [2) Hardware Required](#2-hardware-required)
- [3) Modifying Device Tree](#3-modifying-device-tree)
- [4) Building Device Tree](#4-building-device-tree)
- [5) Flashing boot and rootfs image](#5-flashing-boot-and-rootfs-image)
- [6) Testing DMIC](#6-testing-dmic)

 ***

# 1) DMIC (Digital MIC) in Dragonboard410c

Dragonboard410c has one DMIC port which can be used to connect external
Digital Microphone (two can be connected as a multiplex). APQ8016 provides
the CLK and DATA signals while PM8916 provides the MIC_BIAS. On the
Dragonboard410c DATA and CLK signals are exposed on the LS expansion header
 (J8) while MIC_BIAS is available at the Analog Expansion header (J7). Also,
CLK and DATA signals are multiplexed to the UART0 TxD and RxD signals at Pin 4
and 6 on J8.

# 2) Hardware Required

* Dragonboard410c
* Arrow Audio Mezzanine board

# 3) Modifying Device Tree

Since, UART signals are multiplexed to DMIC CLK and DATA signals on pads, we
need to disable UART0 and enable DMIC in order to use it.

Apply the following diff to `arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi`

```
diff --git a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
index 5d0d5a3..061f5f3 100644
--- a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
+++ b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
@@ -42,7 +42,7 @@
 
                serial@78af000 {
                        label = "LS-UART0";
-                       status = "okay";
+                       status = "disabled";
                        pinctrl-names = "default", "sleep";
                        pinctrl-0 = <&blsp1_uart1_default>;
                        pinctrl-1 = <&blsp1_uart1_sleep>;
@@ -281,13 +281,17 @@
                         reg-names = "mic-iomux", "spkr-iomux";
 
                         status = "okay";
-                        pinctrl-0 = <&cdc_pdm_lines_act &ext_sec_tlmm_lines_act &ext_mclk_tlmm_lines_act>;
-                        pinctrl-1 = <&cdc_pdm_lines_sus &ext_sec_tlmm_lines_sus &ext_mclk_tlmm_lines_sus>;
+                        pinctrl-0 = <&cdc_pdm_lines_act &ext_sec_tlmm_lines_act &ext_mclk_tlmm_lines_act &cdc_dmic_lines_act>;
+                        pinctrl-1 = <&cdc_pdm_lines_sus &ext_sec_tlmm_lines_sus &ext_mclk_tlmm_lines_sus &cdc_dmic_lines_sus>;
                         pinctrl-names = "default", "sleep";
                         qcom,model = "DB410c";
                         qcom,audio-routing =
                                 "AMIC2", "MIC BIAS Internal2",
-                                "AMIC3", "MIC BIAS External1";
+                                "AMIC3", "MIC BIAS External1",
+                                "DMIC1", "MIC BIAS Internal1",
+                                "DMIC1", "Digital Mic1",
+                                "DMIC2", "MIC BIAS Internal1",
+                                "DMIC2", "Digital Mic2";
                        external-dai-link@0 {
                                link-name = "ADV7533";
                                cpu { /* QUAT */
@@ -609,4 +613,4 @@
```
# 4) Building Device Tree

Build the device tree with above mentioned changes.

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path to your GCC cross compiler>/aarch64-linux-gnu-
$ make defconfig distro.config
$ make -j$(nproc) dtbs
```
Now, prepare the boot image.

```shell
$ git clone git://codeaurora.org/quic/kernel/skales
$ ./skales/dtbTool -o dt.img -s 2048 arch/arm64/boot/dts/qcom/
$ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/initrd.img-<KERNELRELEASE>-linaro-lt-qcom
$ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/Image
$ ./skales/mkbootimg --kernel Image \
                   --ramdisk initrd.img.<KERNELRELEASE>-linaro-lt-qcom \
                   --output boot-db410c.img \
                   --dt dt.img \
                   --pagesize 2048 \
                   --base 0x80000000 \
                   --cmdline "root=/dev/disk/by-partlabel/rootfs rw rootwait console=ttyMSM0,115200n8"
```

> Note: Replace < KERNELRELEASE > with latest kernel release version found
[here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/).

# 5) Flashing boot and roofs image

Boot Dragonboard410c into fastboot mode by following the
[instructions](https://www.96boards.org/documentation/ConsumerEdition/DragonBoard-410c/Installation/LinuxFastboot.md.html).

1. Download latest `rootfs` image from
[here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/linaro-*-alip-qcom-snapdragon-arm64-*.img.gz).
2. Flash boot and rootfs images onto Dragonboard410c

```shell
$ sudo fastboot flash boot boot-db410c.img
$ sudo fastboot flash rootfs linaro-<DEBIANRELEASE>-alip-qcom-snapdragon-arm64-<BUILD>.img
```
> Note: Replace < DEBIANRELEASE > and < BUILD > according to the downloaded rootfs image.

# 6) Testing DMIC

> Note: Make sure you have soldered Male headers on the Analog Expansion header
(J7) on Dragonboard410c before connecting the Audio Mezzanine.

* Stack Audio Mezzanine on top of Dragonboard410c
* Boot Dragonboard410c with the above mentioned custom Boot image and pre-built
  RFS image.

For testing the audio capture functionality using DMIC, follow the below
commands on Dragonboard:

First setup mux to use DMIC.

```shell
$ amixer cset iface=MIXER,name='DEC1 MUX' 'DMIC1'
$ amixer cset iface=MIXER,name='CIC1 MUX' 'DMIC'
```
Now, record audio using DMIC present in Audio Mezzanine.

```shell
$ arecord -D plughw:0,2 -r 48000 -f S16_LE /tmp/f-48000.wav
```

After recording audio, mux can be reset using the following command.

```shell
$ amixer cset iface=MIXER,name='DEC1 MUX' 'ZERO'
```
