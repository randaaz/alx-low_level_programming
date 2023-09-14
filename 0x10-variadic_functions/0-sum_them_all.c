#include "variadic_functions.h"

/**
 * sum_them_all - total of parameters.
 * @n: number param
 * @...: numbers
 *
 * Return: total
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list sh;
	int ii = n, total = 0;

	if (!n)
		return (0);

	va_start(sh, n);
	while (ii--)
		total += va_arg(sh, int);
	va_end(sh);

	return (total);
}
