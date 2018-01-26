---
title: AOSP Build Guide Index
permalink: /documentation/ConsumerEdition/guides/aosp-index.md.html
---

# AOSP(Android Open Source Project) Documentation Index & Setup Guide
***
### Documentation Index
- **A consolidated list linking to AOSP build instruction for supported 96Boards CE Products**
  - **[DragonBoard 410c](../DragonBoard-410c/Guides/AOSP.md)**
  - **[Hikey](https://source.android.com/setup/devices#hikey)**
  - **[Hikey960](https://source.android.com/setup/devices#hikey960)**


- **Supported Mezzanine Boards**
  - **[Neonkey](../../mezzanine/neonkey/guides/neonkey-aosp-build.md)**


### Build Environment Setup
- **Recomended OS:** Ubuntu 16.04 LTS. In case you are running some other distribution of Linux, consider using a containerized build environment running Ubuntu 16.04 LTS.
- **Dependencies:**

  ```shell
  $ sudo apt update;
  $ sudo apt-get install git-core gnupg flex bison gperf build-essential zip \
    curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev \
    x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev \
    libxml2-utils xsltproc unzip python-mako openjdk-8-jdk
  ```
- **Installing Repo Tool:** Repo is a tool that makes it easier to work with Git in the context of Android.

  ```shell
  $ mkdir ~/bin
  $ PATH=~/bin:$PATH
  $ curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
  $ chmod a+x ~/bin/repo
  ```
