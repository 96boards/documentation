---
title: Build & Update Linux kernel on HiKey970
permalink: /documentation/consumer/hikey/hikey970/build/linux-kernel.md.html
redirect_from:  /documentation/consumer/hikey970/build/linux-kernel.md.html
---

# Build & Update Linux kernel on HiKey970

This page provides the instructions for building and deploying linux
kernel on HiKey970 from x86 host machine.

**This instruction is to be used only after building [AOSP](aosp.md)**

## Get Linux Kernel Source

```shell
$ git clone https://github.com/96boards-hikey/linux.git
$ git checkout -b hikey970-v4.9
```

## Prepare Tools and Files

- **Create Tools Folder**
  - Create a “tools” folder in the same level directory of the “linux” directory.
    ```
    $ cd linux
    $ mkdir tools
    ```
- **Copy ramdisk.img and mkbootimg to the Tools Directory**
  - Copy the compiled ramdisk.img and mkbootimg into the tools directory.
    ```
    $ cp ../system/core/mkbootimg tools/
    $ cp ..//out/target/product/hikey970/ramdisk.img tools/
    ```
- **Modify the Compilation Script**
  - Create the “build_kernel.sh” file, then copy the contents of the following text box and save it.
  ```
  #!/bin/bash
  DTB=1
  LOCAL_DIR=$(pwd)
  KERNEL_DIR=${LOCAL_DIR}/linux
  PRODUCT_OUT=${LOCAL_DIR}/out/target/product/hikey970
  GEN_IMAGES_DIR=${LOCAL_DIR}/tools
  HIKEY970_KERNEL=${LOCAL_DIR}/tools
  MKBOOTTOOL_DIR=${LOCAL_DIR}/tools
  CURRENT_DIR=${LOCAL_DIR}
  NCPU=`grep -c ^processor /proc/cpuinfo`
  if [ ! -e ${PRODUCT_OUT} ]
  then
  mkdir -p ${PRODUCT_OUT}
  fi
  export MINI_SYS=true
  export ARCH=arm64
  export
  CROSS_COMPILE=~/myview/code/hikey970_trunk_new/prebuilts/gcc/linux-x86/aa
  rch64/aarch64-linux-android-4.9/bin/aarch64-linux-androidfunction
  check_build_result()
  {
    if [ $? != 0 ]; then
    echo -e "\033[31m $1 build fail! \033[0m"
    exit -1
    else
    echo -e "\033[32m $1 build success! \033[0m"
    fi
  }
  if [ "${MINI_SYS}" != true ]; then
  source ./build/envsetup.sh && lunch hikey970-userdebug && make
  -j$[NCPU*2] $2
  check_build_result "Android System"
  fi
  cd ${KERNEL_DIR}
  make hikey970_defconfig && \
  make -j$[NCPU*2] Image.gz modules
  check_build_result "Kernel Image"
  rm -f arch/arm64/configs/hikey970_temp_defconfig
  cp arch/arm64/boot/Image.gz ${HIKEY970_KERNEL}
  if [ $DTB -eq 1 ]; then
  make hisilicon/kirin970-hikey970.dtb
  check_build_result "Hikey970 dtb"
  cp arch/arm64/boot/dts/hisilicon/kirin970-hikey970.dtb
  ${HIKEY970_KERNEL}
  fi
  cd ${CURRENT_DIR}
  if [ ${need_repack_userdata} ];
  then
  make -j$[NCPU*2] userdataimage-nodeps
  check_build_result "Hikey970 need repack userdataimage"
  fi
  if [ "${MINI_SYS}" = true ]; then
  RAMDISK=${GEN_IMAGES_DIR}/ramdisk.img
  else
  RAMDISK=${PRODUCT_OUT}/ramdisk.img
  if  [ ! -e $RAMDISK ]; then
  echo -e "\033[33m $RAMDISK is not exist! please build ramdisk first.
  \033[0m"
  echo -e "\033[33m . ./build/envsetup.sh && lunch hikey960-userdebug
  && make ramdisk \033[0m"
  exit -1
  fi
  fi
  #uefi boot.img = Image + dtb + ramdisk
  cat ${KERNEL_DIR}/arch/arm64/boot/Image
  ${KERNEL_DIR}/arch/arm64/boot/dts/hisilicon/kirin970-hikey970.dtb >
  ${HIKEY970_KERNEL}/Image-dtb
  check_build_result "Image-dtb"
  ${MKBOOTTOOL_DIR}/mkbootimg --kernel ${HIKEY970_KERNEL}/Image-dtb --ramdisk
  ${RAMDISK} --cmdline "androidboot.hardware=hikey970
  firmware_class.path=/system/etc/firmware loglevel=15
  buildvariant=userdebug androidboot.selinux=permissive
  clk_ignore_unused=true" --base 0x0 --tags_offset 0x07A00000 --kernel_offset
  0x00080000 --ramdisk_offset 0x07c00000 --os_version 7.0 --os_patch_level
  2016-08-05 --output ${PRODUCT_OUT}/boot.img
  check_build_result "Boot Image"
  echo -e "\033[36m build boot.img complete! \033[0m"
  ```

## Build the Linux Kernel

### Run build_kernel.sh

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path-to-cross-compiler>/aarch64-linux-gnu-gcc-
$ ./build_kernel.sh
```
> Note: Replace <path-to-cross-compiler> in the above command with the location
>       where you have extracted the toolchain

```shell
$ make defconfig distro.config
$ make bindeb-pkg LOCALVERSION=-hikey-linaro
```

After the compilation is completed, the boot.img can be generated under “out/target/product/hikey970”.
