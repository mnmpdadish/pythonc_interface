#include "Python.h"
#include <stdio.h>

int maxList(int * list, int N) {
  int max = list[0];
  int i=0;
  for(i=1; i<N; i++) if(max<list[i]) max = list[i];
  return max;
}

static PyObject * method_PythonWrapper(
       PyObject *self, PyObject *args){

    PyObject *myList;
    PyObject *listElement;
    if(!PyArg_ParseTuple(args, "O", &myList)) {
        return NULL;
    }

    Py_ssize_t i=0, N = PyList_Size(myList);
    int * list1; 
    list1 = (int *) malloc(N*sizeof(int));

    for(i=0; i<N; i++){ 
        listElement = PyList_GetItem(myList, i); 
        list1[i] = PyLong_AsLong(listElement);  // difference with python2.7
    }

    free(list1);    
    return Py_BuildValue("i", maxList(list1, N));
} 

static PyMethodDef methods[] = {
  { "method", method_PythonWrapper, METH_VARARGS, "" },
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef maxListModule =
  {PyModuleDef_HEAD_INIT, "maxListModule", NULL, -1,methods};

PyMODINIT_FUNC PyInit_maxList(void){
    return PyModule_Create(&maxListModule);
}


