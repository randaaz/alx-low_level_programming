#include "variadic_functions.h"

/**
 * print_char - Prints a character.
 * @args: A va_list containing the character to be printed.
 *
 * Return: void
 */

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_integer - Prints an integer.
 * @args: A va_list containing the integer to be printed.
 *
 * Return: void
 */

void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a floating-point number.
 * @args: A va_list containing the floating-point number to be printed.
 *
 * Return: void
 */

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string.
 * @args: A va_list containing the string to be printed.
 *
 * Return: void
 */

void print_string(va_list args)
{
	char *sp = va_arg(args, char *);

	printf("%s", (sp ? sp : "(nil)"));
}

/**
 * print_all - Prints data based on a format string.
 * @format: A format string specifying the types of data to be printed.
 * @
*/

void print_all(const char * const format, ...)
{
	va_list args;

	int i = 0, j;
	char *sp = " ";

	struct variable var[]  = {
		{'c', print_char},
		{'i', print_integer},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (var[j].variable)
		{
			if (format[i] == var[j].variable)
			{
				printf("%s", sp);
				var[j].function(args);
				sp = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
