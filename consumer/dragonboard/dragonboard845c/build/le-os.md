---
title: LE OS Build Guide for Dragonboard 845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/build/le-os.md.html
---

# Build LE OS for DragonBoard845c

## Step 1. Install Dependencies
``` sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath libsdl1.2-dev xterm openssl libssh-dev libssl-dev```


## Step 2. Download and Extract SDK
- **[Download SDK](https://thundercomm.s3-ap-northeast-1.amazonaws.com/shop/doc/1544580412842651/2d2154597cc14cae894076b1d7d06e55-1372688432)**
- **Extract SDK**
    - ```tar -xzf 2d2154597cc14cae894076b1d7d06e55-1372688432.gz```


## Step 3. Build LE OS
- **Build**

```Shell
cd SDA845-LE-SDK
./sync_and_build.sh
```
- **Confirm build is sucessfull**

```Shell
build@ubuntu$ ls ROBOTICS-SDA845_CAFBUILDID_VXX/poky/build/tmp-glibc/deploy/images/sda845-robot
sda845-cache.ext4
sda845-sysfs.ext4
sda845-usrfs.ext4
sda845-boot.img
sda845-persist.ext4
sda845-systemrw.ext4
vmlinux
```

- **Flash Images to UFS**
    - Follow the [installation instructions](../installation/).


# Build SDK Manually

## Build Images
-  Build all imageswith following commands:

```Shell
cd <metabuild_root>/apps_proc/poky
source build/conf/set_bb_env.sh
build-sda845-robot-image
```

## Build Kernel Image
- Before compiling, go to the poky directory. In the poky directory, execute the following commands to configure the environment: ```source build/conf/set_bb_env.sh```
- After executing the command, the directory automatically becomes poky/build. Execute the following commands to configure some environment variables:
```Shell
export MACHINE=sda845
export DISTRO=robot
```
- Ensure that the present work directory is poky/build: ```bitbake -c cleansstate linux-msm```
- Compile the kernel image by executing the following command: ```bitbake linux-msm```
- After compiling, the kernel image is located at: ```poky/build/tmp-glibc/deploy/images/```

## Build rootfs Image
- Before compiling, go to the poky directory. In the poky directory, execute the following commands to configure the environment: ```source build/conf/set_bb_env.sh```
- After executing the command, the directory automatically becomes poky/build. Execute the following commands to configure some environment variables:
```Shell
export MACHINE=sda845
export DISTRO=robot
```
- Ensure that the present work directory is poky/build: ```bitbake -c cleansstate linux-msm```
- Compile the rootfs image by executing the following command: ```bitbake machine-image```
- After compiling, the kernel image is located at: ```poky/build/tmp-glibc/deploy/images/```