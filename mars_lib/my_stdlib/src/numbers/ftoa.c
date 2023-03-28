/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** ftoi
*/

#include "my_stdlib.h"

char *my_ftoa(float nb, int precision)
{
    char *str = malloc(sizeof(char) * (precision + 2));
    int i = 0;
    int nb_int = (int)nb;
    float nb_float = nb - nb_int;

    if (str == NULL)
        return (NULL);
    (nb < 0) ? str[i++] = '-' : 0;
    nb_int = (nb_int < 0) ? -nb_int : nb_int;
    nb_float = (nb_float < 0) ? -nb_float : nb_float;
    my_strcpy(str + i, my_itoa(nb_int));
    i += my_strlen(str + i);
    str[i++] = '.';
    for (int j = 0; j < precision; j++) {
        nb_float *= 10;
        str[i++] = (int)nb_float + '0';
        nb_float -= (int)nb_float;
    }
    str[i] = '\0';
    return (str);
}
