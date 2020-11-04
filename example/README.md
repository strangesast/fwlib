# Fanuc fwlib example
An example that connects to a machine specified by MACHINE_IP & MACHINE_PORT in `main.c`

# Docker Instructions
From the `example/` directory: `docker run --rm --network=host -it $(docker build -f Dockerfile ..)`

# Manual Instructions
0. Install fwlib32 (`install.sh` may work) and `libconfig-dev`
1. `mkdir build && cd build`
2. `cmake ..`
3. `make`
4. `make test`

The example is configured for 32bit compilation on x64 systems. More work is
required for CMake to detect the environment and configure itself properly on
arm, for example.
