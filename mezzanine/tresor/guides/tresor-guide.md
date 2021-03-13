---
title: 96Boards Tresor Mezzanine Getting Started Guide
permalink: /documentation/mezzanine/tresor/guides/tresor-guide.md.html
---
# Introduction

The [96Boards Tresor Mezzanine](https://www.96boards.org/product/tresor/) is
intended for security development on 96Boards and features the Infineon SLB9670
(TPM 2.0), SLB9645 (TPM 1.2), and SLS32AIA020A chip sets.

This guide will show how to setup the Tresor Mezzanine with 96Boards CE board.

# Required Hardware

- 96Boards CE board running latest Debian Linux, in this guide we will use the
  Dragonboard 410C
- Power supply
- Tresor Mezzanine
- USB A to B Micro cable

# Setting up the Mezzanine

- Connect the mezzanine on top of your Dragonboard410c.
- Power on your board.
- Download and install the latest Debian Linux as per the instructions in the
following [link](/documentation/consumer/dragonboard/dragonboard410c/downloads/debian.md.html)
- Make sure to connect the jumpers on mezzanine as shown in [README](../README.md#11-about-the-96boards-tresor-mezzanine)
- If using Dragonboard410c, below diff needs to be added to the kernel source:

```shell
diff --git a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
index c99fc9a..4e3ec52 100644
--- a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
+++ b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
@@ -139,6 +139,11 @@
 		/* On Low speed expansion */
 			label = "LS-SPI0";
 			status = "okay";
+			tpm_tis_spi@0 {
+				compatible = "tcg,tpm_tis-spi";
+				spi-max-frequency = <5000000>;
+				reg = <0>;
+                        };
 		};
 
 		leds {
diff --git a/arch/arm64/boot/dts/qcom/msm8916-pins.dtsi b/arch/arm64/boot/dts/qcom/msm8916-pins.dtsi
index d680b0e..82fc400 100644
--- a/arch/arm64/boot/dts/qcom/msm8916-pins.dtsi
+++ b/arch/arm64/boot/dts/qcom/msm8916-pins.dtsi
@@ -208,7 +208,7 @@
 			pins = "gpio16", "gpio17", "gpio19";
 		};
 		pinmux_cs {
-			function = "gpio";
+			function = "blsp_spi5";
 			pins = "gpio18";
 		};
 		pinconf {
diff --git a/drivers/spi/spi-qup.c b/drivers/spi/spi-qup.c
index 974a8ce..2969d59 100644
--- a/drivers/spi/spi-qup.c
+++ b/drivers/spi/spi-qup.c
@@ -754,6 +754,7 @@ static int spi_qup_io_config(struct spi_device *spi, struct spi_transfer *xfer)
 	else
 		control &= ~SPI_IO_C_CLK_IDLE_HIGH;
 
+	config |= SPI_IO_C_MX_CS_MODE;
 	writel_relaxed(control, controller->base + SPI_IO_CONTROL);
 
 	config = readl_relaxed(controller->base + SPI_CONFIG);
@@ -1113,7 +1114,7 @@ static int spi_qup_probe(struct platform_device *pdev)
 			base + QUP_ERROR_FLAGS_EN);
 
 	writel_relaxed(0, base + SPI_CONFIG);
-	writel_relaxed(SPI_IO_C_NO_TRI_STATE, base + SPI_IO_CONTROL);
+	writel_relaxed(SPI_IO_C_NO_TRI_STATE|SPI_IO_C_MX_CS_MODE, base + SPI_IO_CONTROL);
 
 	ret = devm_request_irq(dev, irq, spi_qup_qup_irq,
 			       IRQF_TRIGGER_HIGH, pdev->name, controller);
```
- Then enable the TPM driver as per below config:

```shell
CONFIG_TCG_TPM=y
CONFIG_TCG_TIS_CORE=y
CONFIG_TCG_TIS_SPI=y
CONFIG_HW_RANDOM_TPM=y
CONFIG_SECURITYFS=y
CONFIG_CRYPTO_HASH_INFO=y
```

- Finally, build and flash the kernel image onto Dragonboard410c as shown in [this guide](https://github.com/96boards/documentation/blob/171013c54099bdce960eca7cb421b95dd76eae6b/consumer/dragonboard/dragonboard410c/build/kernel.md)

# Using Tresor Mezzanine

Once the board is up and running with Mezzanine on top and with the modified
kernel, below output should be observed which indicates that the TPM is ready
to use:

```shell
root@linaro-developer:~# dmesg | grep tpm
[    1.423004] tpm_tis_spi spi0.0: 2.0 TPM (device-id 0x1B, rev-id 16)
[    1.437424] tpm tpm0: A TPM error (256) occurred continue selftest
[    1.437448] tpm tpm0: starting up the TPM manually

root@linaro-developer:~# ls /dev/tpm*
/dev/tpm0  /dev/tpmrm0
```

> Note: Error (256) can be safetly ignored!

Now, we can install TPM userspace tools:

## Install following packages

```shell
$ sudo apt-get update
$ sudo apt-get -y install aptitude autoconf autoconf-archive automake \
autotools-dev build-essential cmocka-doc libcurl4-gnutls-dev libgcrypt20-dev \
libglib2.0 libglib2.0-dev libcmocka-dev libssl-dev libtool m4 man-db pandoc \
pkg-config ruby-ronn uthash-dev zlib1g-dev doxygen
```

## Build and Install tpm2-tss

```shell
$ git clone https://github.com/tpm2-software/tpm2-tss
$ cd tpm2-tss/
$ ./bootstrap
$ ./configure --with-udevrulesdir=/etc/udev/rules.d --with-udevrulesprefix
$ make -j4
$ sudo make install
```

## Build and Install tpm2-tools

```shell
$ cd
$ git clone https://github.com/tpm2-software/tpm2-tools
$ cd tpm2-tools/
$ ./bootstrap
$ ./configure
$ make -j4
$ sudo make install
```

## Build and Install tpm2-tss-engine

```shell
$ cd
$ git clone https://github.com/tpm2-software/tpm2-tss-engine
$ cd tpm2-tss-engine/
$ ./bootstrap
$ ./configure
$ make -j4
$ sudo make install
$ sudo ldconfig
```

Finally we can use the `tpm2-tools` utility to access TPM functionalities.
For instance, below command generates Endorsement Key (EK) and outputs the
public portion of it.

```shell
linaro@linaro-developer:~$ sudo tpm2_createek -p ek.pub
transient-object-context: ek.ctx

# Check that it is loaded in transient memory
linaro@linaro-developer:~$ sudo tpm2_getcap -c handles-transient
- 0x80000000

# Flush the handle
linaro@linaro-developer:~$ sudo tpm2_flushcontext -c 0x80000000

# Note that it is flushed
linaro@linaro-developer:~$ sudo tpm2_getcap -c handles-transient
<null output>

# Reload it via loadexternal
linaro@linaro-developer:~$ sudo tpm2_loadexternal -a o -u ek.pub -o ek.ctx
transient-context: ek1.ctx
name: 0x000b472f9acd12a2a749d4ed35f85d58a2d0e110c424bcf77c7339883404e07b802e

# Check that it is re-loaded in transient memory
linaro@linaro-developer:~$ sudo tpm2_getcap -c handles-transient
- 0x80000000
```
