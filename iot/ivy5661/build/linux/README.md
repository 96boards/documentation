---
title: Build Zephyr for IVY5661 on Linux
permalink: /documentation/iot/ivy5661/build/linux/
---

# Build for IVY5661 from source

This document illustrates how to build Zephyr for IVY5661 board.

## There will be 3 steps for building IVY5661 from source.
- **Step 1:** Prepare the environment.
- **Step 2:** Download the source code.
- **Step 3:** Choose the board and application profile to make.

In this example, we assume the path: ``~/workspace`` is your workspace.

## Step 1: Prepare the environment

In this section, we should follow the Zephyr official document to install the Zehpyr SDK:
https://docs.zephyrproject.org/latest/getting_started/installation_linux.html#install-the-zephyr-software-development-kit-sdk

## Step 2: Download the source code

```shell
$ cd ~/workspace
$ mkdir unisoc_zephyr_sdk && cd unisoc_zephyr_sdk
$ repo init -u https://github.com/unisoc/manifests.git -b master
$ repo sync
$ repo start --all master
```

## Step 3: Build Zephyr for IVY5661

```shell
$ make BOARD=96b_ivy5661 PROFILE=repeater
```

> Note: The default board is `96b_ivy5661`, while the default profile is `repeater`.
> You can choose a different profile/application or create a new one under `apps` directory.

After the compilation, the images can be found in the directory `output/repeater/images/`.

- ``fdl*.bin`` - Flash downloader
- ``mcuboot-pubkey*.bin`` - Bootloader
- ``zephyr-signed-ota*.bin`` - Kernel
- ``wcn-modem*`` - WCN Modem

Now, proceed to [installation page](../installation#methods-of-installation) for
flashing the binaries onto IVY5661.
