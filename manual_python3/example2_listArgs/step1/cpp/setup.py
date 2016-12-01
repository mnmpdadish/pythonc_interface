from distutils.core import setup, Extension

import os
os.environ["CC"] = "g++"

extension_mod = Extension(name="maxList",sources=["example2.cpp"])
setup(name = "maxList", ext_modules=[extension_mod])
