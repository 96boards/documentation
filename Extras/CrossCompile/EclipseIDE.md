# Using Eclipse on X86 Linux to cross compile C & C++ for ARM Linux

These instructions show how to install the Linux version of Eclipse, either on the latest Debian (Jessie) or Ubuntu (16.04). You will also learn how to install a copy of the Eclipse IDE for C/C++ Developers in your home directory.  These instructions do not demonstrate how to install Eclipse system wide.

Once Eclipse is installed, we will set up a project for cross compiling. It is assumed you have already installed and tested the command line cross compile toolchains ([Cross compile using command line](Commandline.md)). These instructions do not presume to teach you everything about Eclipse, but rather how to get cross compiling working with Eclipse. If you are unsure as to how to use Eclipse, there are tutorials which can teach you how to use both basic and extended functions.

This instruction set can be paired with one of our [96Boards Blogs from David Mandala]()

## Assumptions

- Knowledge on how to use Eclipse as an Integrated Development Environment (IDE).
- Previously installed command line cross compilation tools ([Commandline instructions set](Commandline.md))
- Cross compiling host computer is X86 based running Linux, either Ubuntu 16.04, Debian Jessie, or Debian testing with Jessie cross compiling tools installed.
- You are cross compiling for 96Boards - either 32bit or 64bit ARM.

## Update Host System

The image on your host Linux computer might be out of date. This is possible even when using the stock images, recent downloads, or newly flashed versions of any operating system.

A few useful commands will help us make sure everything on the board is current:

- **apt-get update:** Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade:** Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade:** In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get dist-upgrade
```

## Install Eclipse IDE

Before moving on to the next sections, you will need to install the latest version of the Eclipse integrated development environment (IDE). The following steps will walk you through this process.

#### Step 1: Download Installer from [www.eclipse.org](www.eclipse.org)

To do this we will need to dig our way through download buttons. Using your preferred web browser, go to “[www.eclipse.org](www.eclipse.org)” and click the Download button located at the top-right.

Insert <Screenshot 87>

Once again click the yellow Download button.

Insert <Screenshot 88>

Finally, you will see a box with download mirror and button. You can change your mirror, or simply download from the suggested mirror by clicking this last Download button.

Insert <Screenshot 89>

Once download is complete proceed to next step.

#### Step 2: Extract your eclipse download and run the installer

- Open your terminal and change directory to the folder with your download. 
- Use the tar command to untar the downloaded tar file. 
- Change directory to the newly untarred eclipse-installer folder
- Execute the install script and proceed to the next step

**Commands:**

```shell
$ cd /~/Downloads
$ tar zxvf eclipse-inst-linux64.tar.gz
$ cd eclipse-installer
$ ./eclipse-inst
```
#### Step 3: Install  and Launch Eclipse

- The last command from the previous step will launch Eclipse Installer.
- You will be presented with a easy to understand graphical interface (GUI)
- Select the “Eclipse IDE for C/C++ Developers” option
- Select your “Installation Folder”

> Note: Default “Installation Folder” is /home/your user name/eclipse/cpp-neon2 - **We suggest keeping this default**.

- Click Install button
- Confirm License and installation will begin.

> Note: Installation time for Eclipse is dependent on your internet speed. If you have a poor internet connection, installation may take some time.

- Check box to indicate you trust the eclipse.org certificates
- When Install is complete you may start up the IDE by clicking the Launch button 
- Once eclipse launches, it will want you to select a workspace.  It is recommend to take the default offered and click OK.

## Back up Eclipse IDE - (Optional)

This optional step can be used to create a backup of your Eclipse directories. Doing this will allow you to start from scratch should any files become corrupted, or if your Eclipse IDE is rendered unusable after tampering with defaults.

This section should only be performed in line with the previous sections. Eclipse must first be installed using the downloaded installer.

#### Step 1: Exit Eclipse by closing the windows

#### Step 2: Combine all four Eclipse directories into a single reusable tar file

The Eclipse installer creates four separate directories including the workspace. These directories are required in order for Eclipse to work:

`/home/your user name/eclipse/cpp-neon2`
`/home/your user name/.p2`
`/home/your user name/.eclipse`
`workspace`

**Commands:**

```shell
$ cd ~
$ tar czvf pristine-eclipse.tar.gz .p2 .eclipse eclipse workspace
```

Your tar file of a pristine backup of Eclipse is now ready.

## First cross compile using Eclipse

Now that we have Eclipse installed it is time to do a cross compile project. Follow the steps below.

#### Step 1: Open Eclipse with the following command

`$ eclipse/cpp-neon/eclipse/eclipse`

#### Step 2: Start a new project

**“File” -> “New” -> “C Project”**

This will bring up a “C Project” screen.  You need to enter the project name and select the project type and Toolchain.

- Enter “Test1” for project name
- Select “Hello World ANSI C Project” for project type
- Select “Cross GCC for toolchains and click “Next”
- Enter your name for Author and click “Next”
- Be sure to select both “debug” and “release configuration”, or “Select All” and click “Next” to continue
- Enter a cross compiler prefix and path to the cross compiler tools
   - 32bit toolchain: “arm-linux-gnueabihf-”
   - 64bit toolchain: “aarch64-linux-gnu-”
- Enter “/usr/bin” for the cross compiler path and select “Finish”

These steps are the magic that will cause eclipse to use the ARM cross compiler tools you installed from a prior blog entry.

The new project screen will close and you will see in the “Project Explorer” tab a project called “Test1”. You will then see in the source code editor tab a C file called Test1.c, which will have code to generate “!!!Hello World!!!”

In the Project Explorer tab click on the right facing arrow next to the Test1 Project, this will expand the project.  You will see an Includes tab and a src tab, if you click on the right facing arrow next to the src tab you will see the Test1.c source file.


#### Step 3: Build the project

**Select “Project” -> “Build Project”**

Eclipse will run the cross compiler on the source file. You will see two (2) new Tabs in the Test1 Project. Binaries and Debug. These files were created during the build.

- Expand the Binaries tab to see Test1 - [arm/le]

#### Step 4: Access binary file in file system

- Open Terminal
- Change directory to the following:

`$ cd /workspace/Test1/Debug`

- Test your new Test1 binary file

`$ file Test1`

This file should be an ARM 32 or 64 bit file depending on which toolchain you used.  You can copy this file over to the 96Boards and it will run.
