#include "fibo.h"
#include <stdio.h>

extern const Matrix FIBO;

int main()
{
    printf("%ld\n", fibo(0));
    printf("%ld\n", fibo(1));
    printf("%ld\n", fibo(10));
    printf("%ld\n", fibo(20));
    printf("%ld\n", fibo(30));
    printf("%ld\n", fibo(40));
    printf("%ld\n", fibo(50));
    printf("%ld\n", fibo(60));
    printf("%ld\n", fibo(70));
    printf("%ld\n", fibo(80));
    printf("%ld\n", fibo(90));
}