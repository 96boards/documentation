---
title: Setup SSH
permalink: /documentation/consumer/dragonboard820c/guides/setup-ssh.md.html
redirect_from:

---
# Setup SSH

## Add SSH keys
Please follow [these](https://www.ssh.com/ssh/putty/windows/puttygen) instructions to generate SSH private and public keys with PuttyGen on Windows.
To be able to access the board via SSH properly we copy generated SSH private and public keys.

This process will be updated as soon as the **[OpenSSH for Windows 10](https://blogs.msdn.microsoft.com/powershell/2017/12/15/using-the-openssh-beta-in-windows-10-fall-creators-update-and-windows-server-1709/)** (currently in beta) will be released. We should be able to use ```ssh-copy-id``` that currently returns an cryptic ```exec request failed on channel 0``` error.

```shell
mkdir .ssh
cd .ssh
```

**Copy Private Key**
Fire up your favorite editor (nano) and copy the the content of id_rsa (private key).
 
```shell
nano id_rsa
```

**Copy Public Key**
Copy the the content of id_rsa.pub (public key).

```shell
nano id_rsa.pub
```

**Copy Public Key**
Copy the the content of authorized_keys.

```shell
nano authorized_keys
```

**Make these keys available for linaro and [new username]**

```shell
cd ..
cp -r .ssh /home/linaro/
cp -r .ssh /home/[new username]/
```

**Update ```/etc/ssh/sshd_config``` to enable SSH and X11 windowing system for root and members of the ssh group that linaro and [new username] are member of.** 

```shell
sed -i 's/#PasswordAuthentication yes/PasswordAuthentication no/' /etc/ssh/sshd_config
sed -i 's/UsePAM yes/UsePAM no/' /etc/ssh/sshd_config
sed -i 's/#PermitRootLogin/PermitRootLogin/' /etc/ssh/sshd_config
sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
sed -i 's/#X11DisplayOffset/X11DisplayOffset/' /etc/ssh/sshd_config
echo "" >> /etc/ssh/sshd_config
echo "# SSH ACL" >> /etc/ssh/sshd_config
echo "AllowGroups ssh" >> /etc/ssh/sshd_config
sudo systemctl enable ssh
```

Reboot

```shell
reboot
```

## Login to DragonBoard 820c via SSH
On windows 10 start Putty. Please refer to the **1.3.2.2 For PC with Windows 10** chapter of the [DB410c Major League Hack Quick Start Guide](https://developer.qualcomm.com/download/db410c/mlh-quick-start-guide.pdf) for more details.
