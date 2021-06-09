# README

Main programmer:  Maxime Charlebois


# MAIN REPOSITORY:

To get the most recent version of the source code of this project,
in command line on a bash terminal (represented here with the "$" sign), type:

```
$ hg clone https://bitbucket.org/mnmpdadish/pythonc_interface
```

# DEPENDENCIES:

gcc, any version should be sufficient. Tested with gcc-4.8.
python2.7 and/or python3+, depending on your preference.

Examples 2 and 3 of the ctypes approach require the cuba library 
(obtained at http://www.feynarts.de/cuba/).


# DESCRIPTION:

This repository want to be a tutorial on how to interface 
python with C/C++, although there is only one example with C++.

I present two approaches:
1. "ctypes" refers to the module called ctypes, 
   a very simple and straighforward approach.
2. "manual" refers to the way to code your python extension yourself,
   as described at https://docs.python.org/2/extending/extending.html
   Note that there is small differences for this approach between 
   python2.7 and 3+, hence a different directory for each version.
   You can easily check for the difference using (for example):
```
vimdiff manual_python2.7/example2_listArgs/example2.c manual_python3/example2_listArgs/example2.c
```

Every directory contains a simple functionning example.

# EXAMPLES: 

Every sub-directory is a standalone example. The source codes are
the tutorial. They are very basic and produce a very simple output.
Since no documentation other than the code themself is present,
it is suggested for any reader to visit each example, compile
it, run it and inspect the output. The codes are minimal 
working examples (MWE) that can produce these output using a 
compiled module.

# COMPILING: 

Compile with "make". The shared object ".so" library will then 
be created in the directory and python will be able to call it.

# RUN: 

To run, type "python testSo.py". 

If someone wants to move the ".so" library away from the working
directory, he must update some environment variable with these commands:

for ctypes:
LD_LIBRARY_PATH=/absolute/path/to/your/so:$LD_LIBRARY_PATH

for manual:
PYTHONPATH=/absolute/path/to/your/so:$PYTHONPATH



# #######

Tested on Linux Ubuntu LTS 12.04 and 16.04

