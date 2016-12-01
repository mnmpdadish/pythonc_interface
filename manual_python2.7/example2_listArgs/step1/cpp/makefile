
linux:
	g++ -O2 -fPIC -shared -Wl,-Bsymbolic-functions -I/usr/include/python2.7 -o maxList.so example2.cpp

mac:
	g++ -O2 -fPIC -shared -lpython -o maxList.so example2.cpp

alternative:
	python setup.py build_ext --inplace -f
	rm -r build

all:
	linux


