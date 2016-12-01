#include "Python.h"
#include <stdio.h>

int main(void) {
  printf("Hello World.\n");
  return 0;
}

static PyObject * main_PythonWrapper(
       PyObject *self, PyObject *args){

    main();
    int i; double d;
    if(!PyArg_ParseTuple(args, "id", &i, &d )) 
        return NULL;
    return Py_BuildValue("i", i+(int)d );
}

static PyMethodDef methods[] = {
  { "method", main_PythonWrapper, METH_VARARGS, "" },
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inithello(void) {
    (void) Py_InitModule("hello", methods);
}



