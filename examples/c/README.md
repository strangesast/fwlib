# Fanuc fwlib example
![CMake](https://github.com/strangesast/fwlib/workflows/CMake/badge.svg)
![Windows CMake](https://github.com/strangesast/fwlib/workflows/Windows%20CMake/badge.svg)  
An example that connects to a machine specified by configuration options (file / env / arg)  
Usage (all args are optional):  
```
./bin/fanuc_example --config=<path_to_config> --port=<device port> --ip=<device ip>
```

# Docker
From the `example/` directory: `docker run --rm --network=host -it $(docker build -f Dockerfile -q ..)`  

# Linux
0. Copy `libfwlib32-linux-$arch.so.$version` to `/usr/local/lib` then run `ldconfig`.  Install config with `apt install libconfig-dev` or compile manually.  
1. `mkdir build && cd build`  
2. `cmake ..`  
3. `cmake --build .`  
4. `ctest -V`  

# Windows
0. Compile libconfig in `extern/libconfig/build` with `cmake -A Win32 ..` and `cmake --build . --config Release`  
1. `mkdir build` and `cd build`  
2. `cmake -A Win32 ..`  
3. `cmake --build .`  

# Development / Debug
Copy `compile_commands.json` from build dir to use with IDE  
