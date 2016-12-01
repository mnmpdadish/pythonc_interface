from distutils.core import setup, Extension

extension_mod = Extension(name="sortList",sources=["example2.c"])
setup(name = "sortList", ext_modules=[extension_mod])
