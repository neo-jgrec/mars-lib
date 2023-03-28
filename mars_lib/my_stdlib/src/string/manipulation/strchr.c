/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strchr
*/

#include "my_stdlib.h"

char *my_strchr(const char *str, int c)
{
    while (*str) {
        if (*str == (char)c)
            return (char *)str;
        str++;
    }
    if (c == '\0')
        return (char *)str;
    return NULL;
}
