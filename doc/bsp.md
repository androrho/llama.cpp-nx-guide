# Update BSP
We have to update the BSP (Board Support Package) from version `32.3.1` to version `32.7.4`.   

This is one of the most important steps, because updating the BSP doesn't mean upgrading some random packages, it means upgrading the GPU drivers and other related software. It allows the compatibility wth newer APIs or toolkits like **Vulkan 1.2** or **CUDA 10.2**.  
> **Note:** If you skip this step and install only CUDA 10.2, `llama.cpp` may compile, but you won't be able to run it due to a runtime error.

## Ubuntu 24 (noble)
```bash
# VERY IMPORTANT, DO ALL STEPS AS WRITTEN
# update all installed packages
sudo apt update
sudo apt dist-upgrade

# add the support for the noble-32-7 dist
echo "deb [signed-by=/etc/apt/keyrings/theofficialgman-L4T.asc] https://theofficialgman.github.io/l4t-debs/ l4t noble-32-7" | sudo tee /etc/apt/sources.list.d/theofficialgman-L4T-32-7.list

# remove BSP version restrictions
sudo rm -f /etc/apt/preferences.d/00-switch-bsp-restrictions

# update and install new nvidia-bsp-32-7 meta package
sudo apt update
sudo apt install -y -o Dpkg::Options::="--force-confdef" nvidia-bsp-32-7
```

## Ubuntu 22 (jammy)
```bash
# VERY IMPORTANT, DO ALL STEPS AS WRITTEN
# update all installed packages
sudo apt update
sudo apt dist-upgrade

# add the support for the jammy-32-7 dist
echo "deb [signed-by=/etc/apt/keyrings/theofficialgman-L4T.asc] https://theofficialgman.github.io/l4t-debs/ l4t jammy-32-7" | sudo tee /etc/apt/sources.list.d/theofficialgman-L4T-32-7.list

# remove BSP version restrictions
sudo rm -f /etc/apt/preferences.d/00-switch-bsp-restrictions

# update and install new nvidia-bsp-32-7 meta package
sudo apt update
sudo apt install -y -o Dpkg::Options::="--force-confdef" nvidia-bsp-32-7
```

## Ubuntu 18 (bionic)
1. Remove the 32.7.x bsp restrictions in this file
```bash
sudo gedit /etc/apt/preferences.d/00-switch-bsp-restrictions
```

2. Change `r32` to `r32.7` in both places in this file
```bash
sudo gedit /etc/apt/sources.list.d/nvidia-l4t-apt-source.list
```

3. Create a few files to skip some stuff
```bash
sudo touch /etc/nv_boot_control.conf
sudo mkdir /opt/nvidia/l4t-packages
sudo touch /opt/nvidia/l4t-packages/.nv-l4t-disable-boot-fw-update-in-preinstall
```

4. apt update and upgrade  
when you get asked if you want to replace the files with the distro maintainers version, answer N each time
```bash
sudo apt update
sudo apt dist-upgrade
```

5. Before rebooting, add a `.reinit` file to the `sd:/switchroot/ubuntu/` folder on your sd card
**edit** the path below to match your mounted fat32 sd card partition or create that file via file manager
```bash
touch /media/$USER/{sd_card_fat32_name}/switchroot/ubuntu/.reinit
```

6. Reboot

-----

If **flatpak** is used, these extra steps **must** be followed:
A. If you already got the 32.3.1 BSP flatpaks via L4T-Megascript, you will need to manually remove them
```bash
sudo flatpak remove org.freedesktop.Platform.GL.nvidia-tegra-32-3-1
```
B. Remove this file and then run anything from the L4T-Megascript again to install 32.7.3 flatpak drivers
```bash
rm ~/L4T-Megascript/data/runonce_hashes
```

> **Note:** If you are connected via ssh, or you're simply not comfortable with `gedit`, you can use other editor like `nano` or `vim`.

## Source
This steps come from the pinned messages in the support channel for each distribution in the [Linux 4 Switch](https://discord.gg/53mtKYt) Discord server.
* Ubuntu 24: [Source](https://discord.com/channels/692020816241623081/1234626529892368415/1234627972770828369)
* Ubuntu 22: [Source](https://discord.com/channels/692020816241623081/1142160278595846286/1145916400809033851)
* Ubuntu 18: [Source](https://discord.com/channels/692020816241623081/697241533757390978/1202720701522378842)
