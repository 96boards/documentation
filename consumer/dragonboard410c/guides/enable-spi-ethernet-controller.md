---
title: How to hook up an SPI ethernet controller on 96boards
permalink: /documentation/consumer/dragonboard410c/guides/enable-spi-ethernet-controller.md.html
redirect_from:
- /db410c-getting-started/Guides/EnableSPIEthernetController.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/EnableSPIEthernetController.md.html
---
# How to hook up an SPI ethernet controller on 96boards

## Reference Hardware Setup
- [ENC28J60 Ethernet dongle](http://www.ebay.co.uk/itm/MiNi-ENC28J60-Ethernet-LAN-Network-Module-For-Arduino-SPI-AVR-PIC-LPC-STM32-/291694759068?hash=item43ea5ccc9c)
- [Sensor board](https://www.96boards.org/product/sensors-mezzanine/)

![](https://fileserver.linaro.org/owncloud/index.php/apps/files_sharing/ajax/publicpreview.php?x=2520&y=446&a=true&file=spi-ethernet-dongle.jpeg&t=k9n30ifZUDdNqru&scalingup=0)

**NOTE:**
- The 96boards SPI pins (LS connector) operates on 1.8v so make sure that the sensor board has appropriate level shifters if the dongle works on a different voltage (usually 3.3 or 5v).

### Connections
- Plug the sensor board onto a 96boards board via the LS connector
- Make the appropriate wirings or connections from the sensor board's SPI header (between AB and A_I2C) to the dongle, including VCC, GND and INT (orange cable above).
- The INT pin is usually connected to one of the GPIO pins available on the board

## Kernel Patches to Enable the ENC28J60 Dongle
### Common
```
diff --git a/arch/arm64/configs/defconfig b/arch/arm64/configs/defconfig
index 14d4ab7..b7ce20f 100644
--- a/arch/arm64/configs/defconfig
+++ b/arch/arm64/configs/defconfig
@@ -85,6 +85,7 @@ CONFIG_NETDEVICES=y
 CONFIG_TUN=y
 CONFIG_VIRTIO_NET=y
 CONFIG_NET_XGENE=y
+CONFIG_ENC28J60=y
 CONFIG_SMC91X=y
 CONFIG_SMSC911X=y
 CONFIG_USB_USBNET=y
@@ -110,6 +111,7 @@ CONFIG_VIRTIO_CONSOLE=y
 CONFIG_I2C_QUP=y
 CONFIG_SPI=y
 CONFIG_SPI_PL022=y
+CONFIG_SPI_QUP=y
 CONFIG_SPMI=y
 CONFIG_DEBUG_PINCTRL=y
 CONFIG_PINCTRL_MSM8916=y
```

### DB410c
```
diff --git a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
index 6153663..6883e62 100644
--- a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
+++ b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
@@ -129,6 +129,20 @@
                /* On Low speed expansion */
                        label = "LS-SPI0";
                        status = "okay";
+                       #address-cells = <1>;
+                       #size-cells = <0>;
+                       /* Max of 20Mhz supported by enc chip */
+                       spi-max-frequency = <10000000>;
+                       num-cs = <1>;
+                       cs-gpios = <&msmgpio 18 0>;
+                       eth0: enc28j60@0{
+                               compatible = "microchip,enc28j60";
+                               reg = <0>; /* CE0 */
+                               interrupt-parent = <&msmgpio>;
+                               interrupts = <12 IRQ_TYPE_EDGE_FALLING>; /* falling edge */
+                               spi-max-frequency = <16000000>;
+                               status = "okay";
+                       };
                };
```

### DB820c
```
--- a/arch/arm64/boot/dts/qcom/apq8096-db820c.dtsi
+++ b/arch/arm64/boot/dts/qcom/apq8096-db820c.dtsi
@@ -66,6 +66,20 @@
                /* On Low speed expansion */
                        label = "LS-SPI0";
                        status = "okay";
+                       #address-cells = <1>;
+                       #size-cells = <0>;
+                       /* Max of 20Mhz supported by enc chip */
+                       spi-max-frequency = <16000000>;
+                       num-cs = <1>;
+                       cs-gpios = <&msmgpio 2 0>;
+                       eth0: enc28j60@0{
+                               compatible = "microchip,enc28j60";
+                               reg = <0>; /* CE0 */
+                               interrupt-parent = <&msmgpio>;
+                               interrupts = <29 0x2>; /* falling edge */
+                               spi-max-frequency = <16000000>;
+                               status = "okay";
+                       };
                };
```

**NOTE:**
- Above patch is based on the `release/qcomlt-4.9` branch of the [Qualcomm LT kernel tree](https://git.linaro.org/landing-teams/working/qualcomm/kernel.git)

#### Rebuilding the kernel
Rebuild the kernel based on instructions [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/Releases/RPB_16.06/ConsumerEdition/DragonBoard-410c/BFSDebianRPB-16.06.md).
