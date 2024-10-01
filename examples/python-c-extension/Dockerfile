from python as builder

copy libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/
run ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so && \
    ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so.1 && \
    ldconfig

run python -m pip install setuptools

workdir /usr/src/fwlib-python-c-extension
copy ./examples/python-c-extension/fwlib.c ./examples/python-c-extension/setup.py ./fwlib32.h ./

run python setup.py bdist_wheel

from python:slim

copy libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/
run ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so && \
    ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so.1 && \
    ldconfig

workdir /app

copy --from=builder /usr/src/fwlib-python-c-extension/dist/*.whl /app/

run pip install /app/*.whl && rm /app/*.whl

copy ./examples/python-c-extension/main.py ./
