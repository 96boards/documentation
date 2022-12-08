---
title: Build Source for WinLink E850-96Board
permalink: /documentation/consumer/e850-96b/build/
---
# Build from Source

It’s recommended to use Ubuntu 18.04 (64-bit) for building the Android. All further instructions are
given for exactly that distribution. Please make sure that your hardware meets the requirements
specified in Android build requirements document:
    - At least 300 GiB of drive space
    - At least 16 GiB of RAM; if you have less – please make sure your swap partition is 32 GiB or more.

1. **Installing build dependencies**
    - `$ sudo apt update`<br>`$ sudo apt install git-core gnupg flex bison build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 libncurses5 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev libgl1-mesa-dev libxml2-utils xsltproc unzip fontconfig gcc make perl libncurses5-dev libssl-dev bc bison flex minicom vim git python`

2. **Install the repo tool**
    - `$ mkdir ~/bin`<br>`$ curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo`<br>`$ chmod a+rx ~/bin/repo`<br>`$ export PATH=$HOME/bin:$PATH`

3. **Download and unpack the baremetal AArch64 GCC toolchain**
    - `$ wget "https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz"`<br>`$ sudo tar xJvf gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz -C /opt`<br>`$ rm gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz`

4.  **Configure basic Git settings (needed for repo tool to work properly):**
    - `$ git config --global user.email "you@example.com"`<br>`$ git config --global user.name "Your Name"`

5. **Obtaining the software**
    - Obtain Android-Q source code:
        - `$ mkdir -p ~/repos/android-q`<br>`$ cd ~/repos/android-q`<br>`$ repo init -u https://gitlab.com/Linaro/96boards/e850-96/platform/manifest.git -b android10-e850-96`<br>`$ repo sync -j32`
    - Obtain Linux kernel 4.14 source code:
        - `$ cd ~/repos`<br>`$ git clone https://gitlab.com/Linaro/96boards/e850-96/kernel.git`<br>`$ cd kernel`<br>`$ git checkout android-exynos-4.14-linaro`
    - Obtain LittleKernel bootloader source code:
        - `$ cd ~/repos`<br>`$ git clone https://gitlab.com/Linaro/96boards/e850-96/lk.git`<br>`$ cd lk`<br>`$ git checkout 3830-ww-dev-linaro-e850-96`

6. **Building the software**
    - Building the Android-Q: Android-Q source code contains prebuilt files for Linux kernel, bootloader, etc. So it’s possible to build just Android-Q (and skip building the kernel and bootloader), which will generate all needed images. Output images will be located in out/target/product/erd850/ directory.
         - `$ cd ~/repos/android-q`<br>`$ source build/envsetup.sh`<br>`$ lunch full_erd850-eng`<br>`$ make -j32`
    - Building the kernel
        - `$ cd ~/repos/kernel`
        - `$ prebuilts_path=~/repos/android-q/prebuilts`<br>`$ clang_path=$prebuilts_path/clang/host/linux-x86/clang-r328903`<br>`$ gcc_path=$prebuilts_path/gcc/linux-x86/aarch64/aarch64-linux-android-4.9`<br>`$ export LLVM_AR=$clang_path/bin/llvm-ar`<br>`$ export LLVM_DIS=$clang_path/bin/llvm-dis`<br>`$ export LTO_LLVM_LIB_BASE=$clang_path/lib64`<br>`$ export PATH=$gcc_path/bin:$PATH`<br>`$ export CROSS_COMPILE=aarch64-linux-android-`<br>`$ export PATH=$clang_path/bin:$PATH`<br>`$ export CLANG_TRIPLE=aarch64-linux-gnu-`<br>`$ export ARCH=arm64`
        - `$ fragments/make-config.sh e850-96 android-full`
        - `$ make -j32 CC=clang`
        - `$ scripts/dtc/rebuild-dtbx.sh`
    - Building the bootloader
        - `$ cd ~/repos/lk`<br>`$ export PATH=/opt/gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf/bin:$PATH`<br>`$ export ARCH_arm64_TOOLCHAIN_PREFIX=aarch64-none-elf-`
        - `$ make -j16 erd3830`
    - Rebuild Android with custom kernel
        - `$ cd ~/repos/android-q`<br>`$ source build/envsetup.sh`<br>`$ lunch full_erd850-eng`
        - `$ cp ~/repos/kernel/arch/arm64/boot/dts/exynos/exynos3830.dtb device/samsung/erd850-prebuilts/dtb.img`<br>`$ cp ~/repos/kernel/arch/arm64/boot/dts/exynos/exynos3830-e850-96-*.dtbo device/samsung/erd850-prebuilts/`<br>`$ cp ~/repos/kernel/arch/arm64/boot/Image device/samsung/erd850-prebuilts/kernel`<br>`$ cp ~/repos/kernel/vmlinux device/samsung/erd850-prebuilts/`<br>`$ cp ~/repos/lk/build-erd3830/lk.bin device/samsung/erd850-prebuilts/bootloader.img`
        - `$ cd device/samsung/erd850-prebuilts/`<br>`$ ./create-dtboimg.sh`<br>`$ rm *.dtbo`<br>`$ cd -`
        - `$ make -j32`

7. **Flashing the Software**
    - To flash the images, enter the fastboot mode:
        - Connect the power cable to your E850-96 board
        - Press “POWER” button (SW2) for 1 sec to start booting the bootloader
        - Press and hold the “VOL_UP” button (SW4) for 7 seconds
    - `$ cd ~/repos/android-q`<br>`$ source build/envsetup.sh`<br>`$ lunch full_erd850-eng`<br>`$ cd out/target/product/erd850/`<br>`$ ./ff_erd3830_all.sh`