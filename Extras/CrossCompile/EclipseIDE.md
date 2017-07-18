---
title: Cross compiling with Eclipse for C and C++
permalink: /documentation/Extras/CrossCompile/EclipseIDE.md/
---
# Cross compiling with Eclipse for C and C++

## Part 1 - Using Eclipse on X86 Linux to cross compile C & C++ for ARM Linux

These instructions show how to install the Linux version of Eclipse, either on the latest Debian (Jessie) or Ubuntu (16.04). You will also learn how to install a copy of the Eclipse IDE for C/C++ Developers in your home directory.  These instructions do not demonstrate how to install Eclipse system wide.

Once Eclipse is installed, we will set up a project for cross compiling. It is assumed you have already installed and tested the command line cross compile toolchains ([Cross compile using command line](CommandLine.md)). These instructions do not presume to teach you everything about Eclipse, but rather how to get cross compiling working with Eclipse. If you are unsure as to how to use Eclipse, there are tutorials which can teach you how to use both basic and extended functions.

This instruction set can be paired with one of our [96Boards Blogs from David Mandala](http://www.96boards.org/blog/eclipse-x86-linux-cross-compile-arm-linux/)

## Assumptions

- Knowledge on how to use Eclipse as an Integrated Development Environment (IDE).
- Previously installed command line cross compilation tools ([Commandline instructions set](Commandline.md))
- Cross compiling host computer is X86 based running Linux, either Ubuntu 16.04, Debian Jessie, or Debian Testing with Jessie cross compiling tools installed. (other versions of Linux will have issues getting ssh keys working, it can be done but it’s “complex”, I”m will not try to this it here)
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

***

## Part 2 - Using Eclipse on X86 Linux to cross compile C & C++ for ARM Linux with external libraries

These instructions show how to use `ssh-keygen`, `ssh-agent` and some features of Eclipse to make use of external shared libraries. Some people will recommend generating an `ssh` key without a passphrase so it is easy to copy files from your X86 system to your ARM system; however, an ssh key without a passphrase is a real security hazard. Sure you intend it to be only on your development system but things can happen, and keys get copied by accident. I recommend you never make an SSH key without a strong passphrase.

## Generating & Installing your SSH Key

We will use the `ssh` tools to generate a key with `ssh-keygen`, install it on the remote ARM system with `ssh-copy-id` and then make use of `ssh-agent` to keep the passphrase available in memory so Eclipse can make use of it to copy the generated ARM binary file over to the 96Boards system.

`$ ssh-keygen -t rsa -b 4096 -f ~/.ssh/id_rsa_compile.rsa -C yourname@yourdomain`

When prompted for your passphrase use a passphrase you can remember, long enough to be secure but short enough to remember. Next copy it to the 96Boards using the `ssh-copy-id` command, and test it using the `ssh` command. You should be prompted for your passphrase, if you have not sshed into the 96Boards before you will be prompted that the authenticity of host [local ip address] can’t be established. When prompted to open the key each time you log in select yes.

`$ ssh-copy-id -i ~/.ssh/id_rsa_compile.rsa linaro@[local ip address]`
`$ ssh linaro@[local ip address]`

> Note: 96Boards ip can be retrieved by executing the following command from your 96Boards command line:

`$ /sbin/ifconfig`

## Adding remote copy commands to Eclipse

We are going to use the `scp` command to copy the ARM binary file from the X86 machine onto the ARM 96Boards. We will tell the `scp` command to create a Post-build command using the `ssh` key we generated above to copy the file over to the 96Boards. Since we enabled the system to open the key when you login, you are not prompted for a passphrase. For now we will just place the file into the linaro user directory, you can place it any where you want within the file system, in my next blog we will address remote debugging. We will also use `ssh` as a Pre-build command to remove the old binary on the remote file system so if the build fails you don’t have an old binary on the 96Boards system. If you don’t have Eclipse running the first command will start it.

#### Step 1: Open Eclipse

`$ ~/eclipse/cpp-neon/eclipse/eclipse &`

#### Step 2: Create new ARM project

`File -> New -> C-Project`
`Step 3: Create C Project`

- Project Name: test-64 if using the 64 bit toolchain or test-32 for the 32 bit toolchain
- Project Type: Hello World ANSI C Project
- Toolchains: Cross GCC
- Click the “Next” button

#### Step 4: Set Basic Settings

- Author: your name
- Click the “Next” button

#### Step 5: Select Configurations

- Click the “Select all” button
- Click the “Next” button

#### Step 6: Set Cross GCC Command

- Cross compiler prefix: “`aarch64-linux-gnu-`” for 64 bit or “`arm-linux-gnueabihf-`” for 32 bit
- Path: `/usr/bin`
- Click the “Finish” button

#### Step 7: Adjust the properties of your project

In the project Explorer window right click on your project, scroll to the bottom of the presented options and click on “Properties”

- Double Click on the “C/C++ Build” option
- Click on “Settings”
- Click on “Build Steps”
- In the “Post-build steps”: (the [binary name below will be test-64 if you are using the 64 bit toolchain or test-32 if you are using the 32 bit toolchain.
   - Command: “`/usr/bin/scp -i ~/.ssh/id_rsa_compile.rsa [binary name] linaro@[96Board IP address]:.`”
   - Description: Copy ARM binary to ARM 96Boards
- In the “Pre-build steps”:
   - Command: “`/usr/bin/ssh -i ~/.ssh/id_rsa_compile.rsa linaro@[96Boards IP address] “rm -f [binary name]”`”
   - Description: Remove the ARM binary from the ARM 96Boards
- Click on the “OK” button
   - Right click on your project, find the “Build Project” option and click on it.  When it’s done you will find the binary file has be copied over to the 96Boards.

**Congratulations**, you have gotten automatic copying and deleting setup, you’ll have to add it to each project when you create them but it does make it easier and quicker to get the ARM files on the ARM 96Boards machine. Remember, the file is only copied over on successful builds, the old file is removed from the 96Boards if the build is not successful.

There does seem to be an odd side effect.  If you run the build project command in Eclipse everything works as expected. If however you run the makefile from the command line “make clean all” the pre-build steps seem to be run as a post post command resulting in the binary being copied over to the ARM 96Boards and then being removed from it!

So if you want to run the makefile and have it work as expected I had to run it as “`make clean pre-build main-build`” and things worked as expected! I have NO idea why this is….

## Adding other libraries to Eclipse builds

Just like using the command line tools you can add library support within Eclipse. Again, you need to right click on your project, scroll to the bottom of the presented options and click on “Properties”.  Within the “Properties” you can add shared library to use, the path to them and the path to any needed Include files. That will allow the application to build and then run on the ARM system. So let’s get started. If you don’t have Eclipse running the first command will start it, let’s use the test-XY (32 or 64) project from the prior steps.

### To use Libsoc C Library:

#### Step 1: Open Eclipse

`$ ~/eclipse/cpp-neon/eclipse/eclipse &`

#### Step 2: In the project Explorer window right click on your project, scroll to the bottom of the presented options and click on “Properties”

- Double Click on the “C/C++ Build” option
- Click on “Settings”
- Click on “Tool Settings”
- Click on “Cross GCC Compiler”->“Includes”
- In the “Include paths (-I)”section: (the [path name below will be “aarch64-linux-gnu” if you are using the 64 bit toolchain or “arm-linux-gnuabihf” if you are using the 32 bit toolchain.
   - Click on the “Add” button (little + sign)
   - Directory: “`/usr/[pathname as above]/local/include`”
   - Click the “OK” button
- Click on “Cross GCC Linker”->“Libraries”
- In the “Libraries -l” section:
   - Click on the “Add” button (little + sign)
   - Libraries (-l) “soc”
   - Click the “OK” button
- In the “Library search path (-L)” section:
   - Click on the “Add” button (little + sign)
      - Directory: `/usr/[pathname as above]/local/lib`
      - Click the “OK” button
   - Click on the “OK” button at the bottom

#### Step 3: Exit Eclipse

OK, now we have set the Eclipse project up to use the libsoc library, now we are going to cheat a little bit. We are going to grab an example file from libsoc and replace the helloworld test-??.c file so we can see it build and link and run on the ARM 96boards system. In the libsoc directory there is a test directory, in there is a file called `board_test.c`. Copy that file and overwrite the `test-??.c` file.  For example I have the libsoc directory in a directory called hacking in my home directory (`~/hacking/libsoc/test/board_test.c`). My source file is in `workspace/test-64/src/test-64.c` so to copy the file over the other I’d use `cp ~/hacking/libsoc/test/board_test.c ~/workspace/test-64/src/test-64.c`  You will have to copy the `libsoc/test/board_test.c` file over your `test-??/src/test-??.c` file. Once you’ve done that restart Eclipse.

`~/eclipse/cpp-neon/eclipse/eclipse &`

Right click on your project, find the “Build Project” option and click on it. When it’s done you will find the binary file has be copied over to the 96Boards.  

When you run it it will execute the board_test libsoc application. Congratulations  you have just successfully setup Eclipse to use the external shared library libsoc. You can also use mraa the similar way, simply substitute “`mraa`” library for “`soc`” library in the above commands.  Even though the `mraa` library is a C++ library, the example file we are going to use “hellomraa.c” is a C file so we are just going to create a C project. Clearly if you are going to build a C++ application you should create a C++ project. Let’s walk through the process.  

### To use MRAA C++ library

#### Step 1: Open Eclipse

`$ ~/eclipse/cpp-neon/eclipse/eclipse &`

#### Step 2: create a new ARM project

- File -> New -> C-Project
- C Project
   - Project Name: test-64 if using the 64 bit toolchain or test-32 for the 32 bit toolchain
   - Project Type: Hello World C++ Project
   - Toolchains: Cross GCC
   - Click the “Next” button
- Basic Settings
   - Author: your name
   - Click the “Next” button
- Select Configurations
   - Click the “Select all” button
   - Click the “Next” button
- Cross GCC Command
   - Cross compiler prefix: “`aarch64-linux-gnu-`” for 64 bit or “`arm-linux-gnueabihf-`” for 32 bit
   - Path: `/usr/bin`
- Click the “Finish” button

#### Step 3: In the project Explorer window right click on your project, scroll to the bottom of the presented options and click on “Properties”

- Double Click on the “C/C++ Build” option
- Click on “Settings”
- Click on “Build Steps”
- In the “Post-build steps”: (the [binary name below will be test-64 if you are using the 64 bit toolchain or test-32 if you are using the 32 bit toolchain.
   - Command: “/usr/bin/scp -i ~/.ssh/id_rsa_compile.rsa [binary name] linaro@[96Board IP address]:.”
   - Description: Copy ARM binary to ARM 96Board
- In the “Pre-build steps”:
   - Command: “/usr/bin/ssh -i ~/.ssh/id_rsa_compile.rsa linaro@[96Board IP address] “rm -f [binary name]””
   - Description: Remove the ARM binary from the ARM 96Board
- Click on the “OK” button

#### Step 4: In the project Explorer window right click on your project, scroll to the bottom of the presented options and click on “Properties”

- Double Click on the “C/C++ Build” option
- Click on “Settings”
- Click on “Tool Settings”
- Click on Cross GCC Compiler -> “Includes”
- In the “Include paths (-I)”section: (the [path name below will be “aarch64-linux-gnu” if you are using the 64 bit toolchain or “arm-linux-gnuabihf” if you are using the 32 bit toolchain.
   - Click on the “Add” button (little + sign)
   - Directory: “/usr/[pathname as above]/local/include”
   - Click the “OK” button
- Click on “Cross GCC Linker”->“Libraries”
- In the “Libraries -l” section:
   - Click on the “Add” button (little + sign)
   - Libraries (-l) “mraa”
   - Click the “OK” button
- In the “Library search path (-L)” section:
   - Click on the “Add” button (little + sign)
   - Directory: “/usr/[pathname as above]/local/lib
   - Click the “OK” button
- Click on the “OK” button at the bottom

#### Step 5: Exit Eclipse

OK, now we have set the Eclipse project up to use the mraa library, again we are going to cheat a little bit. We are going to grab an example file from `mraa` and replace the `helloworld test-??.cpp` file so we can see it build and link and run on the ARM 96Boards system. In the mraa directory there is an examples directory, in there is a file called `hellomraa.c`,  copy that file and overwrite the `test-??.c` file. For example, I have the libsoc directory in a directory called hacking in my home directory (`~/hacking/libsoc/test/board_test.c`). My source file is in `workspace/test-64/src/test-64.c` so to copy the file over the other I’d use `cp ~/hacking/libsoc/test/board_test.c ~/workspace/test-64/src/test-64.c`  You will have to copy the `libsoc/test/board_test.c` file over your `test-??/src/test-??.c` file. Once you’ve done this, restart Eclipse.

`~/eclipse/cpp-neon/eclipse/eclipse &`

Right click on your project, find the “Build Project” option and click on it.  When it’s done you will find the binary file has be copied over to the 96Boards.  

When you run it it will execute the board_test libsoc application. Congratulations, you have just successfully setup Eclipse to use the external shared library libmraa.

So far you should have installed and setup command line cross compiling, the building cross compiled shared libraries, and use of shared libraries, then setup Eclipse for cross compiling from X86 to ARM, including using shared libraries, we have setup Eclipse to copy the new binary files over to the ARM 96Boards.
