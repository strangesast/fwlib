from setuptools import setup, Extension

module = Extension(
    "fwlib",
    sources=["fwlib.c"],
    libraries=["fwlib32"],
)

setup(
    name="fwlib",
    version="1.0",
    description="",
    ext_modules=[module],
)
