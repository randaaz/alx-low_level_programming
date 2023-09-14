#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct format_specifier - Specifies format specifiers and corresponding functions.
 * @specifier: The format specifier character.
 * @printer: A function pointer to the corresponding printing function.
 */
typedef struct format_specifier
{
    char specifier;
    void (*printer)(va_list);
} format_specifier_t;

#endif /* VARIADIC_FUNCTIONS_H */

