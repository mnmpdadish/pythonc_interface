from ctypes import cdll

hello = cdll.LoadLibrary \
            ('./hello.so')

result = hello.main()  

print result






