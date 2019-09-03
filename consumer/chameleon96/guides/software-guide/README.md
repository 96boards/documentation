---
title: Software Guide
permalink: /documentation/consumer/chameleon96/guides/software-guide/
---
# Software Guide

# Updating source and images

Updates to the Chameleon96<sup>®</sup> project are available from the VM via SVN.
The following directories are maintained by SVN:
```
~/Projects/support_files
~/Projects/chameleon96/build/linux_custom
~/Projects/chameleon96/build/uboot_custom
```
These are available via SVN [here](http://novtech.ddns.net/svn/Customer/chameleon96)

with username: **chameleon96**
and password: **Chameleon2017@NovTech**

## First update

Initially, it is a good idea to pull the latest support files from SVN and update the svn_script, overlay and buildroot .config files located at **~/Projects/chameleon96**.

To do this, run the following commands:
```
cd ~/Projects/support_files
svn update
./load_files.sh
```
##	Updating from SVN with script

For your convenience, a script has been prepared which will update each of the three SVN repositories from within the **~/Projects/chameleon96** directory. This script is pre-installed at that location, but the SVN updated version of it can be found in the **~/Projects/support_files** directory.

To update the source and images, run the following commands (you may need to provide login credentials as indicated above):
```
cd ~/Projects/chameleon96
./svn_script get support_files
./svn_script get linux
./svn_script get uboot
```
#	Building source and images

Please refer to the [Chameleon96<sup>®</sup> User Guide](user-guide.md)  for instructions on retrieving and configuring the VM for use.

For convenience of development full source and pre-compiled images for console and GUI configurations are provided. The virtual machine is pre-configured with the necessary tools and packages for compilation.

##	Important VM directories

Open a terminal in the virtual machine.
Change directory to the **Projects** directory
```
cd ~/Projects
```

This directory contains the following directories:
-	buildroot-2015.08.01 – buildroot and associated support packages
-	chameleon96 – The buildroot project directory, containing a buildroot tree pre-configured for the Chameleon96<sup>®</sup>.
-	support_files – NovTech support files, including
   -	scripts to update VM packages and download from SVN.

##	Compiling in Buildroot

Change directory to **~/Projects/chameleon96** by typing
```
cd ~/Projects/chameleon96
```

Configure buildroot to include whatever packages you desire by typing
```
make menuconfig
```
and selecting packages.

Compile the buildroot tree by typing

```
make
```
It will take some time to compile.

When completed, you should see something like this:

<img src="../additional-docs/images/images-software/completed_compilation.png" data-canonical-src="../additional-docs/images/images-software/completed_compilation.png" width="636" height="407" />

##	Programming compiled images to SD/MMC cards

Once the compilation is complete, you will need to place the images onto an SD/MMC card for use in the Chameleon96®. The compiled buildroot images are located in: **~/Projects/chameleon96/images**

For convenience, a script has been provided which will place the images onto an SD/MMC card.
Insert the SD/MMC card into your PC and connect it to the VM by selecting it from the **Removable devices** menu.

From the **~/Projects/chameleon96** directory run
```
./mk_chameleon96_sd -a sdb
```
This will program the contents of the **~/Projects/chameleon96/images** directory onto the SD/MMC card at **/dev/sdb**. If your card is NOT located on **/dev/sdb**, use the appropriate device handle.

**Warning** - this script can be destructive if the wrong device handle is used. Please verify your SD/MMC card is at the expected location before executing. The card location can be verified by running
```
cat /proc/partitions
```
and looking for **/dev/sdb**.
 The script can also place individual portions of the compiled images. Run
```
mk_chameleon96_sd
```
without options for more information.

# Programming pre-compiled images to SD/MMC cards

Pre-compiled images for both the console and graphical systems are available from [here](https://novtech.sharefile.com) in the **03 – Compiled SD Images** directory.

Images in **03.01 – Card Images** can be programmed directly to SD/MMC cards with **dd** or Win32DiskImager per instructions in the [Chameleon96<sup>®</sup> User Guide](user-guide.md).

Images in **03.02 – Card Contents** can be downloaded to the VM extracted. These images can be written to cards using the **mk_chameleon96_sd** script included in their respective directories.
