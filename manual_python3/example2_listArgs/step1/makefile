
#by default, make call the command line to run setup.py (more portable).
all: SETUPpy

SETUPpy:
	python3 setup.py build_ext --inplace -f
	rm -r build

linux:
	gcc -O2 -fPIC -shared -Wl,-Bsymbolic-functions -I/usr/include/python3.2mu -o maxList.so example2.c

mac:
	gcc -O2 -fPIC -shared -lpython -o maxList.so example2.c

