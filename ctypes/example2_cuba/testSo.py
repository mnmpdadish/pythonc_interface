from ctypes import cdll, c_int, c_double

i = c_int(3)
d = c_double(4)

hello = cdll.LoadLibrary('./exampleCuba.so')
result = hello.main(i,d)  

print result
