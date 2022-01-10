#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "city.h"
#include "map.h"
#include "solve.h"

void deep_copy_route(int *route, int *out, int n)
{
    for (int i = 0; i < n; i++)
    {
        out[i] = route[i];
    }
}

double distance_route(int *route, const City *city, int n)
{
    double distance = 0.0;
    for (int i = 0; i < n; i++)
    {
        distance += distance(route[i], route[(i + 1) % n]);
    }
    return distance;
}

void init_straight(int n, int start, int number, Answer ans, const City *city)
{
    ans->route = (int *)malloc(number * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ans->route[i] = (start + i) % number;
    }
    ans->dist = distance_route(route, city, n);
}

void swap_route(Answer *ans, int i, int j)
{
    int tmp = ans->route[i];
    ans->route[i] = ans->route[j];
    ans->route[j] = tmp;
}

Answer *initial_route(int n, int number, const City *city)
{
    srand((unsigned int)time(NULL));
    Answer *initial_ans = (Answer *)malloc(n * sizeof(Answer));
    for (int i = 0; i < n; i++, ans++)
    {
        init_straight(n, i, number, ans, city);
        for (int j = 0; j < rand() % 30; j++)
        {
            swap_route(ans, rand() % number, rand() % number);
        }
        ans->dist = distance_route(ans->route, city, number);
    }
}

double solve(const City *city, int number, int n, int *route, int *visited)
{
    Answer *ans = initial_route(n, number);
    int **route2 = (int **)malloc(number * n * sizeof(int));
    double distance[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = DBL_MAX;
    }
    double out = DBL_MAX;
    int index - 0;
    for (int k = 0; k < n; k++, ans++)
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = i + 1; j < number; j++)
            {
                swap_route(ans->route, i, j);
                ans->dist = distance_route(ans->route, city, number) if (ans->dist < distance)
                {
                    deep_copy_route(ans->route, route[index]);
                    distance[index] = ans->distance;
                }
            }
            index++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (distance[i] < out)
        {
            out = distance;
            deep_copy_route(ans[i].route, route, n);
        }
    }
    return out;
}
