
linux:
	gcc -O2 -fPIC -shared -Wl,-Bsymbolic-functions -I/usr/include/python3.2mu -o hello.so example1.c

mac1:
	gcc -O2 -fPIC -shared -lpython -o hello.so example1.c

mac2:
	clang -O2 -fPIC -shared -lpython -o hello.so example1.c

mac3:
	gcc -O2 -fPIC -shared -lpython3.5m -o hello.so example1.c

mac4:
	clang -O2 -fPIC -shared -lpython3.5m -o hello.so example1.c

alternative1:
	python3 setup.py build_ext --inplace -f
	rm -r build

alternative2:
	python setup.py build_ext --inplace -f
	rm -r build

all:
	linux

