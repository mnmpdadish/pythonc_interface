#include "Python.h"
#include <stdio.h>

static PyObject * theCountDown(
       PyObject *self, PyObject *args){
   
    int i=0;
    for(i=10;i>=0;i--){
        printf("%d\n",i);
        sleep(1);
        //uncomment this line for KeyboardInterrupts
        //if(PyErr_CheckSignals()) return NULL; 
    }
    Py_RETURN_NONE;
} 

static PyMethodDef methods[] = {
  { "doIt", theCountDown, METH_VARARGS, "" }
};

DL_EXPORT(void) initcountDown(void) {
    Py_InitModule("countDown", methods);
}


