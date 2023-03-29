/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** n
*/

#include "format.h"

int my_asprintf_n(char **str, va_list ap, UNUSED void *opt)
{
    int *n = va_arg(ap, int *);

    *n = my_strlen(*str);
    *str = my_realloc(*str, sizeof(char) * 1);
    if (*str == NULL)
        return (-1);
    (*str)[0] = '\0';
    return (0);
}
