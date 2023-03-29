/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** int
*/

#include "format.h"

int my_asprintf_int(char **str, va_list ap, UNUSED void *opt)
{
    int nb = va_arg(ap, int);
    int i = 0;
    int sign = 1;
    char *tmp = malloc(sizeof(char) * 12);

    if (tmp == NULL)
        return (-1);
    sign = (nb < 0) ? -1 : 1;
    nb = (nb < 0) ? nb * -1 : nb;
    for (; nb > 0; tmp[i] = nb % 10 + '0', i++, nb /= 10);
    i = (sign == -1) ? i + 1 : i;
    (sign == -1) ? tmp[i - 1] = '-' : 0;
    tmp[i] = '\0';
    my_revstr(tmp);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, tmp);
    free(tmp);
    return (my_strlen(*str));
}

int my_asprintf_uint(char **str, va_list ap, UNUSED void *opt)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int i = 0;
    char *tmp = malloc(sizeof(char) * 12);

    if (tmp == NULL)
        return (-1);
    for (; nb > 0; tmp[i] = nb % 10 + '0', i++, nb /= 10);
    tmp[i] = '\0';
    my_revstr(tmp);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, tmp);
    free(tmp);
    return (my_strlen(*str));
}
