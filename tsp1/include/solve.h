#pragma once
#include "city.h"

typedef struct answer
{
    int *route;
    double dist;
} Answer;

void deep_copy_route(int *route, int *out, int n);

double distance_route(int *route, const City *city, int n);

void init_straight(int start, int number, Answer *ans, const City *city);

void swap_route(Answer *ans, int i, int j);

Answer *initial_route(int n, int number, const City *city);

double solve_single(const City *city, Answer *ans, int number, int *route, double end);

double solve(const City *city, int number, int n, int *route);
