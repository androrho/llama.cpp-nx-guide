# Toolchains installation

This guide explains how to install all the required toolchains to compile llama.cpp on Switch.  
Any Ubuntu version will suit for this.  
  
If you don't want to compile `cmake` and `gcc`, skip to the precompiled section.

## Prerequisites

* Install `build-essential` metapackage (yes, we need gcc to compile gcc).  
```bash
sudo apt install build-essential -y
```
* `cmake` completely uninstalled from our system.  
```bash
sudo apt remove cmake --purge -y
```

## Compile cmake from source
* Download `cmake` source code. 
```bash
wget https://cmake.org/files/v3.28/cmake-3.28.6.tar.gz
```
* Extract the source code and `cd` into it.
```bash
tar -xzvf cmake-3.28.6.tar.gz
cd cmake-3.28.6
```
* Build the source code. 
```bash
./bootstrap
make -j$(nproc)
```
* Install it.
```bash
sudo make install

```

## Compile gcc from source


* Download gcc-8.5 source code.
```bash
wget http://ftp.gnu.org/gnu/gcc/gcc-8.5.0/gcc-8.5.0.tar.gz
```
* Uncompress the source code and `cd` into it.
```bash
tar -xvzf gcc-8.5.0.tar.gz
cd gcc-8.5.0
```
* Download the prerequisites.
```bash
./contrib/download_prerequisites
```
* Compile the source code.
```bash
mkdir build && cd build
../configure --enable-languages=c,c++ --disable-multilib --prefix=/usr/local/gcc-8.5
make -j$(nproc)
```
* Install gcc.
```bash
sudo make install
```

> Note: if you follow this steps you will install gcc in the `/usr/local/gcc-8.5` folder, to change it, just replace that path in the `--prefix=/usr/local/gcc-8.5`.

## Precompiled

If you don't want to compile cmake and gcc because it takes a really long time, you can also download the precompiled version under the [releases](https://github.com/androrho/llama.cpp-nx-guide/releases) of this repo.
