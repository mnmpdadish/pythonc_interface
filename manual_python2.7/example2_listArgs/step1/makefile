
linux:
	gcc -O2 -fPIC -shared -Wl,-Bsymbolic-functions -I/usr/include/python2.7 -o maxList.so example2.c

mac:
	gcc -O2 -fPIC -shared -lpython -o maxList.so example2.c

alternative:
	python setup.py build_ext --inplace -f
	rm -r build

all:
	linux


