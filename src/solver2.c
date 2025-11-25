#include <stdio.h>
#include <math.h>
#include "det.h"
#include "solver2.h"

int solve2(){
    double a,b,c,d, v1,v2;
    if (scanf("%lf %lf %lf %lf",&a,&b,&c,&d)!=4) return 0;
    if (scanf("%lf %lf",&v1,&v2)!=2) return 0;

    double D = det2(a,b,c,d);
    if (fabs(D) < 1e-12){
        printf("No unique solution (det=0).\n");
        return 1;
    }

    double Dx = det2(v1,b,v2,d);
    double Dy = det2(a,v1,c,v2);

    printf("x = %.10g, y = %.10g\n", Dx/D, Dy/D);
    return 1;
}
