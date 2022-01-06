#include "calc_magicnumber.h"

float char_to_f32(char *c)
{
    float *out;
    out = (float *)c;
    return *out;
}

int slength(char *s)
{
    int i = 0;
    while (*s != 0)
    {
        i++;
        s++;
    }
    return i;
}

float *parse_char_to_f32(char *s)
{
    int l = slength(s);
    float *out = (float *)malloc((l / 4 + 1) * sizeof(float));
    int i = 0;
    for (i = 0; i < l / 4; i++, s += (sizeof(float) / sizeof(char)))
    {
        out[i] = char_to_f32(s);
    }
    out[i + 1] = 0;
    return out;
}