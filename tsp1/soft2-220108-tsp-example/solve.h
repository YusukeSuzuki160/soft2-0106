#pragma once
#include "city.h"

typedef struct ans
{
    double dist;
    int *route;
} Answer;

void deep_copy_route(int *route, int *out, int n);

double distance_route(int *route, const City *city);

void init_straight(int start, Answer ans);

void swap_route(Answer *ans, int i, int j);

Answer *initial_route(int n);

double solve(const City *city, int n, int *route, int *visited);

Answer search(const City *city, int n, int *route, int *visited);
