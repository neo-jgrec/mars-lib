/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** basics
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

int my_printf(char *str, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, basics, .init = redirect_all_std)
{
    my_printf("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_printf_float, basics, .init = redirect_all_std)
{
    my_printf("%f", 3.141);
    cr_assert_stdout_eq_str("3.141000");
}

Test(my_printf_float_precision, basics, .init = redirect_all_std)
{
    my_printf("%.2f", 3.14159265358979323846);
    cr_assert_stdout_eq_str("3.14");
}

Test(my_printf_int, basics, .init = redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf_int_precision, basics, .init = redirect_all_std)
{
    my_printf("%5d", 42);
    cr_assert_stdout_eq_str("   42");
}

Test(my_printf_int_precision_zero, basics, .init = redirect_all_std)
{
    my_printf("%05d", 42);
    cr_assert_stdout_eq_str("00042");
}

Test(my_printf_int_precision_zero_neg, basics, .init = redirect_all_std)
{
    my_printf("%05d", -42);
    cr_assert_stdout_eq_str("-0042");
}

Test(my_printf_string, basics, .init = redirect_all_std)
{
    my_printf("%s", "Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_printf_string_precision, basics, .init = redirect_all_std)
{
    my_printf("%.5s", "Hello World!");
    cr_assert_stdout_eq_str("Hello");
}

Test(my_printf_string_precision_zero, basics, .init = redirect_all_std)
{
    my_printf("%.0s", "Hello World!");
    cr_assert_stdout_eq_str("");
}

Test(my_printf_string_precision_zero_neg, basics, .init = redirect_all_std)
{
    my_printf("%5.0s", "Hello World!");
    cr_assert_stdout_eq_str("     ");
}

Test(my_printf_combo, basics, .init = redirect_all_std)
{
    my_printf("%d %s %f", 42, "Hello World!", 3.141);
    cr_assert_stdout_eq_str("42 Hello World! 3.141000");
}

Test(my_printf_convertion_bin, basics, .init = redirect_all_std)
{
    my_printf("%b", 42);
    cr_assert_stdout_eq_str("101010");
}

Test(my_printf_convertion, basics, .init = redirect_all_std)
{
    my_printf("%o, %x, %X, %u", 42, 42, 42, 42);
    cr_assert_stdout_eq_str("52, 2a, 2A, 42");
}

Test(my_printf_scientific, basics, .init = redirect_all_std)
{
    my_printf("%e, %E", 42.42, 42.42);
    cr_assert_stdout_eq_str("4.242000e+01, 4.242000E+01");
}

Test(my_printf_scientific_precision, basics, .init = redirect_all_std)
{
    my_printf("%.2e, %.2E", 42.42, 42.42);
    cr_assert_stdout_eq_str("4.24e+01, 4.24E+01");
}

Test(my_printf_scientific_or_not, basics, .init = redirect_all_std)
{
    my_printf("%g, %G", 42.42, 42.42);
    cr_assert_stdout_eq_str("42.42, 42.42");
}

Test(my_printf_pointer, basics, .init = redirect_all_std)
{
    int *ptr = NULL;
    my_printf("%p", ptr);
    cr_assert_stdout_eq_str("(nil)");
}

Test(my_printf_pointer_2, basics, .init = redirect_all_std)
{
    int *ptr = (int *)42;
    my_printf("%p", ptr);
    cr_assert_stdout_eq_str("0x2a");
}

Test(my_printf_char, basics, .init = redirect_all_std)
{
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf_char_2, basics, .init = redirect_all_std)
{
    my_printf("%c", 42);
    cr_assert_stdout_eq_str("*");
}

Test(my_printf_long, basics, .init = redirect_all_std)
{
    my_printf("%ld", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf_long_long, basics, .init = redirect_all_std)
{
    my_printf("%lld", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf_unsigned_long, basics, .init = redirect_all_std)
{
    my_printf("%lu", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf_unsigned_long_long, basics, .init = redirect_all_std)
{
    my_printf("%llu", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf_percent, basics, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf_percent_2, basics, .init = redirect_all_std)
{
    my_printf("%%d");
    cr_assert_stdout_eq_str("%d");
}

Test(my_printf_simple_percent, basics, .init = redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf_everything, basics, .init = redirect_all_std)
{
    my_printf("%d %s %f %b %o %x %X %u %e %E %g %G %p %c %ld %lld %lu %llu %% %", 42, "Hello World!", 3.141, 42, 42, 42, 42, 42, 42.42, 42.42, 42.42, 42.42, (int *)42, 'a', 42, 42, 42, 42, '%');
    cr_assert_stdout_eq_str("42 Hello World! 3.141000 101010 52 2a 2A 42 4.242000e+01 4.242000E+01 42.42 42.42 0x2a a 42 42 42 42 42 %");
}
