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
    if(!PyArg_ParseTuple(args, "id", &i, &d )) 
        return NULL;
    return Py_BuildValue("i", i+(int)d );
}

static PyMethodDef methods[] = {
  { "method", main_PythonWrapper, METH_VARARGS, "" },
  {NULL, NULL, 0, NULL}
};


#ifndef python3
PyMODINIT_FUNC inithello(void) {
    (void) Py_InitModule("hello", methods);
}

#else

static struct PyModuleDef moduledef = {PyModuleDef_HEAD_INIT,"hello",NULL,-1,methods};

PyMODINIT_FUNC inithello(void) {
    PyModule_Create(&moduledef);
}
#endif


