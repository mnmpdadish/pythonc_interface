#include "Python.h"
#include <stdio.h>
#include <signal.h>

//
void interrupt_handler(int sig) {exit(0);}
//

static PyObject * theCountDown(
       PyObject *self, PyObject *args){
    //
    signal(SIGINT, interrupt_handler); 
    //
    int i=0;
    for(i=10;i>=0;i--){
        printf("%d\n",i);
        sleep(1);
    }
    Py_RETURN_NONE;
} 

static PyMethodDef methods[] = {
  { "doIt", theCountDown, METH_VARARGS, "" }
};

DL_EXPORT(void) initcountDown(void) {
    Py_InitModule("countDown", methods);
}


