#ifndef VARIADIC_FUNCTIONS
#define VARIADIC_FUNCTIONS

#include <stdarg.h>
#include <stdio.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct variable - Struct variable for specifying
 * format specifiers and functions.
 * @variable: The format specifier character.
 * @function: A function pointer to the corresponding printing function.
 *
 * Description: This struct is used to map format specifier characters to their
 *              respective printing functions for the print_all function.
 */
struct variable
{
	char variable;
	void (*function)(va_list);
};

#endif
