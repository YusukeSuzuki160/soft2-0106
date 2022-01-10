#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "city.h"
#include "map.h"
#include "solve.h"
const int SAMPLE_NUMBER = 10000;
void deep_copy_route(int *route, int *out, int n)
{
    // printf("deep_copy_route start!!/n");
    for (int i = 0; i < n; i++)
    {
        out[i] = route[i];
    }
    // printf("deep_copy_route end!!/n");
}

double distance_route(int *route, const City *city, int n)
{
    // printf("distance_route start!!\n");
    double distance_out = 0.0;
    for (int i = 0; i < n; i++)
    {
        distance_out += distance(city[route[i]], city[route[(i + 1) % n]]);
    }
    // printf("distance_route end!!\n");
    return distance_out;
}

void init_straight(int start, int number, Answer *ans, const City *city)
{
    // printf("init_straight start!!\n");
    ans->route = (int *)malloc(number * sizeof(int));
    ans->route[0] = 0;
    for (int i = 1; i < number; i++)
    {
        ans->route[i] = (start + i) % (number - 1) + 1;
    }
    ans->dist = distance_route(ans->route, city, number);
    // printf("init_straight end!!\n");
}

void swap_route(Answer *ans, int i, int j)
{
    // printf("swap_route start!!\n");
    int tmp = ans->route[i];
    ans->route[i] = ans->route[j];
    ans->route[j] = tmp;
    // printf("swap_route end!!\n");
}

Answer *initial_route(int n, int number, const City *city)
{
    // printf("initial_route start!!\n");
    srand((unsigned int)time(NULL));
    Answer *initial_ans = (Answer *)malloc(n * sizeof(Answer));
    for (int i = 0; i < n; i++, initial_ans++)
    {
        init_straight(i, number, initial_ans, city);
        for (int j = 0; j < rand() % 30; j++)
        {
            swap_route(initial_ans, rand() % number, rand() % number);
        }
        initial_ans->dist = distance_route(initial_ans->route, city, number);
    }
    initial_ans -= n;
    // printf("initial_route end!!\n");
    return initial_ans;
}

double solve_single(const City *city, Answer *ans, int number, int *route, double end)
{
    // printf("solve_single start!!\n");
    double before = end;
    for (int i = 1; i < number; i++)
    {
        for (int j = i + 1; j < number; j++)
        {
            swap_route(ans, i, j);
            double dist = distance_route(ans->route, city, number);
            if (end > dist)
            {
                deep_copy_route(ans->route, route, number);
                end = dist;
            }
        }
    }
    double out = 0;
    if (before == end)
    {
        return end;
    }
    else
    {
        deep_copy_route(route, ans->route, number);
        ans->dist = end;
        out = solve_single(city, ans, number, route, end);
    }
    // printf("solve_single end!!\n");
    return out;
}

double solve(const City *city, int number, int n, int *route)
{
    // printf("solve start!!\n");
    Answer *ans = initial_route(SAMPLE_NUMBER, number, city);
    double init = DBL_MAX;
    double result[SAMPLE_NUMBER];
    int route2[SAMPLE_NUMBER][number];
    for (int i = 0; i < SAMPLE_NUMBER; i++)
    {
        result[i] = solve_single(city, ans, number, route2[i], init);
    }
    double out = result[0];
    deep_copy_route(route2[0], route, number);
    for (int i = 0; i < SAMPLE_NUMBER; i++)
    {
        if (result[i] < out)
        {
            out = result[i];
            deep_copy_route(route2[i], route, number);
        }
    }
    // printf("solve end!!\n");
    return out;
}
