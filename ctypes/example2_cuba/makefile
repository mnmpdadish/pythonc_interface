
#important: cuba must have been compiled with -fPIC option

all:
	gcc -O2 -fPIC -shared -Wl,-Bsymbolic-functions -I/usr/include/python2.7 -o exampleCuba.so example2.c -lcuba -lm

