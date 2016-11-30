
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cuba.h"

typedef struct{
  int n_elements;
  double *mux_list;
  double *muy_list;
} Parameters;

static int Integrand(const int *ndim, const double xx[],
  const int *ncomp, double ff[], void *userdata) {

  Parameters params = *((Parameters*)userdata);
  double sig=0.05, A = 1.0/(2*M_PI*sig*sig);
  
  int i;
  for(i=0; i<params.n_elements; i++){
    double Dx=xx[0]-params.mux_list[i];
    double Dy=xx[1]-params.muy_list[i];
    ff[i] = A*exp(-(Dx*Dx+Dy*Dy)/(2*sig*sig) );
  }
  return 0;
}

int method(int in_ncomp, double *in_muxList, double *in_muyList, 
                         double *out_integral, double *out_error) {
  int NDIM=2;
  int MINEVAL=3000, MAXEVAL=3000000;
  double epsRel=0.001, epsAbs=0.0001;
  
  Parameters params;
  params.n_elements = in_ncomp;
  params.mux_list = in_muxList;
  params.muy_list = in_muyList;

  int nregions, neval, fail;
  double /*integral[NCOMP], error[NCOMP],*/ prob[in_ncomp];
  
  Cuhre(NDIM, in_ncomp, Integrand, &params, 1, epsRel, epsAbs, 
        0, MINEVAL, MAXEVAL, 0, NULL, NULL,
        &nregions, &neval, &fail, out_integral, out_error, prob);
  
  return neval;
}

