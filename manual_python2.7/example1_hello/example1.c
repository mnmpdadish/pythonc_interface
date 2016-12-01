#include "Python.h"
#include <stdio.h>

int main0(void) { //some version of python do not like if we keep the main() function in the .so
  printf("Hello World.\n");
  return 0;
}

static PyObject * main_PythonWrapper(
       PyObject *self, PyObject *args){

    main0();
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



