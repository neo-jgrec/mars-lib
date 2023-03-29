/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** pointer
*/

#include "format.h"

int my_asprintf_pointer(char **str, va_list ap, UNUSED void *opt)
{
    char *tmp = my_convert_base(my_itoa(va_arg(ap, long)),
    "0123456789", "0123456789abcdef");
    char *tmp2 = my_strcat("0x", tmp);

    *str = my_strcat(*str, tmp2);
    free(tmp);
    free(tmp2);
    return (0);
}