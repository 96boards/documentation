---
title: Building Linaro images based on Debian
permalink: /documentation/consumer/guides/debian.html
---

This page is meant to be generic for any 96boards CE edition. However this guide is started from existing instructions for Dragonboard 410c, 820c, and 845c. It will become generic over time!

# Linaro Debian images for 96boards CE

Linaro is building custom images based on Debian operating system. This guide provides instructions on how such images are being created. In short, the whole image build process relies on FAI project/tool (see: https://wiki.debian.org/FAI and https://fai-project.org/) and on Linaro OBS instance (https://obs.linaro.org/).

As with any builds/images, all jobs are executed on Linaro Jenkins CI server (https://ci.linaro.org/).

The main jobs that create Dragonboard Debian images are:

* https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-debian-images-dragonboard410c.yaml
* https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-debian-images-dragonboard820c.yaml
* https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-debian-images-dragonboard845c.yaml

They are all very much the same, and they create images here:

* http://snapshots.linaro.org/96boards/dragonboard410c/linaro/debian/
* http://snapshots.linaro.org/96boards/dragonboard820c/linaro/debian/
* http://snapshots.linaro.org/96boards/dragonboard845c/linaro/debian/

We use trigger jobs to decide when to build:
* https://git.linaro.org/ci/job/configs.git/tree/trigger-lt-qcom-debian-images-dragonboard410c.yaml
* https://git.linaro.org/ci/job/configs.git/tree/trigger-lt-qcom-debian-images-dragonboard820c.yaml
* https://git.linaro.org/ci/job/configs.git/tree/trigger-lt-qcom-debian-images-dragonboard845c.yaml

All jobs use the following helpers:
* to build the root file system image: https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-debian-images/builders-fai.sh
* to publish the images: https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-debian-images/publishers.sh
* to generate the diff between two images: https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-debian-images/debpkgdiff.py

## Debian images configuration

As mentioned previously the FAI project tools are used to generate Linaro Debian images. All the configuration data used for the Linaro Debian images can be found here: https://git.linaro.org/ci/fai.git. In this set of configurations files, the following is defined:
* all supported images, and their list of packages
* all "board" specific configurations.

This is where the list of debian packages to pull/install is defined: https://git.linaro.org/ci/fai.git/tree/package_config. And this is where variables/custom configuration parameters are set: https://git.linaro.org/ci/fai.git/tree/class.

The FAI tool is then invoked from the command line using this FAI configuration data set and specific list of keywords to apply. For example, when a DEBIAN image for one of the Qualcomm boards, the QCOM keyword should be used, which uses this file: https://git.linaro.org/ci/fai.git/tree/package_config/QCOM, where for example, we define what the appropriate kernel package name is. As such when building with the flags QCOM,DB845C, the following kernel package is installed:

```
PACKAGES install-norec DB845C
linux-image-5.1.0-qcomlt-arm64
```

So basically to build a custom debian image for a new board, most of the time, only a couple of configuration files are needed, *and* of course a debian kernel package for the board.

## Linux kernel Debian package

There are many different ways to build a Debian package for a Linux kernel. Debian has its own set of tools and processes, but they are typically difficult to understand and use. Instead in this section we will be showing a simple approach, and that relies on the in-kernel mechanism to generate Debian kernel package, since the upstream Makefile from Linux can build such a Debian package directly.

It all starts from this trigger job: https://git.linaro.org/ci/job/configs.git/tree/trigger-lt-qcom-linux-4.14.0.yaml.

It monitors a specific kernel branch, which is used to create Debian images, and when there is a new commit, it generates a new build using this job: https://git.linaro.org/ci/job/configs.git/tree/lt-qcom-linux.yaml.

This job builds the kernel as a Debian package, and also create a Debian source package (e.g. a .dsc file + tarball of the source tree). The debian source package is sent to Linaro OBS instance to be built using this CI job: https://git.linaro.org/ci/job/configs.git/tree/build-package-obs.yaml.

Once the kernel is built in OBS, it appears in the Linaro OBS overlay (as .deb file), and that automatically triggers the Debian image job that we mentioned earlier. e.g. it will call FAI and pull all packages, including the new
kernel.
