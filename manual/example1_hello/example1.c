#include "Python.h"
#include <stdio.h>

int main() {
  printf("Hello World.\n");
  return 0;
}

static PyObject * main_PythonWrapper(
       PyObject *self, PyObject *args){

    main();
    int i; double d;
    PyArg_ParseTuple(args, "id", &i, &d );
    return Py_BuildValue("i", i+(int)d );
}

static PyMethodDef methods[] = {
  { "method", main_PythonWrapper, METH_VARARGS, "" }
};

DL_EXPORT(void) inithello(void) {
    Py_InitModule("hello", methods);
}














