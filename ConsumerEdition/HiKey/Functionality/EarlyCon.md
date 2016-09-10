# Enabling Early Console on HiKey

## Introduction

A UART console is available on 96boards. In Linux, the console output may not
be available until later in the kernel boot process. Early console (earlycon)
is a feature in the kernel to capture console output from first entrance into
the kernel. This is useful for developers who are building custom kernels.
It is recommended to verify early console is working on a known working kernel
before attempting to use it on a non-working kernel.

***

## Getting Started with Earlycon

The following steps will cover setting up early console on HiKey. These
steps assume you have an existing kernel tree.

#### Step 1: Required kernel options

All kernel options to support the existing console must be enabled. This
should include

`CONFIG_SERIAL_AMBA_PL011=y`

`CONFIG_SERIAL_AMBA_PL011_CONSOLE=y`

An additional kernel option is required for early console

`CONFIG_SERIAL_EARLYCON=y`

This option should be automatically selected by the above console options.

#### Step 2: Identifying the correct kernel command line options

The early console will only be activated when appropriate arguments are
passed on the command line. The format for earlycon in general is

`earlycon=<options>`

The format needed for the console on HiKey is

`earlycon=pl011,0xf7113000`

This selects the pl011 console (the hardware used on HiKey) and uses the
UART at address 0xf7113000. This address corresponds to UART3.

#### Step 3: Adding the option to the kernel command line

The command line option from step #2 needs to be added to the command line.
On Android, the file device/linaro/hikey/BoardConfig.mk needs to be modified.
The variable `BOARD_KERNEL_CMDLINE` has the kernel command line. Add
`earlycon=pl011,0xf7113000` to that variable

```diff
diff --git a/BoardConfig.mk b/BoardConfig.mk
index 3dfc149..f8eaeda 100644
--- a/BoardConfig.mk
+++ b/BoardConfig.mk
@@ -33,7 +33,7 @@ CONFIG_DRIVER_NL80211 := y
 ifeq ($(TARGET_KERNEL_USE_4_1), true)
 BOARD_KERNEL_CMDLINE := console=ttyAMA3,115200 androidboot.console=ttyAMA3 androidboot.hardware=hikey firmware_class.path=/system/etc/firmware efi=noruntime
 else
-BOARD_KERNEL_CMDLINE := console=ttyFIQ0 androidboot.console=ttyFIQ0 androidboot.hardware=hikey firmware_class.path=/system/etc/firmware efi=noruntime
+BOARD_KERNEL_CMDLINE := console=ttyFIQ0 earlycon=pl011,0xf7113000 androidboot.console=ttyFIQ0 androidboot.hardware=hikey firmware_class.path=/system/etc/firmware efi=noruntime
 endif
 
 TARGET_NO_BOOTLOADER := true
```

After modifying the kernel command line, the boot.img must be rebuilt.
***

## Conclusion

Upon rebooting into your modified kernel, you should see console output from
the very beginning of kernel boot. If you do not see any early output,
verify the kernel command line is correct. This is printed out in the kernel
dmesg log

`[    0.000000] Kernel command line: console=ttyFIQ0 earlycon=pl011,0xf7113000`

This can also be collected from the command line

`$ cat /proc/cmdline`

There should also be a message in the kernel log

`[    0.000000] bootconsole [uart0] enabled`
