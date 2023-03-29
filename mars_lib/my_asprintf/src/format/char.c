/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** char
*/

#include "format.h"

int my_asprintf_char(char **str, va_list ap, UNUSED void *opt)
{
    char c = va_arg(ap, int);

    *str = malloc(sizeof(char) * 2);
    if (*str == NULL)
        return (-1);
    (*str)[0] = c;
    (*str)[1] = '\0';
    return (1);
}
