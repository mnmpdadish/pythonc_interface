from distutils.core import setup, Extension

extension_mod = Extension(name="countDown",sources=["example3.c"])
setup(name = "countDown", ext_modules=[extension_mod])
