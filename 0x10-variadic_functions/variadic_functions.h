#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdio.h>
#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct variable - specifying format specifiers and functions
 * @variable: The format specifier character.
 * @function: A function pointer to the corresponding printing function.
 */
typedef struct variable
{
    char variable;
    void (*function)(va_list);
}oa;

#endif

