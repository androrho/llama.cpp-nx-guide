# llama.cpp-nx-guide

llama.cpp with CUDA support on a Nintendo Switch running Ubuntu.

<div align="center">

[Build from source](https://github.com/androrho/llama.cpp-nx-guide/doc/README.md) / 
[Releases](https://github.com/androrho/llama.cpp-nx-guide) /
[llama.cpp-nx](https://github.com/androrho/llama.cpp-nx) /
[llama.cpp](https://github.com/ggml-org/llama.cpp) / 
[Credits](https://github.com/androrho/llama.cpp-nx-guide/Credits.md)

</div>

## Quick start

You can compile llama.cpp or download it prebuilt from the releases tab.  
* [Build from source](doc/README.md)
* Download from the [releases tab](https://github.com/androrho/llama.cpp-nx-guide/releases)

## Run a model

To run a model, just execute `llama-cli` and pass the model with the `-m` param.
```bash
./llama-cli -m <model-name> 
```

## Credits

* [llama.cpp-jetson](https://github.com/kreier/llama.cpp-jetson) by Matthias Kreier. This was the main guide used as an starting point and also to compare the performance.
* [Switch AI ✨](https://nocoffei.com/?p=352) by nocoffei. It was also a good resource to provide the source of the istructions to update CUDA to the latest compatible version with the Switch.
* [Setup Guide for llama.cpp on Nvidia Jetson Nano 2GB](https://gist.github.com/FlorSanders/2cf043f7161f52aa4b18fb3a1ab6022f) by FlorSanders Specially for the good idea about create a git patch file.
* [switchroot](https://switchroot.org/) Special thanks to them and to the switch homebrew community as this weren't be possible without your amazing work.
* [CTCaer](https://github.com/CTCaer) and [theofficialgman](https://github.com/theofficialgman) for providing the guide to update the BSP and all the amazing contributions to the switch homebrew community.
