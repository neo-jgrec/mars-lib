/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** conversion
*/

#include "format.h"

int my_asprintf_octal(char **str, va_list ap, UNUSED void *opt)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *tmp = my_convert_base(my_itoa(nb), "0123456789", "01234567");

    if (tmp == NULL)
        return (-1);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, tmp);
    free(tmp);
    return (my_strlen(*str));
}

int my_asprintf_hexa_min(char **str, va_list ap, UNUSED void *opt)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *tmp = my_convert_base(my_itoa(nb), "0123456789", "0123456789abcdef");

    if (tmp == NULL)
        return (-1);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, tmp);
    free(tmp);
    return (my_strlen(*str));
}

int my_asprintf_hexa_maj(char **str, va_list ap, UNUSED void *opt)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *tmp = my_convert_base(my_itoa(nb), "0123456789", "0123456789ABCDEF");

    if (tmp == NULL)
        return (-1);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, tmp);
    free(tmp);
    return (my_strlen(*str));
}

int my_asprintf_bin(char **str, va_list ap, UNUSED void *opt)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *tmp = my_convert_base(my_itoa(nb), "0123456789", "01");

    if (tmp == NULL)
        return (-1);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, tmp);
    free(tmp);
    return (my_strlen(*str));
}
