#ifndef _matrix_h_
#define _matrix_h_
#include <stdbool.h>
typedef struct matrix
{
    long int a00;
    long int a01;
    long int a10;
    long int a11;
} Matrix;

Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_mul_int(Matrix a, int n);
Matrix matrix_sub(Matrix a, Matrix b);
Matrix matrix_mul(Matrix a, Matrix b);
Matrix matrix_ex(Matrix a, int n);
bool matrix_eq(Matrix a, Matrix b);

#endif