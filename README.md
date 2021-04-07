# Fanuc FOCAS Library
[![Docker Hub](https://img.shields.io/docker/v/strangesast/fwlib?sort=date)](https://hub.docker.com/r/strangesast/fwlib)  
Header and runtime files for CNC communication  

# Docker
Build the base image with `docker build .`  

Build an example with `docker build examples/c/Dockerfile`   

# `examples/`  
Link or rename appropriate `libfwlib\*.so` (based on platform) to `libfwlib32.so.1` and `libfwlib32.so` 

On linux x86\_64 for example: `ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so` 

More instructions in each example folder
