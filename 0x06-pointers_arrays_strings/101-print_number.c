#include "main.h"

/**
 *  print_number - prints an integer
 *  @n : the number we want to print
 *
 *  Return: void
 */

void print_number(int n)
{

	if (n < 0)
	{

		n = -n;
		_putchar('-');
	}
	if (n / 10 != 0)
	{
		print_number(n / 10);
	}
	_putchar(n % 10 + '0');
}
