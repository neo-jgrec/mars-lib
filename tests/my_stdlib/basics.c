/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** basics
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_stdlib.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strcpy, basics, .init = redirect_all_std)
{
    char *str = "Hello World!";
    char *str2 = malloc(sizeof(char) * 12);

    my_strcpy(str2, str);
    cr_assert_str_eq(str2, str);
}
