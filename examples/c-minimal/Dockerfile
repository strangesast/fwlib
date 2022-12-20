from gcc
#from debian

#run apt-get update && apt-get install -y gcc-arm-linux-gnueabihf && rm -rf /var/lib/apt/lists/*


workdir /usr/src/app
copy . .

run ln -s libfwlib32-linux-armv7.so.1.0.5 libfwlib32.so && \
  ln -s libfwlib32-linux-armv7.so.1.0.5 libfwlib32.so.1 && \
  ln -s libfwlib32-linux-armv7.so.1.0.5 libfwlib32.so.1.0.5 && \
  # arm-linux-gnueabihf-gcc -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -lpthread -o fanuc_minimal
  gcc -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -lpthread -o fanuc_minimal

cmd ./fanuc_minimal
