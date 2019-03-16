#ifndef COMPLEX_H
#define COMPLEX_H
/*
 * A complex numer z is defined by z=a+bi, where a is its real portion
 *    and b its imaginary portion
 */

/*------------------------------------------------------------------------------
|                           Macro Defenition                                   |
------------------------------------------------------------------------------*/
#define X(P) ((P)->x)
#define Y(P) ((P)->y)

/*------------------------------------------------------------------------------
|                           Complex Defenition                                 |
------------------------------------------------------------------------------*/
typedef struct complex{
    double x;                                     //Real portion of complex
    double y;                                     //Imaginary portion of complex
}Complex,*PComplex;


/*------------------------------------------------------------------------------
|                          Function Defenition                                 |
------------------------------------------------------------------------------*/
PComplex newComplex(double,double);
PComplex addComplex(PComplex,PComplex);
PComplex subComplex(PComplex,PComplex);
PComplex mulPComplex(PComplex,PComplex);
PComplex divComplex(PComplex, PComplex);
PComplex conjComplex(PComplex);
double modComplex(PComplex);
double argComplex(PComplex);
double realComplex(PComplex);
double imaginaryComplex(PComplex);


#endif
