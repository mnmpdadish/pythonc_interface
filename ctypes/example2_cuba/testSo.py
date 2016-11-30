from ctypes import cdll 

hello = cdll.LoadLibrary('./exampleCuba.so')
result = hello.main()  

print 'OK.'
