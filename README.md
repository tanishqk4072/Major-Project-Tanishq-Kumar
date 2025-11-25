PROJECT DESCRIPTION AND INTRODUCTION



C programming Project 


PROJECT REPORT


Project title:-MATRIX SOLVER


Submitted By : Tanishq Kumar
SAP ID: 590021506
Course Title: Programming in C
Course Code: CSEG1032
Semester: 1
Batch:-19

Submitted To : Mr. Rahul Prashad

1. ABSTRACT

This project looks at creating a Matrix Solver in C language that can solve 2×2 and 3×3 linear systems using Cramer’s Rule. The goal is to show how structured programming, mathematical modeling, and problem-solving work together. The project covers determinant calculation, managing singular matrices, and providing correct numerical results. It also includes a clear explanation of matrix theory, determinants, Cramer’s Rule, and the workflow of the algorithm.




2. OBJECTIVE

The main goals of this project are:

• To design and implement a matrix solver using C.

• To use Cramer’s Rule to find solutions for 2×2 and 3×3 systems.

• To learn and carry out determinant calculations for 2×2 and 3×3 matrices.

• To show modular programming by using functions in C.

• To look into numerical stability and detect singular matrices.

• To write a detailed project report that meets academic standards.

Additional learning goals include improving problem-solving skills, understanding matrix operations, practicing structured programming, and learning the documentation standards used in engineering projects.

3. PROBLEM DEFINITION
Linear equations often appear in areas like structural engineering, electrical circuit design, control systems, and machine learning. Solving these equations by hand can become tedious and lead to calculation errors.

Challenges this project addresses:

• Calculating determinants by hand takes a lot of time.

• There is a high chance of human error when working with 3×3 systems.

• Users cannot instantly check if matrices are singular.

• Beginners lack automated tools to learn about solving matrices.

This project automates the process using C. It lets users enter matrix values and get solutions quickly, accurately, and with error detection.


4. SYSTEM DESIGN AND ALGORITHM
SYSTEM DESIGN:
The system design consists of multiple modules, arranged for readability, reusability, and modular execution.


### Module Responsibilities
• det2() – Computes 2×2 determinant.

• det3() – Computes 3×3 determinant using expansion by minors.

• solve2() – Reads input for 2×2 system, computes determinants, outputs solutions.

• solve3() – Handles full 3×3 system input and outputs results.

• main() – Menu selection, program coordination, user interface.


### Data Flow
User → Input Matrix → Determinant Computation → Check D → Compute Cramer Values → Output

ALGORITHM:

### Algorithm Steps for 2×2 Solver
1. Read matrix values a, b, c, d.

2. Read RHS values v1, v2.

3. Compute D = ad − bc.

4. If D = 0 → No unique solution.

5. Compute Dx and Dy.
6. Output x = Dx/D, y = Dy/D.


### Algorithm for 3×3 Solver
1. Read 3×3 matrix A.
2. Read RHS vector b.
3. Compute determinant D.
4. If |D| < threshold → No unique solution.
5. Form Mx, My, Mz.
6. Compute Dx, Dy, Dz.
7. Output values of x, y, z.


Both algorithms ensure numerical stability by comparing the determinant with a small epsilon (1e−12).


Flowchart:-  

5. IMPLEMENTATION DETAILS
The implementation is written in standard C with the GCC compiler. Key features include:

• Modular functions for determinants and solvers.

• Floating-point arithmetic using double precision.

• scanf() and printf() for input and output.

• Mathematical checks using fabs() from math.h.

• Thresholding to prevent floating-point instability for near-zero determinants.

The code is designed to be clear, informative, and efficient for small matrices.
6. Source Code
#include <stdio.h>
#include <math.h>

double det2(double a,double b,double c,double d){ return a*d - b*c; }

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
    if (fabs(D) < 1e-12){ printf("No unique solution (det=0).\n"); return 1; }
    double Dx = det2(v1,b,v2,d), Dy = det2(a,v1,c,v2);
    printf("x = %.10g, y = %.10g\n", Dx/D, Dy/D);
    return 1;
}

int solve3(){
    double A[3][3], b[3];
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (scanf("%lf",&A[i][j])!=1) return 0;
    for (int i=0;i<3;i++) if (scanf("%lf",&b[i])!=1) return 0;
    double D = det3(A);
    if (fabs(D) < 1e-12){ printf("No unique solution (det=0).\n"); return 1; }
    double Mx[3][3], My[3][3], Mz[3][3];
    for (int i=0;i<3;i++){
        Mx[i][0]=b[i]; Mx[i][1]=A[i][1]; Mx[i][2]=A[i][2];
        My[i][0]=A[i][0]; My[i][1]=b[i]; My[i][2]=A[i][2];
        Mz[i][0]=A[i][0]; Mz[i][1]=A[i][1]; Mz[i][2]=b[i];
    }
    double Dx = det3(Mx), Dy = det3(My), Dz = det3(Mz);
    printf("x = %.10g, y = %.10g, z = %.10g\n", Dx/D, Dy/D, Dz/D);
    return 1;
}

int main(){
    puts("Choose 1 for 2x2 or 2 for 3x3 (then enter matrix and RHS).");
    int c;
    if (scanf("%d",&c)!=1) return 0;
    if (c==1){
        puts("Enter 4 numbers (A row-major) then 2 RHS numbers:");
        solve2();
    } else if (c==2){
        puts("Enter 9 numbers (A row-major) then 3 RHS numbers:");
        solve3();
    } else puts("Invalid choice.");
    return 0;
}


7. TESTING AND RESULTS

Several test cases were executed to validate correctness:


### Test Case 1 (2×2)
Matrix:
1 2
3 4
RHS: 5 6
Output: x = −4, y = 4.5


### Test Case 2 (3×3 Identity Matrix)
Matrix:
1 0 0
0 1 0
0 0 1
RHS: 3 4 5
Output: x=3, y=4, z=5


### Singular Test
Matrix:
1 2 3
2 4 6
1 2 3
Determinant = 0 → No unique solution.


These cases confirm correct behavior for regular and singular matrices.



8. CONCLUSION AND FUTURE SCOPE

This project successfully creates a matrix solver using Cramer’s Rule. It is precise, modular, efficient, and suitable for academic purposes.

### Future Enhancements
• Support for n×n matrices.

• Gaussian elimination and LU decomposition.

• File handling to load or save matrices.

• GUI-based matrix calculator.

• Error checking for invalid inputs.

The project shows how math and programming can come together to create useful tools.


9. REFERENCES

Kernighan, B. W., & Ritchie, D. M. The C Programming Language. 

Lecture Notes 

Standard C Library Documentation: cppreference.com


