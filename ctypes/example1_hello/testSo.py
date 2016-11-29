from ctypes import cdll 
from ctypes import c_int, c_double

hello = cdll.LoadLibrary \
            ('./hello.so')

i = c_int(3)
d = c_double(4)
result = hello.method(i,d)  

print result, '\n'












