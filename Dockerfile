from debian:stretch-slim

workdir /tmp
copy libfwlib32* fwlib32.h install.sh ./

run ./install.sh
