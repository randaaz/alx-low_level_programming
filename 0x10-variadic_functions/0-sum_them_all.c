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
	va_list args;
	int i = n, sum = 0;

	if (!n)
		return (0);

	va_start(args, n);
	while (i--)
		sum += va_arg(args, int);
	va_end(args);

	return (sum);
}
