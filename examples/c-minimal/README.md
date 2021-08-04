# Instructions

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
