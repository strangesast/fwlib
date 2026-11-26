from python as builder

copy libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/
run ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so && \
    ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so.1 && \
    ldconfig

run python -m pip install setuptools

workdir /usr/src/fwlib-python-c-extension
copy ./examples/python-c-extension/fwlib.c ./examples/python-c-extension/setup.py ./fwlib32.h ./

run python setup.py bdist_wheel

# regression tests against a stub of the library (no CNC needed):
#   docker build --target test -f examples/python-c-extension/Dockerfile .
from python as test

run python -m pip install setuptools

workdir /usr/src/fwlib-python-c-extension
copy ./examples/python-c-extension/tests/stub_fwlib.c ./tests/
run gcc -shared -fPIC -O2 -Wall -o /usr/local/lib/libfwlib32.so tests/stub_fwlib.c &&     ldconfig

copy ./examples/python-c-extension/fwlib.c ./examples/python-c-extension/setup.py ./fwlib32.h ./
copy ./examples/python-c-extension/tests/test_lifecycle.py ./tests/
run python setup.py build_ext --inplace &&     PYTHONPATH=. python tests/test_lifecycle.py

from python:slim

copy libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/
run ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so && \
    ln -s /usr/local/lib/libfwlib32-linux-x64.so.1.0.5 /usr/local/lib/libfwlib32.so.1 && \
    ldconfig

workdir /app

copy --from=builder /usr/src/fwlib-python-c-extension/dist/*.whl /app/

run pip install /app/*.whl && rm /app/*.whl

copy ./examples/python-c-extension/main.py ./
