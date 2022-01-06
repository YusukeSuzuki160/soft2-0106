#include "fibo.h"
#include <assert.h>

const Matrix FIBO = {.a00 = 1, .a01 = 1, .a10 = 1, .a11 = 0};

long int fibo(int n)
{
    assert(n <= 90);
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    Matrix a = matrix_ex(FIBO, n - 1);
    return a.a00 * fibo(1) + a.a01 * fibo(0);
}