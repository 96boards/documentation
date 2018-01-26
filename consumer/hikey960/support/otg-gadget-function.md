USB functions are now ready for v4.13-rc1 based HiKey960 kernel, including:
- USB Host
- USB OTG Gadget
- USB OTG Host

Note: It's not upstreamed yet, but we plan to.

USB Host function testing is quite straight forward, you just need to plug in your USB devices to Host A port or to Type-C port via a proper OTG cable.

In this document, it describes how to test USB OTG Gadget function using generic linux distribution.

# Step 0:
Kernel source code and branch is here:
[https://github.com/96boards-hikey/linux/commits/hikey960-upstream-rebase](https://github.com/96boards-hikey/linux/commits/hikey960-upstream-rebase)

# Step 1:
Turn on the following Config items when building your own kernel:
```bash
 CONFIG_USB_GADGET=y
+CONFIG_USB_LIBCOMPOSITE=y
+CONFIG_USB_U_ETHER=y
+CONFIG_USB_F_NCM=y
+CONFIG_USB_F_ECM=y
+CONFIG_USB_F_SUBSET=y
+CONFIG_USB_F_RNDIS=y
+CONFIG_USB_CONFIGFS=y
+CONFIG_USB_CONFIGFS_NCM=y
+CONFIG_USB_CONFIGFS_ECM=y
+CONFIG_USB_CONFIGFS_ECM_SUBSET=y
+CONFIG_USB_CONFIGFS_RNDIS=y
 CONFIG_USB_RENESAS_USBHS_UDC=m
 CONFIG_MMC=y
```

# Step 2:

Create ```test.usb.otg.sh``` on your HiKey960 board：
```bash
mount -t configfs none /sys/kernel/config
mkdir /sys/kernel/config/usb_gadget/g1
echo "0x12d1" > /sys/kernel/config/usb_gadget/g1/idVendor
echo "0x107E" > /sys/kernel/config/usb_gadget/g1/idProduct
mkdir /sys/kernel/config/usb_gadget/g1/strings/0x409
echo "0123456789" > /sys/kernel/config/usb_gadget/g1/strings/0x409/serialnumber
echo "HISILICON" > /sys/kernel/config/usb_gadget/g1/strings/0x409/manufacturer
echo "Ethernet Gadget" > /sys/kernel/config/usb_gadget/g1/strings/0x409/product
mkdir /sys/kernel/config/usb_gadget/g1/functions/ecm.usb0
mkdir /sys/kernel/config/usb_gadget/g1/configs/c.1
mkdir /sys/kernel/config/usb_gadget/g1/configs/c.1/strings/0x409
echo "CDC" > /sys/kernel/config/usb_gadget/g1/configs/c.1/strings/0x409/configuration
ln -s /sys/kernel/config/usb_gadget/g1/functions/ecm.usb0 /sys/kernel/config/usb_gadget/g1/configs/c.1
echo "ff100000.dwc3" > /sys/kernel/config/usb_gadget/g1/UDC
```

# Step 3:
Connect OTG Type-C cable between HiKey960 and your PC.


# Step 4:
On HiKey960, run ```test.usb.otg.sh```. It will setup CDC-ECM on Type-C OTG port.

Done. Now HiKey960 can communicate with your PC.
