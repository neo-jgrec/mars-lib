/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** basics
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_stdlib.h"
#include <stdio.h>

Test(test_my_atol, basics)
{
    cr_assert_eq(my_atol("42"), 42);
    cr_assert_eq(my_atol("-42"), -42);
    cr_assert_eq(my_atol("0"), 0);
}

Test(test_my_atoi, basics)
{
    cr_assert_eq(my_atoi("42"), 42);
    cr_assert_eq(my_atoi("-42"), -42);
    cr_assert_eq(my_atoi("0"), 0);
}

Test(test_my_atof, basics)
{
    float epsilon = 0.0001f;
    cr_expect_float_eq(my_atof("3.14"), 3.14f, epsilon);
    cr_expect_float_eq(my_atof("0"), 0.0f, epsilon);
    cr_expect_float_eq(my_atof("-123.456"), -123.456f, epsilon);
}

Test(test_my_my_strtod, basics)
{
    float epsilon = 0.0001f;
    cr_expect_float_eq(my_strtod("0", NULL), 0.0f, epsilon);
}

Test(test_my_strncat, basics)
{
    char *str = "Hello World!";
    char *dest = my_calloc(1, 12);
    cr_assert_eq(my_strncat(dest, str, 5), dest);
    cr_assert_str_eq(dest, "Hello");
    cr_assert_eq(my_strncat(dest, str + 5, 6), dest);
    cr_assert_str_eq(dest, "Hello World");
    cr_assert_eq(my_strncat(dest, str + 11, 1), dest);
    cr_assert_str_eq(dest, "Hello World!");
}

Test(test_my_strcat, basics)
{
    char *str = "Hello World!";
    char *dest = my_calloc(1, 12);
    cr_assert_eq(my_strcat(dest, str), dest);
    cr_assert_str_eq(dest, "Hello World!");
}

Test(test_my_strcat_char, basics)
{
    char *dest = my_calloc(1, 12);
    dest = my_strcpy(dest, "Hello");
    cr_assert_eq(my_strcat_char(dest, ' '), dest);
    cr_assert_str_eq(dest, "Hello ");
    cr_assert_eq(my_strcat_char(dest, 'W'), dest);
    cr_assert_str_eq(dest, "Hello W");
}

Test(test_my_strlen, basics)
{
    cr_assert_eq(my_strlen("Hello World!"), 12);
    cr_assert_eq(my_strlen(""), 0);
}

Test(test_my_strdup, basics)
{
    char *str = "Hello World!";
    char *dest = my_strdup(str);
    cr_assert_str_eq(dest, str);
    cr_assert_neq(dest, str);
}

Test(test_my_strndup, basics)
{
    char *str = "Hello World!";
    char *dest = my_strndup(str, 5);
    cr_assert_str_eq(dest, "Hello");
    cr_assert_neq(dest, str);
}

Test(test_my_strsplit, basics)
{
    char *str = "Hello World!";
    char **dest = my_strsplit(str, ' ');
    cr_assert_str_eq(dest[0], "Hello");
    cr_assert_str_eq(dest[1], "World!");
    cr_assert_eq(dest[2], NULL);
}

Test(test_my_revstr, basics)
{
    char *str = my_calloc(1, 12);
    str = my_strcpy(str, "Hello World!");
    cr_assert_eq(my_revstr(str), str);
    cr_assert_str_eq(str, "!dlroW olleH");
}

Test(test_my_strcmp, basics)
{
    cr_assert_eq(my_strcmp("Hello World!", "Hello World!"), 0);
    cr_assert_eq(my_strcmp("Hello World!", "Hello World"), 33);
    cr_assert_eq(my_strcmp("Hello World", "Hello World!"), -33);
}

Test(test_my_strncmp, basics)
{
    cr_assert_eq(my_strncmp("Hello World!", "Hello World!", 12), 0);
    cr_assert_eq(my_strncmp("Hello World!", "Hello World", 12), 33);
    cr_assert_eq(my_strncmp("Hello World", "Hello World!", 12), -33);
    cr_assert_eq(my_strncmp("Hello World!", "Hello World!", 5), 0);
}

Test(test_my_strchr, basics)
{
    cr_assert_eq(my_strchr("Hello World!", 'H'), "Hello World!");
    cr_assert_eq(my_strchr("Hello World!", 'z'), NULL);
}

Test(test_clean_str, basics)
{
    char *str = my_calloc(1, 12);
    str = my_strcpy(str, "Hello World!");
    str = clean_str(str, " ");
    cr_assert_str_eq(str, "HelloWorld!");
}

Test(test_my_strcpy, basics)
{
    char *str = "Hello World!";
    char *dest = my_calloc(1, 12);
    cr_assert_eq(my_strcpy(dest, str), dest);
    cr_assert_str_eq(dest, str);
}

Test(test_my_strncpy, basics)
{
    char *str = "Hello World!";
    char *dest = my_calloc(1, 12);
    cr_assert_eq(my_strncpy(dest, str, 5), dest);
    cr_assert_str_eq(dest, "Hello");
}

Test(test_my_strstr, basics)
{
    char *str = "Hello World!";
    str = my_strstr(str, "World");
    cr_assert_str_eq(str, "World!");
}

Test(test_my_strremove, basics)
{
    char *str = "Hello World!";
    str = my_strremove(str, "o");
    cr_assert_str_eq(str, "Hell Wrld!");
}

Test(test_my_strstr_index, basics)
{
    char *str = "Hello World!";
    cr_assert_eq(my_strstr_index(str, "World"), 6);
    cr_assert_eq(my_strstr_index(str, "World!"), 6);
    cr_assert_eq(my_strstr_index(str, "World?"), -1);
}

Test(test_my_strcat_inf, basics)
{
    char *str = my_strcat_inf(4, "Hello", " ", "World", "!");
    cr_assert_str_eq(str, "Hello World!");
}
