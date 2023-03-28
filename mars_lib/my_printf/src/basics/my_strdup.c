/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "utils.h"

char *my_strdup(const char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}
