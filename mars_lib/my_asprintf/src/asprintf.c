/*
** EPITECH PROJECT, 2023
** Mars-Lib
** File description:
** asprintf
*/

#include "format.h"

static int my_vasprintf(char **str, const char *format, va_list ap)
{
    int len = 0;
    int tmp = 0;
    char *tmp_str = NULL;

    for (int i = 0; *format != '\0'; i++) {
        if (*format == '%') {
            format++;
            for (int j = 0; flags[j].name != '\0'; j++) {
                if (*format == flags[j].name) {
                    tmp = flags[j].fct(&tmp_str, ap, (void *) format);
                    if (tmp == -1)
                        return (-1);
                    char *tmp2 = malloc(sizeof(char) * (len + tmp + 1));
                    if (tmp2 == NULL)
                        return (-1);
                    for (int k = 0; k < len; k++)
                        tmp2[k] = (*str)[k];
                    for (int k = 0; k < tmp; k++)
                        tmp2[k + len] = tmp_str[k];
                    tmp2[len + tmp] = '\0';
                    free(*str);
                    *str = tmp2;
                    len += tmp;
                    break;
                }
            }
        } else {
            char *tmppp = malloc(sizeof(char) * (len + 2));
            if (tmppp == NULL)
                return (-1);
            for (int j = 0; j < len; j++)
                tmppp[j] = (*str)[j];
            tmppp[len] = *format;
            tmppp[len + 1] = '\0';
            free(*str);
            *str = tmppp;
            len++;
        }
        format++;
    }
    return (len);
}

int my_asprintf(char **str, const char *format, ...)
{
    va_list ap;
    int len;

    va_start(ap, format);
    len = my_vasprintf(str, format, ap);
    va_end(ap);
    return (len);
}
