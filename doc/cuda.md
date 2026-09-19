# CUDA 10.2 installation and patching guide

This guide explains how to install and patch CUDA 10.2 to compile llama.cpp-nx.

## Prerequisites

* BSP (Board Support Package) updated to `32.7.4` ([BSP update guide](bsp.md)).
* `curl`, `git` and `libssl-dev` installed.
```bash
sudo apt install curl git libssl-dev
```

## 1. Add nvidia repo to apt (Ubuntu 24 & 22 only)

* Import gpg key for the nvidia repos
```bash
sudo mkdir -p /etc/apt/trusted.gpg.d
curl -fsSL https://repo.download.nvidia.com/jetson/jetson-ota-public.asc | sudo gpg --dearmor -o /etc/apt/trusted.gpg.d/nvidia-jetson.gpg
```

* Add the repos
```bash
echo "deb https://repo.download.nvidia.com/jetson/common r32.7 main
deb https://repo.download.nvidia.com/jetson/t210 r32.7 main" | sudo tee /etc/apt/sources.list.d/nvidia-l4t-source.list
```

>Note: These steps are only for Ubuntu 24 and Ubuntu 22, so if you have Ubuntu 18 installed, skip these steps and go to the Install CUDA 10.2 section.
## 2. Install CUDA 10.2

* Update apt sources and install CUDA 10.2
```bash
sudo apt update && sudo apt install cuda-toolkit-10-2 -y
```

* Then add CUDA 10.2 to path
```bash
cat << 'EOF' >> ~/.bashrc

export PATH=/usr/local/cuda-13.4/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-13.4/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
EOF
```

* Apply the changes
```bash
source ~/.bashrc
```

> Note: Install only the cuda-toolkit-10-2 package from the nvidia repos.
## 3. Patch CUDA 10.2

First of all, clone this repo to obtain the `cuda_bf16.h`, `cuda_bf16.hpp` and `reduce.h` files.

```bash
git clone https://github.com/androrho/llama.cpp-nx-guide
```

Files are under the `llama.cpp-nx-guide/patches` folder.

Then we have to paste the following files to the `/usr/local/cuda-10-2/include` folder.

`cuda_bf16.h` and `cuda_bf16.hpp`
```bash
sudo cp llama.cpp-nx-guide/patch/cuda_bf16.h /usr/local/cuda-10.2/include/cuda_bf16.h
sudo cp llama.cpp-nx-guide/patch/cuda_bf16.hpp /usr/local/cuda-10.2/include/cuda_bf16.hpp
```
`reduce.h`

```bash
# Create the cooperative_groups folder
sudo mkdir /usr/local/cuda-10.2/include/cooperative_groups
# Copy the reduce.h file
sudo cp llama.cpp-nx-guide/patch/reduce.h /usr/local/cuda-10.2/include/cooperative_groups/reduce.h
```

>Note: remember to copy the files as sudo, as only root has the permission to write under the `cuda-10-2` folder
