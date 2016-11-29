#include "Python.h"
#include <stdio.h>

int main() {
  printf("Hello World.\n");
  return 0;
}

static PyObject * main_PythonWrapper(
       PyObject *self, PyObject *args){
    
    main();
    return Py_BuildValue("i", 56);
}

static PyMethodDef methods[] = {
  { "method", main_PythonWrapper, METH_VARARGS, "" }
};

DL_EXPORT(void) inithello(void) {
    Py_InitModule("hello", methods);
}



