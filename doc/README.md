# Installation guide
This guide explains how to compile llama.cpp builds b10405, b5050, and b3233 on a Nintendo Switch running Ubuntu.

## Prereqeuisites

* An **RCM vulnerable** or **modchipped** Switch ([see](https://switch.hacks.guide/user_guide/getting_started)). 
* Ubuntu 24,22,18. Any Ubuntu version will work ([Linux installation guide](https://wiki.switchroot.org/wiki/linux)).
* BSP (Board Support Package) updated to `32.7.4` ([BSP update guide](bsp.md)).
* CUDA 10.2 installed and patched on your Switch ([CUDA 10.2 Installation guide](cuda.md)).
* gcc 8.5 and cmake 3.28.6 ([Toolchain installation](toolchain.md)).
* (**Not** required, but highly recommended) Useful tools ([Useful tools](useful_tools.md))

## Building

You have two options, clone the llama.cpp repo and apply the patches to that repo, or clone my repo branch with all the patches already applied.

### 1 A. From llama.cpp repo

#### 1. Clone `llama.cpp` repository and this repo for the patches

`llama.cpp` repo
```bash
git clone https://github.com/ggml-org/llama.cpp.git
``` 
`llama.cpp-nx-guide` repo
```bash
git clone https://github.com/androrho/llama.cpp-nx-guide.git
```

and `cd` into llama.cpp repo:

```bash
cd llama.cpp
```

#### 2. Checkout the desired build

The tested builds are `b10405`, `b5050`, and `b3233`. So select one of those and checkout it.

```bash
git checkout b10405
```

#### 3. Apply the patches to the build

* Apply the patches to the `llama.cpp` build, patches for b10405 are only for build b10405, same with build b5050.

```bash
git apply ../llama.cpp-nx-guide/patch/llama.cpp-b10405-nx.patch
```
> Note: There's no need to apply any patches  to build b3233, as it is the latest one that doesn't require any patches.
### 1 B. From my llama.cpp fork

#### 1. Clone my llama.cpp fork

```bash
git clone https://github.com/androrho/llama.cpp-nx.git
```

And cd into it
```bash
cd llama.cpp-nx
```

#### 2. Switch to the branch/tag with the patches

* b10405 `git switch b10405-nx`
* b5050 `git switch b5050-nx`
* b3233 `git checkout b3233`

### 2. Compile

```bash
rm -rf build
cmake -B build \
    -DGGML_CUDA=on \
    -DCMAKE_CUDA_COMPILER=/usr/local/cuda/bin/nvcc \
    -DCMAKE_CUDA_ARCHITECTURES=53 \
    -DCMAKE_CUDA_STANDARD=14 \
    -DCMAKE_CUDA_STANDARD_REQUIRED=true \
    -DGGML_NATIVE=off \
    -DGGML_CPU_ARM_ARCH=armv8-a \
    -DCMAKE_C_COMPILER=/usr/local/gcc-8.5/bin/gcc \
    -DCMAKE_CXX_COMPILER=/usr/local/gcc-8.5/bin/g++ \
    -DCMAKE_CUDA_HOST_COMPILER=/usr/local/gcc-8.5/bin/g++ \
    -DCMAKE_C_FLAGS="-w" -DCMAKE_CXX_FLAGS="-w" -DCMAKE_CUDA_FLAGS="-w"
cmake --build build --config Release -j$(nproc)
```
`llama.cpp` binaries should be under `build/bin`

>Note: If you installed gcc in a different path you have to change the `C_COMPILER`, `CXX_COMPILER` and `CUDA_HOST_COMPILER` paths.
## Precompiled
If you don't want to compile `llama.cpp` and want a premade thing you can download it already precompiled with all the pathes from the [releases tab](https://github.com/androrho/llama.cpp-nx-guide/releases).   

`llama.cpp` binaries should be under `build/bin`.


>Note: if you download it precompiled, it comes the source code witch the patches and the build, all together.
