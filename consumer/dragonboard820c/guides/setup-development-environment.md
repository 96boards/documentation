---
title: Setup Development Environment
permalink: /documentation/consumer/dragonboard820c/guides/setup-development-environment.md.html
redirect_from:

---
# Setup Development Environment
These guides will help to get you started with setting up the development environment to start developing cool IoT, [**IoMT** (Internet of Medical Things)](http://www.healthcaretechnologies.com/the-internet-of-medical-things-internet-of-things-health), [**IoMBT** (Internet of Military/Battlefield Things)](https://publications.computer.org/cloud-computing/2018/03/22/internet-of-military-battlefield-things-iomt-iobt/) and **[Azure IoT Edge](https://azure.microsoft.com/en-us/services/iot-edge/)** modules and applications utilizing the power of the cross platform **[.NET Core 2.1](https://blogs.msdn.microsoft.com/dotnet/2018/02/27/announcing-net-core-2-1-preview-1/)** framework and Docker.
We aim to use open source libraries to access **[GPIO](https://en.wikipedia.org/wiki/General-purpose_input/output)**, **[UART](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter)**, **[I²C](https://en.wikipedia.org/wiki/I%C2%B2C)**, **[SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus)** and other hardware resources via the **[MRAA](https://iotdk.intel.com/docs/master/mraa/)** and **[UPM](https://iotdk.intel.com/docs/master/upm/)** libraries.
We also would like to venture into the **[ARM Mbed](https://www.mbed.com/en/)** camp and get our feet wet with Bluetooth 5 development to transmit sensor data to or IoT hub. 

## Prerequisites
- Developer or ALIP GUI image of Debian Buster is installed and running on DragonBoard 820c.
- [Grove Seeed Sensor Mezzanine](https://www.96boards.org/product/sensors-mezzanine/).
- Windows 10 PC.
- [Windows Subsystem for Linux (WSL)](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux) installed. Follow [these](https://docs.microsoft.com/en-us/windows/wsl/install-win10) instructions to install.
- mini USB of Sensor Mezzanine connected to  Windows 10 PC.
- [Putty](https://www.putty.org/) installed (or other terminal program for SSH and serial communication).
- Putty terminal from Windows 10 PC to DragonBoard 820c (shell access).
- Read the [DB410c Major League Hack Quick Start Guide](https://developer.qualcomm.com/download/db410c/mlh-quick-start-guide.pdf). While it's for the DragonBoard 410c, the successor of the DragonBoard 820c, the content is still relevant and  can be used for the DragonBoard 820c.
- Wi-Fi.
- The Ethernet connector of the DragonBoard 820c is connected to the LAN on the same subnet as your Wi-Fi.
- HDMI connector of the DragonBoard 820c is connected to a display.
- USB connector of the DragonBoard 820c has a wireless mouse/keyboard receiver.
 
## Overview
At this point you put either the developer or the ALIP GUI image on your DragonBoard 820c.
If not, please go to the **[Installation](/documentation/consumer/dragonboard820c/installation/)** and come back when it's done.
These steps below will provide a basic developer environment.
In subsequent guides we'll branch out to various topics in more details.

## Initial Setup
Stop LXQt desktop, with the SDDM login manager

```shell
systemctl stop sddm
```

Set columns and rows for better UI

```shell
stty rows 50 cols 140
```

## Rename host
For developer image

```shell
sed -i 's/linaro-developer/TeleCuris/' /etc/hosts
sudo hostnamectl set-hostname TeleCuris
```

For ALIP GUI image

```shell
sed -i 's/linaro-alip/TeleCuris/' /etc/hosts
sudo hostnamectl set-hostname TeleCuris
```

Reboot

```shell
reboot
```

## Connect to Wi-Fi
The ```nmtui``` NetworkManager utility enable us to connect to Wi-Fi and to configure network setting.
Please read the **1.3.3 Connect to Wi-Fi** chapter of the [DB410c Major League Hack Quick Start Guide](https://developer.qualcomm.com/download/db410c/mlh-quick-start-guide.pdf) for more details about the ```nmtui``` and ```nmcli``` tools.
After connecting to Wi-Fi get your IP addresses.

```shell
ip addr show
```

There are ways to setup static IP addresses on the board itself.
I chose to use the DHCP Address Reservation feature of my router. I got the Ethernet and Wi-Fi MAC addresses and associated them with the desired IP addresses. This strategy suits me. I'd like to hear yours.

## Install Base Packages
This section will guide you through the process of setting up the base development environment to make sure your board has all the appropriate dependencies needed for development.

```shell
sudo apt update && \
 sudo apt upgrade -y && \
 sudo apt dist-upgrade -u -y && \
 sudo apt-get clean && \
 sudo apt autoremove -y && \
 sudo apt-get install -y \
  apt-utils \
  ca-certificates \
  lsb-release \
  locales \
  curl \
  wget \
  unzip \
  procps \
  tar \
  openssh-server \
  htop \
  dos2unix \
  nano \
  mc \
  tmux
```

## Install .NET Core 2.1 Remote Debugging
Enable the remote debugger for .NET Core 2.1
  
```shell
sudo apt-get install -y \
 libunwind8 gettext apt-transport-https \
 && curl -sSL https://aka.ms/getvsdbgshbeta | bash /dev/stdin -v latest -r linux-arm -l /vsdbg
```

## Install Docker dependencies
Install Docker dependencies

```shell
sudo apt-get install -y \
 gnupg2 software-properties-common
```

## Install Sensor Board dependencies
Install Sensor Board dependencies

```shell
sudo apt-get install -y \
 arduino-mk arduino git build-essential cmake bison doxygen graphviz python-sphinx python3-sphinx libudev-dev libgtest-dev libjson-c-dev autoconf libtool python-dev python-pip python3-pip pkg-config libpcre3-dev libjpeg-dev clang-6.0 libclang-6.0-dev python-clang-6.0 \
 # && rm -rf /var/lib/apt/lists/* \
```

## Install verious other dependencies

```shell
sudo apt-get install -y python3-pip
sudo apt-get install -y python3-dev python3-tk python3-numpy
sudo apt-get install -y python3-scipy
sudo apt-get install -y python-opencv
sudo apt-get install -y libopencv-dev
```

Reboot

```shell
reboot
```

## Setup Desktop Environment
If you installed the developer image you might want to add the Desktop Environment later or you installed the ALIP GUI image, but you want to use a different theme, perhaps another Desktop Manager than sddm.

```shell
sudo tasksel
```

This command provides a character based UI.
Select the following by typing space.

- Debian Desktop Environment
- All or some indented GUI themes
- SSH Server

select sddm Desktop Manager when asked.
  
Reboot

```shell
reboot
```

## Setup linaro user

**Change default linaro password.** 
You are logged in as ```root``` admin. 
```shell
passwd linaro
```
Type your new password twice. 
**Logon to ```linaro``` default user**
```shell
login linaro
```

Type your new password.

**Add Python to the PYTHONPATH environment variable.**

```shell
sudo sed -i '$a export PYTHONPATH=/usr/local/lib/python3.6/dist-packages:/usr/local/lib/python2.7/site-packages\n' ~/.bashrc
```

## Add a new user
**SSH ACL**

```shell
sudo groupadd -rf ssh
sudo usermod -a -G ssh root
sudo adduser $USER ssh
```

**I²C ACL**

```shell
sudo adduser $USER i2c
```

**logout to root**

```shell
logout
```

**Fix /etc/adduser.conf before we add a new user**

```shell
sed -i 's/#ADD_EXTRA_GROUPS/ADD_EXTRA_GROUPS/' /etc/adduser.conf
sed -i 's/#EXTRA_GROUPS="dialout cdrom floppy audio video plugdev users"/EXTRA_GROUPS="linaro adm dialout cdrom sudo audio dip video plugdev staff systemd-journal netdev bluetooth ssh pulse-access i2c"/' /etc/adduser.conf
```

**Add the new user**

```shell
adduser [new username] --add_extra_groups
```
Provide Full name and other info if you wish.

```shell
login [new username]
```

Type password

let's test which group the user belongs to

```shell
groups
```

You should see this:

```shell
[new username] adm dialout cdrom sudo audio dip video plugdev staff systemd-journal netdev bluetooth ssh pulse-access i2c linaro
```

**Add Python to the PYTHONPATH environment variable.**

```shell
sudo sed -i '$a export PYTHONPATH=/usr/local/lib/python3.6/dist-packages:/usr/local/lib/python2.7/site-packages\n' ~/.bashrc
```

logout to root

```shell
logout
```

## Add SSH keys
Please follow the [Setup SSH](setup-SSH.md) guide.


## Setup [new username] in GUI

On the DragonBoard 820c GUI login as [new username]. Please choose [LXQt](https://lxqt.org/) (lightweight Qt) desktop environment when asked.

## Install X11 Windowing System
Please refer to the **1.3.3.3 Case of the Interstitial Wi-Fi** chapter of the [DB410c Major League Hack Quick Start Guide](https://developer.qualcomm.com/download/db410c/mlh-quick-start-guide.pdf) for more details.

**In Windows 10 WSL**

```shell
sudo su
echo "" >> ~/.bashrc
echo "# XMING (X11 windowing system)" >> ~/.bashrc
echo "export DISPLAY=localhost:0.0" >> ~/.bashrc
exit
```

**On Windows**

Install [XMING](https://sourceforge.net/projects/xming/files/latest) (X11 windowing system).
Start Xming.

**In SSH terminal to DragonBoard 820c**

```shell
sudo apt-get install -y x11-apps
xeyes
```

observe eyes on Windows 10 UI.

## Install WinSCP
**[WinSCP](https://winscp.net/eng/download.php)** is a remote File Manager for DragonBoard 820c via SSH. Setup a connection to your board, please and enjoy the GUI capabilities.

## Install .NET Core 2.1
[.NET Core 2.1](https://blogs.msdn.microsoft.com/dotnet/2018/02/27/announcing-net-core-2-1-preview-1/) is a cross platform development framework. Version 2.1 is the first version that includes the majority of the legacy .NET Framework. I's a prerequisite for many components like the new, rewritten **[SignalR](https://blogs.msdn.microsoft.com/webdev/2018/02/27/asp-net-core-2-1-0-preview1-getting-started-with-signalr/)** (part of ASP.NET Core 2.1) and enables building dockerised components for cloud microservices and **[Azure IoT Edge modules](https://docs.microsoft.com/en-us/azure/iot-edge/tutorial-csharp-module)** (Docker containers) alike.

> **.NET Core 2.1** and **Docker** provides a truly polyglot development paradigm that we have been waiting for. 

It's very exiting that recently Microsoft released an [arm64v8](https://en.wikipedia.org/wiki/ARM_architecture) (aka AArch64) version of .NET Core 2.1, that is just perfect for our new and shiny DragonBoard 820c (precious).

Kudos to [Richard Lander](https://twitter.com/runfaster2000?lang=en) and [Peter Marcu](https://twitter.com/petermarcu?lang=en) to make this happen and thanks again for their contribution that is so important for our community.
Currently only the runtime is available, but since there is an SDK alrady for [armhf](https://en.wikipedia.org/wiki/ARM_architecture) (ARM hard float, ARMv7 architecture, like the one in Raspberry Pi) the arm64v8 .NET Core 2.1 SDK is just right around the corner (no pressure Rich, and Pete).

But wait. There is more!

What is even more exiting is that [Microsoft will launch ARM64 app SDK for Snapdragon 835 laptops at BUILD 2018 Conference](https://hothardware.com/news/windows-on-snapdragon-to-get-64-bit-app-support) in May 2018.
Now you can have a Windows 10 laptop for only [$999](https://hothardware.com/news/hp-envy-x2-2-in-1-snapdragon-835-windows-10-convertible-preorder) that you can use as your ARM development workstation and do not have to cross compile any more!

Alternatively you can purchase the also newly released and powerful **[SynQuacer 96Boards Enterprise Platform](https://www.cnx-software.com/2017/09/24/gigabyte-synquacer-96boards-enterprise-platform-is-powered-by-socionext-sc2a11-24-core-armv8-soc/)**, powered by [SocioNext SC2A11](https://www.socionext.com/en/products/assp/SC2A11/) 24-core ARMv8 SoC.
Don't we just love options and competition!

**Install .NET Core 2.1**  

```shell
sudo rm -r /usr/share/dotnet
sudo mkdir /usr/share/dotnet
sudo curl https://dotnetcli.blob.core.windows.net/dotnet/Runtime/master/dotnet-runtime-latest-linux-arm64.tar.gz | sudo tar xz -C /usr/share/dotnet
sudo ln -sf /usr/share/dotnet/dotnet /usr/bin/dotnet
```

**Test Installation 1**

```shell
dotnet --info
```

**Output**
```shell
Host (useful for support):
  Version: 2.1.0-preview3-26406-06
  Commit:  213c19510e

.NET Core SDKs installed:
  No SDKs were found.

.NET Core runtimes installed:
  Microsoft.NETCore.App 2.1.0-preview3-26406-06 [/usr/share/dotnet/shared/Microsoft.NETCore.App]
```

**Test Installation 2**

```shell
dotnet --list-runtimes
```

**Output**
```shell
Microsoft.NETCore.App 2.1.0-preview3-26406-06 [/usr/share/dotnet/shared/Microsoft.NETCore.App]
```

## Install Docker
**[Docker](https://www.docker.com/)**  enables true independence between applications and infrastructure and developers and IT ops to unlock their potential and creates a model for better collaboration and innovation.
It's quickly encroaching into IoT as well via **[Azure IoT Edge](https://azure.microsoft.com/en-us/services/iot-edge/)** modules.

**Install Docker**

```shell
wget https://download.docker.com/linux/debian/dists/stretch/pool/edge/arm64/docker-ce_18.03.0~ce-0~debian_arm64.deb
sudo dpkg -i docker-ce_18.03.0~ce-0~debian_arm64.deb
```

**Add the docker group if it doesn't already exist.**

```shell
sudo groupadd docker
```

**Add the connected user "$USER" to the docker group.**

```shell
sudo usermod -aG docker $USER
sudo gpasswd -a $USER docker
```

**Reboot**

```shell
sudo shutdown -P now
```

**Test**
 
```shell
docker version
```

**Output**

```shell
Client:
 Version:       18.03.0-ce
 API version:   1.37
 Go version:    go1.9.4
 Git commit:    0520e24
 Built: Wed Mar 21 23:10:06 2018
 OS/Arch:       linux/arm64
 Experimental:  false
 Orchestrator:  swarm

Server:
 Engine:
  Version:      18.03.0-ce
  API version:  1.37 (minimum version 1.12)
  Go version:   go1.9.4
  Git commit:   0520e24
  Built:        Wed Mar 21 23:08:10 2018
  OS/Arch:      linux/arm64
  Experimental: false
```

**Create a Docker Hub account**

Please create an account on **[Docker Hub](https://hub.docker.com/)** where you'll store your Docker container images.

**Login to Docker Hub** 
 
```shell
docker login
```

Please provide your Docker Hub Username and Password.

## Install Docker Compose
Please replace [Docker Hub Username] with your Docker Hub Username. 

```shell
wget https://github.com/docker/compose/archive/1.20.1.tar.gz
tar -xvf 1.20.1.tar.gz
cd compose-1.20.1
cp Dockerfile.armhf Dockerfile.arm64v8
sed -i "s|FROM armhf/debian:wheezy|FROM debian:buster-slim|" Dockerfile.arm64v8
sed -i "s|stable/armhf/docker-17.12.0|edge/aarch64/docker-18.03.0|" Dockerfile.arm64v8
docker build -t [Docker Hub Username]/compose:arm64v8-1.20.1 -f Dockerfile.arm64v8 .
docker push [Docker Hub Username]/compose:arm64v8-1.20.1
```

**Test**
Please replace [Docker Hub Username] with your Docker Hub Username.

```shell
docker run -ti [Docker Hub Username]/compose:arm64v8-1.20.1 --version
```

**Output**

```shell
docker-compose version 1.20.1, build unknown
```

**Add alias for convenience**
Please replace [Docker Hub Username] with your Docker Hub Username.

```shell
echo "alias docker-compose='docker run -ti [Docker Hub Username]/compose:arm64v8-1.20.1'" >> ~/.bashrc
source ~/.bashrc 
```

**Test**

```shell
docker-compose --version
```

**Output**

```shell
docker-compose version 1.20.1, build unknown
```

## Install Portainer
**[Portainer](https://portainer.io/)** is an open-source lightweight management UI which allows you to easily manage your docker hosts or swarm clusters.

**On Linux**
```shell
docker volume create portainer_data
docker run -d -p 9000:9000 --restart always -v /var/run/docker.sock:/var/run/docker.sock -v /opt/portainer:/data --name portainer portainer/portainer
```

**On Windows**
```shell
docker volume create portainer_data
docker run -d -p 9000:9000 --restart always -v C:\ProgramData\Portainer:C:\data --name portainer portainer/portainer
```

Please refer to **[this](https://www.techrepublic.com/article/how-to-install-and-use-portainer-for-easy-docker-container-management/)** guide for more details.

## Conclusion
Well that's it folks. Now you are empowered to usher in great IoT, IoMT and IoMBT applications and change the World!

To be continued.
