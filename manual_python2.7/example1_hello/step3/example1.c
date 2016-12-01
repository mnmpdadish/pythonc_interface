#include "Python.h"
#include <stdio.h>

int main(void) {
  printf("Hello World.\n");
  return 0;
}

static PyObject * main_PythonWrapper(
       PyObject *self, PyObject *args){
    
    main();
    return Py_BuildValue("i", 56);
}

static PyMethodDef methods[] = {
  { "method", main_PythonWrapper, METH_VARARGS, "" },
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inithello(void) {
    (void) Py_InitModule("hello", methods);
}



