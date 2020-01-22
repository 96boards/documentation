---
title: Mainline kernel build for AI_ML board
permalink: /documentation/consumer/aiml/build/mainline.md.html
---

# AI_ML board setup with mainline kernel and Linaro Debian image

We need to:
- Get sources
- Update U-boot
- Cross-compile mainline kernel
- Prepare and flash SD card

## Get sources
Let's create a folder and get the sources we need:
```
$ mkdir ~/ai_ml
$ cd ~/ai_ml
$ git clone https://source.codeaurora.org/external/imx/imx-atf
$ cd imx-atf
$ git checkout origin/imx_4.9.88_imx8qxp_beta2 -b imx_4.9.88_imx8qxp_beta2
$ cd ..
$ git clone https://github.com/Mani-Sadhasivam/u-boot.git -b ai_ml
$ git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
```

## Update U-boot
```
$ cd ~/ai_ml/imx-atf
$ make CROSS_COMPILE=aarch64-linux-gnu- PLAT=imx8qxp bl31
$ cd ..
```

Get scfw_tcm.bin and ahab-container.img
```
$ wget https://raw.githubusercontent.com/96boards-ai-ml/binaries/master/mx8qx-aiml-scfw-tcm.bin
$ wget https://www.nxp.com/lgfiles/NMG/MAD/YOCTO/firmware-imx-8.1.bin
$ chmod +x firmware-imx-8.1.bin
$ ./firmware-imx-8.1.bin
```

Copy the following binaries to U-boot folder:
```
$ cp imx-atf/build/imx8qxp/release/bl31.bin ./u-boot/
$ cp firmware-imx-8.1/firmware/seco/mx8qx-ahab-container.img ./u-boot/
$ cp mx8qx-aiml-scfw-tcm.bin ./u-boot/
```
Cross-compile U-boot:
```
$ cd ~/ai_ml/u-boot
$ make CROSS_COMPILE=aarch64-linux-gnu- imx8qxp_ai_ml_defconfig
$ make CROSS_COMPILE=aarch64-linux-gnu- u-boot-dtb.imx
```

Burn the u-boot-dtb.imx binary to SD card offset 32KB:
```
$ sudo dd if=u-boot-dtb.imx of=/dev/sd[x] bs=1024 seek=32
```

## Cross-compile mainline kernel

```
$ cd ~/ai_ml/linux
$ wget -O .config people.linaro.org/~servando.german.serrano/ai_ml/ai_ml_config
$ make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- dtbs modules Image
```

## Prepare and flash SD card

Make 2 ext4 partitions on the SD card:
- 120Mb partition called `boot`.
- Rest of SD card partition called `rootfs`.

Mount both partitions and `cd` into `boot`.
```
$ cd `/path/to/boot`
$ mkdir extlinux
$ cd extlinux
$ wget http://people.linaro.org/~servando.german.serrano/ai_ml/extlinux.conf
$ cd ..
$ cp ~/ai_ml/linux/arch/arm64/boot/Image .
$ cp ~/ai_ml/linux/arch/arm64/boot/dts/freescale/imx8qxp-ai_ml.dtb .
```

`cd` into `rootfs`:
Get linaro debian image
```
$ cd `/path/to/rootfs`
$ wget http://releases.linaro.org/debian/images/developer-arm64/18.04/linaro-stretch-developer-20180416-89.tar.gz
$ tar xzf linaro-stretch-developer-20180416-89.tar.gz
$ cd binary; sudo mv * ./..; cd ..; sudo rm -r binary
$ rm linaro-stretch-developer-20180416-89.tar.gz
```

Now install the kernel modules on the SD card:
```
$ cd ~/ai_ml/linux
$ make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules_install INSTALL_MOD_PATH=`path/to/rootfs`
```
