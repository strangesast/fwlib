# Fanuc fwlib example
![CMake](https://github.com/strangesast/fwlib/workflows/CMake/badge.svg)
![Windows CMake](https://github.com/strangesast/fwlib/workflows/Windows%20CMake/badge.svg)  
An example that connects to a machine specified by configuration options (file / env / arg)  
Usage (all args are optional):  
```
./bin/fanuc_example --config=<path_to_config> --port=<device port> --ip=<device ip>
```

**Notice:** This example requires fetching submodules first (`git submodule update --init --recursive`)  

# Docker (Linux containers)
From the root of this repository:
```
docker build -t fwlib_c-example -f examples/c/Dockerfile .
docker run --rm --network=host -it fwlib_c-example
```

# Linux
1. Copy `libfwlib32-linux-$arch.so.$version` to `/usr/local/lib` then run `ldconfig`.  Install config with `apt install libconfig-dev` or compile manually.  
2. `mkdir build && cd build`  
3. `cmake ..`  
4. `cmake --build .`  
5. `ctest -V`  

# Windows
1. Compile libconfig in `extern/libconfig/build` with `cmake -A Win32 ..` and `cmake --build . --config Release`  
2. `cmake -E make_directory build`  
3. `cd build`  
4. `cmake -A Win32 ..`  
5. `cmake --build .`  
6. `.\bin\fanuc_example.exe` (Fwlib32.dll may need to be moved to cwd)  

# Development / Debug
Copy `compile_commands.json` from build dir to use with IDE  
