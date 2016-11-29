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
        list1[i] = PyInt_AsLong(listElement); 
    }
    
    return Py_BuildValue("i", maxList(list1, N));
} 


static PyMethodDef methods[] = {
  { "method", method_PythonWrapper, METH_VARARGS, "" }
};

#ifdef __cplusplus
extern "C" {
#endif
    DL_EXPORT(void) initmaxList(void) {
        Py_InitModule("maxList", methods);
    }
#ifdef __cplusplus
}
#endif














