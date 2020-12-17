ARG image=debian:buster-slim
FROM ${image}

WORKDIR /tmp/
COPY libfwlib32* fwlib32.h scripts/install.sh ./

RUN ./install.sh
