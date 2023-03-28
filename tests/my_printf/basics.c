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


Test(my_printf_test, basic_string_printing) {
    cr_redirect_stdout();
    my_printf("Hello, world!\n");
    cr_assert_stdout_eq_str("Hello, world!\n", "Expected output does not match actual output");
}

Test(my_printf_test, integer_printing) {
    int x = 42;
    cr_redirect_stdout();
    my_printf("The value of x is: %d\n", x);
    cr_assert_stdout_eq_str("The value of x is: 42\n", "Expected output does not match actual output");
}

Test(my_printf_test, float_printing) {
    double pi = 3.14159265359;
    cr_redirect_stdout();
    my_printf("The value of pi is: %f\n", pi);
    cr_assert_stdout_eq_str("The value of pi is: 3.141593\n", "Expected output does not match actual output");
}

Test(my_printf_test, character_printing) {
    char c = 'a';
    cr_redirect_stdout();
    my_printf("The character is: %c\n", c);
    cr_assert_stdout_eq_str("The character is: a\n", "Expected output does not match actual output");
}

Test(my_printf_test, hexadecimal_printing) {
    int x = 255;
    cr_redirect_stdout();
    my_printf("The value of x in hexadecimal is: %x\n", x);
    cr_assert_stdout_eq_str("The value of x in hexadecimal is: ff\n", "Expected output does not match actual output");
}

Test(my_printf_test, octal_printing) {
    int x = 255;
    cr_redirect_stdout();
    my_printf("The value of x in octal is: %o\n", x);
    cr_assert_stdout_eq_str("The value of x in octal is: 377\n", "Expected output does not match actual output");
}

Test(my_printf_test, string_printing_with_width_and_precision) {
    cr_redirect_stdout();
    my_printf("The string is: %10.5s\n", "Hello, world!");
    cr_assert_stdout_eq_str("The string is:      Hello\n", "Expected output does not match actual output");
}

Test(my_printf_test, date_printing) {
    int day = 28, month = 3, year = 2023;
    cr_redirect_stdout();
    my_printf("Today's date is: %02d/%02d/%04d\n", day, month, year);
    cr_assert_stdout_eq_str("Today's date is: 28/03/2023\n", "Expected output does not match actual output");
}

Test(my_printf_test, pointer_printing) {
    int x = 42;
    int *ptr = &x;
    cr_redirect_stdout();
    my_printf("The value of ptr is: %p\n", ptr);
    cr_assert_stdout_eq_str("The value of ptr is: <address_of_ptr>\n", "Expected output does not match actual output");
}

Test(my_printf_test, negative_value_printing) {
    cr_redirect_stdout();
    my_printf("The value of x is: %d\n", -10);
    cr_assert_stdout_eq_str("The value of x is: -10\n", "Expected output does not match actual output");
}
