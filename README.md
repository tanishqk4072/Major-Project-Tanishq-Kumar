PROJECT DESCRIPTION

Matrix Solver for 2×2 and 3×3 Systems Using Cramer’s Rule

This project aims to develop a C-language program that solves linear equations of order 2×2 and 3×3 using Cramer’s Rule. Linear systems of equations are found in almost every area of engineering, science, computer graphics, and data analysis. The goal of this project is to create a simple, interactive command-line tool. It will read matrix coefficients and right-hand-side (RHS) constants from the user, compute the necessary determinants, check if a unique solution exists, and print the solution of the system.

The program is written in standard C, using only <stdio.h> and <math.h> for portability and clarity. It implements two determinant functions: one for a 2×2 matrix and another for a 3×3 matrix. Using these, the program applies Cramer's Rule. This rule states that each variable in a linear system can be calculated by replacing one column of the coefficient matrix with the RHS vector and dividing the resulting determinant by the main determinant of the system.

The project handles two types of systems:

1. 2×2 system:
   - Reads four matrix elements in row-major order and two RHS values.
   - Computes the determinant and checks if it is zero.
   - Outputs the values of x and y if the system is solvable.

2. 3×3 system:
   - Reads nine matrix elements and three RHS values.
   - Computes the determinant of the coefficient matrix and three modified matrices.
   - Displays the values of x, y, and z if a unique solution exists.

If the determinant of the matrix is zero or very close to zero, the program prints a message indicating that the system has no unique solution. This prevents unnecessary division by extremely small values.

The project showcases basic programming concepts such as functions, loops, conditional statements, matrix handling, and numerical computation. It also demonstrates how mathematical techniques like determinants and Cramer’s Rule can be implemented in programming. The simplicity, accuracy, and ease of extending this solver make it beneficial for educational purposes and for students learning linear algebra and computational methods. 



INTRODUCTION

Solving systems of linear equations is one of the most basic tasks in mathematics, engineering, physics, and computer science. It is used in circuit analysis, structural engineering, economics, and computer graphics. Linear algebra offers a way to model and solve real-world problems. Among the different methods for solving these systems, Cramer’s Rule stands out as a straightforward and easy-to-understand technique for small matrices.

This project aims to create a matrix solver in the C programming language that can manage 2×2 and 3×3 systems of linear equations using Cramer’s Rule. The program asks the user to choose the size of the system, accepts the coefficient matrix and right-hand-side values, computes the determinant of the matrix, and checks if the system has a unique solution. If the determinant is non-zero, the program calculates and shows the values of the unknown variables. If the determinant is zero or very small, the program identifies that the system has no unique solution, which might mean there are either infinite solutions or no solution at all.

Implementing this project helps students grasp the mathematical ideas behind determinants and Cramer’s Rule, as well as how these ideas translate into effective C code. It shows how to use user-defined functions, modular programming, conditional checks, nested loops, and numeric accuracy with floating-point operations. Additionally, the project emphasizes good programming practices such as breaking down logic into functions, checking mathematical conditions, and ensuring clear user interaction.
