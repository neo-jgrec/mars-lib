/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** Testing failing malloc
*/

#include <criterion/criterion.h>
#include "malloc_wrapper.h"
#include "my_stdlib.h"

Test(test_my_realloc, failing_malloc)
{
    void *ptr = malloc(42);
    break_malloc();
    cr_assert_null(my_realloc(ptr, 42));
    fix_malloc();
}

Test(test_my_calloc, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_calloc(42, 42));
    fix_malloc();
}

Test(test_my_ftoa, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_ftoa(42.42, 42));
    fix_malloc();
}

Test(test_my_itoa, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_itoa(42));
    fix_malloc();
}

Test(test_my_clean_str, failing_malloc)
{
    break_malloc();
    cr_assert_null(clean_str("Hello World!", " "));
    fix_malloc();
}

Test(test_my_strcat_inf, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_strcat_inf(42, "Hello", "World"));
    fix_malloc();
}

Test(test_my_strdup, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_strdup("Hello World!"));
    fix_malloc();
}

Test(test_my_strndup, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_strndup("Hello World!", 42));
    fix_malloc();
}

Test(test_my_strremove, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_strremove("Hello World!", " "));
    fix_malloc();
}

Test(test_my_strcat_realloc, failing_malloc)
{
    break_malloc();
    cr_assert_null(my_strcat_realloc("Hello", "World"));
    fix_malloc();
}
