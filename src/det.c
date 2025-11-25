#include <math.h>
#include "det.h"

double det2(double a,double b,double c,double d){
    return a*d - b*c;
}

double det3(double A[3][3]){
    return A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])
         - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
         + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
}
