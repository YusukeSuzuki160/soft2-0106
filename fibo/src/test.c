#include "matrix.h"
#include <assert.h>
#include <stdio.h>

int main() // test for matrix.c
{
    Matrix a = {.a00 = 1, .a01 = 1, .a10 = 1, .a11 = 0};
    Matrix b = {.a00 = 1, .a01 = 1, .a10 = 1, .a11 = 1};
    Matrix c = {.a00 = 2, .a01 = 2, .a10 = 2, .a11 = 1};
    Matrix d = {.a00 = 3, .a01 = 3, .a10 = 3, .a11 = 0};
    Matrix e = {.a00 = 0, .a01 = 0, .a10 = 0, .a11 = -1};
    Matrix f = {.a00 = 2, .a01 = 2, .a10 = 1, .a11 = 1};
    Matrix g = {.a00 = 8, .a01 = 5, .a10 = 5, .a11 = 3};
    printf("test start!\n");
    assert(matrix_eq(matrix_add(a, b), c));
    assert(matrix_eq(matrix_mul_int(a, 3), d));
    assert(matrix_eq(matrix_sub(a, b), e));
    assert(matrix_eq(matrix_mul(a, b), f));
    assert(matrix_eq(matrix_ex(a, 5), g));

    printf("test succeeded!");
    return 0;
}