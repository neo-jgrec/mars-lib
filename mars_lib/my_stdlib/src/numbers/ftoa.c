/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** ftoi
*/

#include "my_stdlib.h"

char *my_ftoa(double nb, int precision)
{
    char *str = malloc(sizeof(char) * (precision * 10));
    int i = 0;
    int nb_int = (int)nb;
    double nb_double = nb - nb_int;

    if (str == NULL)
        return (NULL);
    (nb < 0) ? str[i++] = '-' : 0;
    nb_int = (nb_int < 0) ? -nb_int : nb_int;
    nb_double = (nb_double < 0) ? -nb_double : nb_double;
    my_strcpy(str + i, my_itoa(nb_int));
    i += my_strlen(str + i);
    str[i++] = '.';
    for (int j = 0; j < precision; j++) {
        nb_double *= 10;
        str[i++] = (int)nb_double + '0';
        nb_double -= (int)nb_double;
    }
    str[i] = '\0';
    return (str);
}
