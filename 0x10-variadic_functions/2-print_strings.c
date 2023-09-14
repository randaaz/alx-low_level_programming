#include "variadic_functions.h"

/**
 * print_strings - Prints string, followed by a new line
 * @separator: The string to be printed between numbers
 * @n: The number of string passed to the function
 *
 * Return:void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *str;
	va_list args;

	if (!n)
	{
		printf("\n");
		return;
	}
	va_start(args, n);


	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str)
		{
			printf("%s", str);
		}
		else
		{
		printf("(nil)");
		}
		if (separator && i != n - 1)
		{
			printf("%s", separator);
		}
	}
	 printf("\n");
	va_end(args);
}
