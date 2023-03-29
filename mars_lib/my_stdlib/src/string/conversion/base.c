/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** base
*/

#include <malloc.h>
#include "my_stdlib.h"

char *my_convert_base(char *nbr, char *base_from, char *base_to)
{
    int len = my_strlen(base_from);
    int len2 = my_strlen(base_to);
    int nb = 0;
    int i = 0;
    char *tmp = malloc(sizeof(char) * 12);

    if (tmp == NULL)
        return (NULL);
    for (; nbr[i] != '\0'; i++)
        for (int j = 0; base_from[j] != '\0'; j++)
            if (nbr[i] == base_from[j])
                nb = nb * len + j;
    for (i = 0; nb > 0; tmp[i] = base_to[nb % len2], i++, nb /= len2);
    tmp[i] = '\0';
    my_revstr(tmp);
    return (tmp);
}
