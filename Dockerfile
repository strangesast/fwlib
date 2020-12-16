arg image=debian:buster-slim
from ${image}
#from debian:buster-slim
#from python:3-slim-buster

workdir /tmp/
copy libfwlib32* fwlib32.h install.sh ./

run ./install.sh
