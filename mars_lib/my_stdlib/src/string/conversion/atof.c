/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** atof
*/

#include "macros.h"
#include <stdint.h>

static double my_powf(double base, int exponent)
{
    double result = 1;

    if (exponent < 0) {
        exponent = -exponent;
        base = 1.0f / base;
    }
    while (exponent) {
        if (exponent & 1)
            result *= base;
        exponent >>= 1;
        base *= base;
    }
    return result;
}

double my_atof(const char *str)
{
    int32_t mantissa = 0;
    int exponent = 0;
    int sign = 1;
    double result;

    for (; *str == ' '; str++);
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    for (; IS_NUM(*str); str++)
        mantissa = mantissa * 10 + (*str - '0');
    if (*str == '.') {
        str++;
        for (; IS_NUM(*str); str++, exponent--)
            mantissa = mantissa * 10 + (*str - '0');
    }
    result = (double)mantissa * my_powf(10, exponent) * sign;
    return result;
}
