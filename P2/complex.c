#include <stdlib.h>
#include <math.h>
#include "complex.h"

/*------------------------------------------------------------------------------
|                          Function Implementation                             |
------------------------------------------------------------------------------*/
PComplex newComplex(double x,double y){
    PComplex z =(PComplex)malloc(sizeof(Complex));
    X(z)=x; Y(z)=y;
    return z;
}
PComplex addComplex(PComplex a,PComplex b){
    return newComplex(X(a)+X(b), Y(a)+Y(b));
}
PComplex subComplex(PComplex a,PComplex b){
    return newComplex(X(a)-X(b), Y(a)-Y(b));
}
PComplex mulPComplex(PComplex a,PComplex b){
    return newComplex(X(a)*X(b) -Y(a)*Y(b), X(a)*Y(b)+Y(a)*X(b));
}
PComplex divComplex(PComplex a, PComplex b){
    return newComplex(X(a)*X(b) +Y(a)*Y(b), X(a)*Y(b)-Y(a)*X(b));
}
PComplex conjComplex(PComplex);
double modComplex(PComplex);
double argComplex(PComplex);
double realComplex(PComplex a){
    return X(a);
}
double imaginaryComplex(PComplex a){
    return Y(a);
}
