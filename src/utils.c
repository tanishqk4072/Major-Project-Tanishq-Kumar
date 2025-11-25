#include "utils.h"
#include <stdio.h>
#include <math.h>

double det2(double a,double b,double c,double d){
    return a*d - b*c;
}

double det3(double A[3][3]){
    return A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])
         - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
         + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
}

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

int solve3(){
    double A[3][3], b[3];

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (scanf("%lf",&A[i][j])!=1) return 0;

    for (int i=0;i<3;i++)
        if (scanf("%lf",&b[i])!=1) return 0;

    double D = det3(A);
    if (fabs(D) < 1e-12){
        printf("No unique solution (det=0).\n");
        return 1;
    }

    double Mx[3][3], My[3][3], Mz[3][3];
    for (int i=0;i<3;i++){
        Mx[i][0]=b[i];  Mx[i][1]=A[i][1]; Mx[i][2]=A[i][2];
        My[i][0]=A[i][0]; My[i][1]=b[i];  My[i][2]=A[i][2];
        Mz[i][0]=A[i][0]; Mz[i][1]=A[i][1]; Mz[i][2]=b[i];
    }

    double Dx = det3(Mx);
    double Dy = det3(My);
    double Dz = det3(Mz);

    printf("x = %.10g, y = %.10g, z = %.10g\n", Dx/D, Dy/D, Dz/D);
    return 1;
}
