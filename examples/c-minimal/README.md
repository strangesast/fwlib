# Instructions

## Docker
```
docker build --platform=linux/arm/v7 -f examples/c-minimal/docker/armv7/Dockerfile .
docker run --rm -it --platform=linux/amd64 $(docker build --platform=linux/amd64 -f examples/c-minimal/docker/x86/Dockerfile . -q)
```

## Linux
From the root of this repository:  
```
gcc -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -lpthread -o fanuc_minimal
./fanuc_minimal
```

## Windows
Requires Visual Studio or [Visual Studio Tools](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019)  
From the root of this repository:  
```
cl.exe /Fe"fanuc_minimal.exe" .\examples\c-minimal\main.c /link .\Fwlib32.lib
.\fanuc_minimal.exe
```
