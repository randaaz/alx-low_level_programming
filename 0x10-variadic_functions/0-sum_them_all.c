#include "variadic_functions.h"


/**
 * sum_them_all - function that returns the sum of all its parameters
 * @n: Nmber of arguments
 *
 * Return: The sum of all its parameters
*/
int sum_them_all(const unsigned int n, ...)
{
	int r = 0, j = n;
	va_list args;

	if (!n)
		return (0);
	va_start(args, n);
	while (j--)
		r += va_arg(args, int);
	va_end(args);
	return (r);
}
