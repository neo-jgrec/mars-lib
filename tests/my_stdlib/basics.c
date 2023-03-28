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

Test(test_my_strcat_realloc, basics)
{
    char *str = my_calloc(1, 12);
    str = my_strcpy(str, "Hello");
    str = my_strcat_realloc(str, " World!");
    cr_assert_str_eq(str, "Hello World!");
}

Test(test_my_ftoa, basics)
{
    char *str = my_ftoa(3.21, 2);
    cr_assert_str_eq(str, "3.21");
    str = my_ftoa(-3.21, 2);
    cr_assert_str_eq(str, "-3.21");
}

Test(test_my_itoa, basics)
{
    char *str = my_itoa(321);
    cr_assert_str_eq(str, "321");
    str = my_itoa(-321);
    cr_assert_str_eq(str, "-321");
}

Test(test_my_strchr, find_null_character)
{
    char str[] = "hello, world!";
    char *result = my_strchr(str, '\0');
    cr_assert_eq(result, str + 13);
}

Test(test_my_strstr, returns_null_when_substring_not_found) {
    const char *fullstring = "hello world";
    const char *substring = "goodbye";
    char *result = my_strstr(fullstring, substring);
    cr_assert_null(result);
}

Test(test_my_strcmp, one_string_is_null) {
    const char *str1 = NULL;
    const char *str2 = "hello";
    int result = my_strcmp(str1, str2);
    cr_assert_eq(result, -1);
}

Test(test_my_strncmp, one_is_null) {
    const char *str1 = NULL;
    const char *str2 = "hello";
    int result = my_strncmp(str1, str2, 5);
    cr_assert_eq(result, -1);
}

Test(my_memmove, moves_data_correctly_when_destination_is_before_source) {
    char src[] = "hello world";
    char dest[] = "goodbye";
    my_memmove(dest, src, sizeof(src));
    cr_assert_str_eq(dest, "hello world");
}

Test(my_memmove, moves_data_correctly_when_source_is_before_destination) {
    char src[] = "hello world";
    char dest[] = "goodbye";
    my_memmove(src, dest, sizeof(dest));
    cr_assert_str_eq(src, "goodbye");
}

Test(my_memmove, returns_correct_pointer_when_destination_is_before_source) {
    char src[] = "hello world";
    char dest[] = "goodbye";
    char *result = my_memmove(dest, src, sizeof(src));
    cr_assert_eq(result, dest);
}

Test(my_memmove, returns_correct_pointer_when_source_is_before_destination) {
    char src[] = "hello world";
    char dest[] = "goodbye";
    char *result = my_memmove(src, dest, sizeof(dest));
    cr_assert_eq(result, src);
}