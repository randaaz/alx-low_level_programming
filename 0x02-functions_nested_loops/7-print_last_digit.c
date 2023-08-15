#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n: The number to get the last digit of.
 *
 * Return: The last digit of n.
*/

int print_last_digit(int n)
{
	int last = n % 10;

	if (n < 0)
	{
		last = -last;
	}
	else
	{
		last = last;
	}
	_putchar(last + '0');
	return (last);
}
