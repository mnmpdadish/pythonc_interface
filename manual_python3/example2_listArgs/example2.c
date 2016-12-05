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
        list1[i] = PyLong_AsLong(listElement);  //note the difference with python2.7 here.
    }

    sortList(list1,N);
    PyObject *ResultList = PyList_New(N);
    for(i=0; i<N; i++)
    {
        listElement = PyLong_FromLong(list1[i]); //here too
        PyList_SetItem(ResultList, i, listElement); 
    }

    free(list1);
    return Py_BuildValue("O", ResultList);
} 

static PyMethodDef methods[] = {
  { "method", method_PythonWrapper, METH_VARARGS, "" },
  {NULL, NULL, 0, NULL}
};

struct PyModuleDef sortListModule =
  {PyModuleDef_HEAD_INIT, "sortList", NULL, -1,methods};

PyMODINIT_FUNC PyInit_sortList(void){
    return PyModule_Create(&sortListModule);
}





