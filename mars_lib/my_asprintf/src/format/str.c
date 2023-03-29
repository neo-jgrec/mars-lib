/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** str
*/

#include "format.h"

int my_asprintf_str(char **str, va_list ap, UNUSED void *opt)
{
    char *s = va_arg(ap, char *);

    *str = malloc(sizeof(char) * (my_strlen(s) + 1));
    if (*str == NULL)
        return (-1);
    my_strcpy(*str, s);
    return (my_strlen(s));
}

int my_asprintf_str_non_printable(char **str, va_list ap, UNUSED void *opt)
{
    char *s = va_arg(ap, char *);

    *str = malloc(sizeof(char) * (my_strlen(s) * 4 + 1));
    if (*str == NULL)
        return (-1);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 32 && s[i] <= 126) {
            *str = my_strcat(*str, &s[i]);
        } else {
            *str = my_strcat(*str, "\\");
            *str = my_strcat(*str, my_convert_base(my_itoa(s[i]),
            "0123456789", "01234567"));
        }
    }
    return (my_strlen(*str));
}
