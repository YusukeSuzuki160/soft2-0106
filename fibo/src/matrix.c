#include "matrix.h"
#include <assert.h>

Matrix matrix_add(Matrix a, Matrix b)
{
    Matrix c;
    c.a00 = a.a00 + b.a00;
    c.a01 = a.a01 + b.a01;
    c.a10 = a.a10 + b.a10;
    c.a11 = a.a11 + b.a11;
    return c;
}

Matrix matrix_mul_int(Matrix a, int n)
{
    Matrix c;
    c.a00 = a.a00 * n;
    c.a01 = a.a01 * n;
    c.a10 = a.a10 * n;
    c.a11 = a.a11 * n;
    return c;
}

Matrix matrix_sub(Matrix a, Matrix b)
{
    return matrix_add(a, matrix_mul_int(b, -1));
}

Matrix matrix_mul(Matrix a, Matrix b)
{
    Matrix c;
    c.a00 = a.a00 * b.a00 + a.a01 * b.a10;
    c.a01 = a.a00 * b.a01 + a.a01 * b.a11;
    c.a10 = a.a10 * b.a00 + a.a11 * b.a10;
    c.a11 = a.a10 * b.a01 + a.a11 * b.a11;
    return c;
}

Matrix matrix_ex(Matrix a, int n)
{
    assert(n > 0);
    if (n == 2)
    {
        return matrix_mul(a, a);
    }
    else if (n == 1)
    {
        return a;
    }
    else if (n % 2 == 0)
    {
        return matrix_ex(matrix_ex(a, n / 2), 2);
    }
    else if (n % 2 == 1)
    {
        Matrix b = {.a00 = 1, .a01 = 1, .a10 = 1, .a11 = 0};
        return matrix_mul(matrix_ex(matrix_ex(a, (n - 1) / 2), 2), b);
    }
}

bool matrix_eq(Matrix a, Matrix b)
{
    if (a.a00 == b.a00 && a.a01 == b.a01 && a.a10 == b.a10 && a.a11 == b.a11)
    {
        return true;
    }
    else
    {
        return false;
    }
}