#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include "item.h"

// 構造体をポインタで確保するお作法を確認してみよう
Itemset *init_itemset(size_t number, int seed)
{
    Itemset *list = (Itemset *)malloc(sizeof(Itemset));

    Item *item = (Item *)malloc(sizeof(Item) * number);

    srand(seed);
    for (int i = 0; i < number; i++)
    {
        item[i].value = 0.1 * (rand() % 200);
        item[i].weight = 0.1 * (rand() % 200 + 1);
    }
    *list = (Itemset){.number = number, .item = item};
    return list;
}

// itemset の free関数
void free_itemset(Itemset *list)
{
    free(list->item);
    free(list);
}

// 表示関数
void print_itemset(const Itemset *list)
{
    size_t n = list->number;
    const char *format = "v[%d] = %4.1f, w[%d] = %4.1f\n";
    for (int i = 0; i < n; i++)
    {
        Item item = get_item(list, i);
        printf(format, i, get_itemvalue(item), i, get_itemweight(item));
    }
    printf("----\n");
}

Item get_item(const Itemset *list, size_t index)
{
    return list->item[index];
}

double get_itemweight(Item item)
{
    return item.weight;
}

double get_itemvalue(Item item)
{
    return item.value;
}

Itemset *load_itemset(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open %s", filename);
        exit(1);
    }
    int number;
    fread(&number, 4, 1, fp);
    Itemset *list = (Itemset *)malloc(sizeof(Itemset));

    Item *item = (Item *)malloc(sizeof(Item) * number);

    for (int i = 0; i < number; i++)
    {
        fread(&(item[i].value), 8, 1, fp);
    }
    for (int i = 0; i < number; i++)
    {
        fread(&(item[i].weight), 8, 1, fp);
    }

    *list = (Itemset){.number = number, .item = item};
    return list;
}

void save_itemset(char *filename, Itemset *list)
{
    FILE *fp = fopen(filename, "wb");
    int number = list->number;
    fwrite(&(number), 4, 1, fp);
    for (int i = 0; i < number; i++)
    {
        Item item = get_item(list, i);
        double value = get_itemvalue(item);
        fwrite(&value, 8, 1, fp);
    }
    for (int i = 0; i < number; i++)
    {
        Item item = get_item(list, i);
        double weight = get_itemweight(item);
        fwrite(&weight, 8, 1, fp);
    }
}