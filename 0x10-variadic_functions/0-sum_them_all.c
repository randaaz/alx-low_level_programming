#include "variadic_functions.h"

/**
 * sum_them_all - sum of all its parameters
 * @n: Number of argument
 *
 * Return:  sum of all its parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	va_list args;

	va_start(args, n);
	for (i = 0, sum = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return (sum);

}
