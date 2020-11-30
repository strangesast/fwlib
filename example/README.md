# Fanuc fwlib example
An example that connects to a machine specified by configuration options (file / env / arg)  
Usage (all args are optional):  
```
./bin/fanuc_example --config=<path_to_config> --port=<device port> --ip=<device ip>
```

# Docker Instructions
From the `example/` directory: `docker run --rm --network=host -it $(docker build -f Dockerfile ..)`

# Manual Instructions
0. Install fwlib32 (`install.sh` may work) and `libconfig-dev`
1. `mkdir build && cd build`
2. `cmake ..`
3. `make`
4. `make test`

# Windows
Compiling with Fwlib32 instead of Fwlib64 requires passing `-A Win32` to cmake.
1. `mkdir build` and `cd build`  
2. `cmake -A Win32 ..`  
3. `cmake --build .`  

The example is configured for 32bit compilation on x64 systems. More work is
required for CMake to detect the environment and configure itself properly on
arm, for example.

# Development / Debug
Copy `compile_commands.json` from build dir to use with IDE
