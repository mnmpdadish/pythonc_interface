from distutils.core import setup, Extension

extension_mod = Extension(name="hello",sources=["example1.c"])
setup(name = "hello.so", ext_modules=[extension_mod])
