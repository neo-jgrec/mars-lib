/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** format
*/

#ifndef FORMAT_H_
    #define FORMAT_H_

    #include <stdarg.h>
    #include <malloc.h>

    #include "my_stdlib.h"

int my_asprintf_char(char **str, va_list ap, void *opt);
int my_asprintf_str(char **str, va_list ap, void *opt);
int my_asprintf_int(char **str, va_list ap, void *opt);
int my_asprintf_uint(char **str, va_list ap, void *opt);
int my_asprintf_octal(char **str, va_list ap, void *opt);
int my_asprintf_hexa_min(char **str, va_list ap, void *opt);
int my_asprintf_hexa_maj(char **str, va_list ap, void *opt);
int my_asprintf_bin(char **str, va_list ap, void *opt);
int my_asprintf_pointer(char **str, va_list ap, void *opt);
int my_asprintf_str_non_printable(char **str, va_list ap, void *opt);
int my_asprintf_float(char **str, va_list ap, void *opt);
int my_asprintf_percent(char **str, va_list ap, void *opt);
int my_asprintf_n(char **str, va_list ap, void *opt);

typedef struct {
    char name;
    int (*fct)(char **str, va_list ap, void *opt);
} flags_t;

static const flags_t flags[] = {
    {'c', my_asprintf_char},
    {'s', my_asprintf_str},
    {'d', my_asprintf_int},
    {'i', my_asprintf_int},
    {'u', my_asprintf_uint},
    {'o', my_asprintf_octal},
    {'x', my_asprintf_hexa_min},
    {'X', my_asprintf_hexa_maj},
    {'b', my_asprintf_bin},
    {'p', my_asprintf_pointer},
    {'S', my_asprintf_str_non_printable},
    {'f', my_asprintf_float},
    {'F', my_asprintf_float},
    {'%', my_asprintf_percent},
    {'n', my_asprintf_n},
    {'\0', NULL}
};

#endif /* !FORMAT_H_ */
