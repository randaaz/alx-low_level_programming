#include "main.h"

/**
 *  print_number - prints an integer
 *  @n : the number we want to print
 *
 *  Return: void
 */

void print_number(int n)
{
	unsigned int nu = n;

	if (nu < 0)
	{
		nu = -n;
	}
	if (nu / 10 != 0)
	{
		print_number(nu / 10);
	}
	_putchar(nu % 10 + '0');
}
