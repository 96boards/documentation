---
title: Build the android-mainline kernel for Hikey960
permalink: /documentation/consumer/hikey/hikey960/build/android-mainline.md.html
redirect_from:
- /documentation/ConsumerEdition/HiKey960/BuildSource/android-mainline.md.html
- /documentation/consumer/hikey960/build/android-mainline.md.html

---
# Build the android-mainline kernel for Hikey960
Since the [ACK (Android Common Kernel)](https://android.googlesource.com/kernel/common/) android-mainline branch in AOSP does not officially support the Hikey960 dev board, Linaro does some work to keep this combination working on a best-effort basis. Here are some instructions on how to build the ACK android-mainline kernel for this dev board for people interested in it.

The instruction is based on the [Android Building Kernels](https://source.android.com/docs/setup/build/building-kernels) document.

## Repo sync the android-mainline source
```shell
$ mkdir android-kernel && cd android-kernel
$ repo init -u https://android.googlesource.com/kernel/manifest \
        -b common-android-mainline
$ repo sync -j$(nproc)
```
## Git clone the external module repository
```shell
$ git clone -b android-mainline-linaro \
        https://android-git.linaro.org/git/kernel/hikey-modules \
        hikey-modules-linaro/hikey960/android-mainline
```

## Apply out of tree patches
Since there are some out of tree patches used as temporary workaround, they should be applied before  start building the kernel.
```shell
$ cd common && \
        ../hikey-modules-linaro/hikey960/android-mainline/patchsets/apply.sh && \
        cd -
```
## Build the kernel
```shell
$ tools/bazel run \
        --config=release \
        //hikey-modules-linaro/hikey960/android-mainline:hikey960_dist
```
## Artifacts path
The kernel/dtb/ko files could be found under the directory of out/android-mainline/dist:

```shell
$ ls -1 out/android-mainline/dist/Image* out/android-mainline/dist/*.dtb
out/android-mainline/dist/Image
out/android-mainline/dist/Image.gz
out/android-mainline/dist/hi3660-hikey960.dtb
...
$
```

## Build AOSP with the android-mainline kernel files
For the instructions on how to build the userspace images with the AOSP tree, the instructions on [Android Open Source Project](http://source.android.com/) for [Hikey960 boards](https://source.android.com/docs/setup/create/devices#960userspace) could be referred to.

Download the AOSP tree:
```shell
$ repo init -u https://android.googlesource.com/platform/manifest -b master
$ repo sync -j$(nproc)
```
Delete all files under ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/ , then copy all the artifact files from the kernel build dist directory to ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/

```shell
$ cp ${KERNEL_TOPDIR}/out/android-mainline/* \
        ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/
```
Build the Android Userspace:
```shell
$ ./device/linaro/hikey/fetch-vendor-package.sh
$ . ./build/envsetup.sh
$ lunch hikey960-userdebug
$ make TARGET_KERNEL_USE=mainline -j$(nproc)
```
To test with the android-mainline GKI kernel, please check the [latest android-mainline kernel_aarch64 build](https://ci.android.com/builds/branches/aosp_kernel-common-android-mainline/grid?), In artifacts, download the Image.gz file and copy it to ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/, concatenate the DTB:

```shell
$ cat ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/Image.gz \
        ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/hi3660-hikey960.dtb > \
        ${AOSP_TOPDIR}/device/linaro/hikey-kernel/hikey960/mainline/Image.gz-dtb
```
Build again with the new kernel using the instructions above.

## Flash and deploy to the board
Please flash with the ./device/linaro/hikey/installer/hikey960/flash-all.sh script to deploy the new images.

One may refer to the [Installing local images](https://source.android.com/docs/setup/create/devices#960fastboot) document for details.

```shell
$ ./device/linaro/hikey/installer/hikey960/flash-all.sh
```
