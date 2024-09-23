from gcc as builder

copy libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/
run ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so && \
    ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so.1 && \
    ldconfig

workdir /usr/src/fwlib-c-minimal
run mkdir -p examples/c-minimal
copy fwlib32.h ./
copy examples/c-minimal/main.c ./examples/c-minimal/

run gcc -L./ -Wl,-rpath . examples/c-minimal/main.c -lfwlib32 -lm -lpthread -o fanuc_minimal


from debian:stable-slim

copy libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/
run ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so && \
    ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so.1 && \
    ldconfig

copy --from=builder /usr/src/fwlib-c-minimal/fanuc_minimal /

cmd ["/fanuc_minimal"]
