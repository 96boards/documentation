# Enabling SPI on Dragonboard 410c with SPIDEV

This tutorial will show how to build and flash a DragonBoard 410c boot image with SPI enabled using SPIDEV.

> Note: LT Debian 16.06 release MUST be used as base (**Step 1**). The 16.06 LT release already includes the SPIDEV kernel module, you will only need to change the device tree file (and boot image).

***

### Step 1: **Flash the 16.06 LT Debian release:**

First make sure you are running the 16.06 LT Debian release. The following folder contains all the necessary files:

- https://builds.96boards.org/releases/dragonboard410c/linaro/debian/16.06/

From the above link, download your desired `rootfs` and `boot` image
- linaro-jessie-{alip or developer}-qcom-snapdragon-arm64-*.img.gz
- boot-linaro-jessie-qcom-snapdragon-arm64-*.img.gz

Fastboot installation instructions (using a Linux host machine) can be found [here](../Installation/LinuxFastboot.md)

A pre-built, flashable boot image is available (skip steps 2-5). Simply replace the boot image downloaded from builds.96boards with the boot-db410c-spi.img [downloaded here](http://people.linaro.org/~ricardo.salveti/boot-db410c-spi.img) and proceed to fastboot installation instruction above. Once you have finished flashing both pre-built `rootfs` and `boot` images, skip to **Step 6** for SPI test commands.

### Step 2: Customize the device tree to export the spidev devices (low and high speed expansion headers):

```shell
$ git clone -n http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
$ cd kernel
$ git checkout -b kernel-16.06 debian-qcom-dragonboard410c-16.06
```

Change the device tree file to include the spidev devices:

```
$ git diff
diff --git a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
index aeed816..f6714a5 100644
--- a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
+++ b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
@@ -477,3 +477,23 @@
 &vidc {
        status = "okay";
 };
+
+/* On Low speed expansion */
+&blsp_spi5 {
+       status = "okay";
+       spidev@0 {
+               compatible = "spidev";
+               spi-max-frequency = <50000000>;
+               reg = <0>;
+       };
+};
+
+/* On High speed expansion */
+&blsp_spi3 {
+       status = "okay";
+       spidev@0 {
+               compatible = "spidev";
+               spi-max-frequency = <50000000>;
+               reg = <0>;
+       };
+};
```

### Step 3: Build the device tree file to be used (dtb):

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path to your GCC cross compiler>/aarch64-linux-gnu-
$ make defconfig distro.config
$ make dtbs
```

### Step 4: Build the new boot image, using the new device tree files:

```shell
$ git clone git://codeaurora.org/quic/kernel/skales
$ ./skales/dtbTool -o dt.img -s 2048 arch/arm64/boot/dts/qcom/
$ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/16.06/initrd.img-4.4.9-linaro-lt-qcom
$ wget https://builds.96boards.org/releases/dragonboard410c/linaro/debian/16.06/Image
$ ./skales/mkbootimg --kernel Image --ramdisk
initrd.img-4.4.9-linaro-lt-qcom --output boot-db410c.img --dt dt.img
--pagesize 2048 --base 0x80000000 --cmdline
"root=/dev/disk/by-partlabel/rootfs rw rootwait
console=ttyMSM0,115200n8"
```

### Step 5: Flash the new boot image and boot the device.

> Note: DragonBoard 410c must first be booted into fastboot mode

`$ sudo fastboot flash boot boot-db410c.img`

Kernel warning when booting the kernel:

Since the SPIDEV module is not a representation of a real hardware,
the kernel will produce a warning when booting the system, such as:

```shell
[   11.566840] spidev spi1.0: buggy DT: spidev listed directly in DT
[   11.566934] ------------[ cut here ]------------
[   11.571901] WARNING: at ../drivers/spi/spidev.c:719
```

The device will still be functional, so just ignore while testing the
SPIDEV devices.

#### Step 6: Test with spi-test

```
$ wget https://raw.githubusercontent.com/KnCMiner/spi-test/master/spi-test.c
$ gcc -o spi-test spi-test.c
$ ./spi-test -CHO -D /dev/spidev0.0  0xaa,0xbb,0xcc,0,0,0,0,0
 AA BB CC 00 00 00 00 00
 00 00 00 00 00 00 00 00
```

Loopback test:

```shell
$ ./spi-test -CHO -D /dev/spidev0.0  0xaa,0xbb,0xcc,0,0,0,0,0 --loop
 AA BB CC 00 00 00 00 00
 AA BB CC 00 00 00 00 00
``` 
 
