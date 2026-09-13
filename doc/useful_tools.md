# Useful tools and configurations
Some useful tools or configurations will be explained in this guide as it could help with the llama.cpp compiling/running on Switch.

## ssh access
You can connect to your switch via ssh, so you don't have to connect a USB keyboard or type on the touchscreen.

* OpenSSH server installation
```bash
sudo apt install openssh-server -y
```

* Connect via ssh
```bash
ssh <username>@<ip_or_hostname>
```

## Kill the GUI
You can kill the gui to have some extra RAM to run heavier models or models with more context.

* Kill the GUI
```bash
sudo systemctl isolate multi-user.target
```
* Enable the GUI
```bash
sudo systemctl isolate graphical.target
```
> Note: This is specially useful while being connected to an ssh session.

## screen terminal multiplexor
It is handy tool while compiling because you can compile without warring about your ssh session disconnecting and the compile proccess stopping.

* Install `screen`
```bash
sudo apt install screen -y
```

* Start screen session
```bash
screen
```

* Deatach screen  
Hold `Ctrl+A`, release `Ctrl+A`, press `D`

* List screen sessions
```bash
screen -ls
```

* Atatch screen
```bash
screen -r <screen_name>
```

## btop, htop, top, ...
These are good tools to monitor the performance.

* Install `btop`
```bash
sudo apt install btop -y
```
