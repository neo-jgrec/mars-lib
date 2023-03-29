/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** float
*/

#include "format.h"

int my_asprintf_float(char **str, va_list ap, UNUSED void *opt)
{
    double nb = va_arg(ap, double);
    int len;

    *str = my_calloc(sizeof(char), (opt != NULL) ? *(int *) opt : 6 + 2);
    if (*str == NULL)
        return (-1);
    char *result = my_ftoa(nb, 6);
    my_strcpy(*str, result);
    free(result);
    len = my_strlen(*str);
    return (len);
}
