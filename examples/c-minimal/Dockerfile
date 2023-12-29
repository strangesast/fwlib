from debian

#run apt-get update && apt-get install -y build-essential gcc-multilib g++-multilib
run apt-get update && apt-get install -y build-essential

#run apt-get update && \
#  DEBIAN_FRONTEND=noninteractive apt-get install -y \
#    g++-arm-linux-gnueabihf \
#    gcc-arm-linux-gnueabihf

workdir /usr/src/app
copy . .

#run ln -s libfwlib32-linux-armv7.so.1.0.5 libfwlib32.so && \
#  ln -s libfwlib32-linux-armv7.so.1.0.5 libfwlib32.so.1 && \
#  ln -s libfwlib32-linux-armv7.so.1.0.5 libfwlib32.so.1.0.5 && \
#  arm-linux-gnueabihf-gcc -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -lpthread -o fanuc_minimal

#env QEMU_LD_PREFIX=/usr/arm-linux-gnueabihf
#cmd ["/usr/src/app/fanuc_minimal"]

#copy . .

#run \
#  ln -s libfwlib32-linux-x86.so.1.0.0 libfwlib32.so && \
#  ln -s libfwlib32-linux-x86.so.1.0.0 libfwlib32.so.1 && \
#  ln -s libfwlib32-linux-x86.so.1.0.0 libfwlib32.so.1.0.0 && \
#  g++ -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -m32 -lpthread -o fanuc_minimal

run \
  ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so && \
  ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so.1 && \
  ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so.1.0.0 && \
  g++ -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -lpthread -o fanuc_minimal


cmd ["/usr/src/app/fanuc_minimal"]
