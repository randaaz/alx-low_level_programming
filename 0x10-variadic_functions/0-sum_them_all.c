#include "variadic_functions.h"

/**
 * sum_them_all - sum of parameters.
 * @n: number param
 * @...: numbers
 *
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int i = n, sum = 0;

	if (!n)
		return (0);

	va_start(args, n);
	while (i--)
		total += va_arg(args, int);
	va_end(args);

	return (sum);
}
