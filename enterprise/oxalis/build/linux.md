---
title: Build Source for Oxalis
permalink: /documentation/enterprise/oxalis/build/
---

# Build from Source

### Download and Test Build SDK
The following instructions assume you are running Linux and are well versed in using a terminal.
On any other operating system we recommend installing VirtualBox from
https://www.virtualbox.org or any other virtualization system that lets you run a Linux
distribution.

- Download, unpack and install the [NXP-QoriQ Linux SDK v2.0 source](https://www.nxp.com/support/developer-resources/run-time-software/linux-software-and-development-tools/linux-sdk-for-qoriq-processors:SDKLINUX).
- Download and install the NXP-QoriQ Linux SDK v2.0 17.03 Upgrade.
- Change into your SDK directory using the linux console.
- Run ```. ./fsl-setup-env -m ls1012frdm```
- Accept the EULA, you should now have been transferred into a directory called build_ls1012afrdm.
- Verify your installation state by running bitbake fsl-image-core (This will take a long time, depending on your system)

If bitbake runs through without major errors, your installation of the Yocto SDK has been
successful.

> Note: The image that resulted from this test-build carries no Oxalis specific customizations but might
be bootable on your board (not supported).


### Get Oxalis Specific SDK
- Execute the following:
```
$ cd <sdk-install-dir>/
$ mkdir systart
$ cd systart
$ git clone https://github.com/ebs-systart/meta-systart-oxalis
$ source meta-systart-oxalis/scripts/oxalis-setup-env
```
- You should now have been switched into a new build directory ie ```<build-dri>```
```
$ <sdk-install-dir>/build_oxalisls1012a
```

### Build
- From here bitbake should be able to build these images:
  - ```oxalis-image-kernelitb```: Kernel, U-Boot and minimal Linux environment (BusyBox) ramdisk in U-Boot loadable format. Recomended Target.
  - ```oxalis-image-core```: RootFS image with core components
  - ```oxalis-image-full```: RootFS with full content of the yocto distribution, including GUI (very large, extreme build times, not supported).

- To start build, run ```$ bitbake oxalis-image-kernelitb```

- After the build you can find the images in:
```<sdk-install-dir>/<build-dir>/tmp/deploy/images/ls1012aoxalis/```

**Follow [Installation Guide](../installation/)**
