#ifndef VARIADIC_FUNCTIONS
#define VARIADIC_FUNCTIONS

#include <stdarg.h>
#include <stdio.h>

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_char(va_list args);
void print_integer(va_list args);
void print_float(va_list args);
void print_string(va_list args);

/**
 * struct variable - Struct variable
 * @variable: The variable character
 * @function: The function pointer taking a va_list argument
 *
 * Description: This struct defines a variable character and a function pointer
 *              to a function that takes a va_list argument.
 */

struct variable
{
    char variable;
    void (*function)(va_list);
};

#endif
