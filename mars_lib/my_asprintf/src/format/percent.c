/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** percent
*/

#include "format.h"

int my_asprintf_percent(char **str, va_list ap, UNUSED void *opt)
{
    (void) ap;
    *str = my_realloc(*str, sizeof(char) * 2);
    if (*str == NULL)
        return (-1);
    (*str)[0] = '%';
    (*str)[1] = '\0';
    return (1);
}
