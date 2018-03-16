---
title: Software Guide
permalink: /documentation/consumer/imx7-96/guides/software-guide.md.html
redirect_from:
- /documentation/ConsumerEdition/imx7-96/Guides/software-guide.md.html
---
# Software Guide

# 1 Updating source and images

Updates to the Meerkat<sup>®</sup> project are available from the VM via SVN.
The following directories are maintained by SVN:

~/Projects/support_files
~/Projects/meerkat96/build/linux_custom
~/Projects/meerkat96/build/uboot_custom

These are available via SVN from

http://novtech.ddns.net/svn/Customer/meerkat96
with username: meerkat96
and password: Meerkat2017@NovTech

## 1.1	First update

Initially, it is a good idea to pull the latest support files from SVN and update the svn_script, overlay and buildroot .config files located at ~/Projects/meerkat96.

To do this, run the following commands:
cd ~/Projects/support_files
svn update
./load_files.sh

## 1.2	Updating from SVN with script

For your convenience, a script has been prepared which will update each of the three SVN repositories from within the “~/Projects/meerkat96” directory. This script is pre-installed at that location, but the SVN updated version of it can be found in the “~/Projects/support_files” directory.

To update the source and images, run the following commands (you may need to provide login credentials as indicated above):

cd ~/Projects/meerkat96
./svn_script get support_files
./svn_script get linux
./svn_script get uboot

# 2	Building source and images


Please refer to the [i.MX7 96Board User Guide](guides/user-guide.md) for instructions on retrieving and configuring the VM for use.

For convenience of development full source and pre-compiled images for console and GUI configurations are provided. The virtual machine is pre-configured with the necessary tools and packages for compilation.

## 2.1	Important VM directories

Open a terminal in the virtual machine.
Change directory to the “Projects” directory (cd ~/Projects)

This directory contains the following directories:
 - buildroot-2015.08.01 – buildroot and associated support packages
 - meerkat96 – The buildroot project directory, containing a buildroot tree pre-configured for the i.MX7 96Board.
 - support_files – NovTech support files, including
   - scripts to update VM packages and download from SVN.

## 2.2	Compiling in Buildroot

 - Change directory to “~/Projects/meerkat96” by typing “cd ~/Projects/meerkat96”

 - Configure buildroot to include whatever packages you desire by typing “make menuconfig” and selecting packages.

 - Compile the buildroot tree by typing “make”. It will take some time to compile.

 - When completed, you should see something like this:

 <img src="https://github.com/96boards/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-software/completed-compilation-buildroot.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-software/completed-compilation-buildroot.png?raw=true" width="250" height="160" />
