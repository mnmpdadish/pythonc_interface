#include "Python.h"
#include <stdio.h>

int sortList(int * list, int N) {
  int tmp,i,j;
  for(i=0; i<N; i++) 
    for(j=0;j<N-1;j++)
      if(list[j]<list[j+1])
        {
          tmp=list[j+1];
          list[j+1]=list[j];
          list[j]=tmp;
        }
  return 0;
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

    for(i=0; i<N; i++)
    { 
        listElement = PyList_GetItem(myList, i); 
        list1[i] = PyInt_AsLong(listElement); 
    }

    sortList(list1,N);
    PyObject *ResultList = PyList_New(N);
    for(i=0; i<N; i++)
    {
        listElement = PyInt_FromLong(list1[i]);
        PyList_SetItem(ResultList, i, listElement); 
    }

    return Py_BuildValue("O", ResultList);
} 

static PyMethodDef methods[] = {
  { "method", method_PythonWrapper, METH_VARARGS, "" },
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initsortList(void) {
    (void) Py_InitModule("sortList", methods);
}


