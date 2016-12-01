from distutils.core import setup, Extension

extension_mod = Extension(name="maxList",sources=["example2.c"])
setup(name = "maxList", ext_modules=[extension_mod])
