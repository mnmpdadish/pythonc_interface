
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cuba.h"

static int Integrand(const int *ndim, const double xx[],
  const int *ncomp, double ff[], void *userdata) {

  double mux=0.41234, muy=0.41234, sig=0.05;
  double Dx=xx[0]-mux, Dy=xx[1]-muy;
  double A = 1.0/(2*M_PI*sig*sig);
  ff[0] = 0.25*M_PI*M_PI*sin(xx[0]*M_PI)*sin(xx[1]*M_PI);
  ff[1] = A*exp(-(Dx*Dx+Dy*Dy)/(2*sig*sig) );
  return 0;
}

int main() {
  int NDIM=2, NCOMP=2;
  int MINEVAL=3000, MAXEVAL=3000000;
  double epsRel=0.001, epsAbs=0.0001;
  
  int comp, nregions, neval, fail;
  double integral[NCOMP], error[NCOMP], prob[NCOMP];
  
  Cuhre(NDIM, NCOMP, Integrand, NULL, 1, epsRel, epsAbs, 
        0, MINEVAL, MAXEVAL, 0, NULL, NULL,
        &nregions, &neval, &fail, integral, error, prob);

  printf("\nResult:\nsin2D=      %f +/- %e\ngaussian2D= %f +/- %e\nneval: %d\n",
          integral[0], error[0], integral[1], error[1],neval);
  
  return 0;
}

