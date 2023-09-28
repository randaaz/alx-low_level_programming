#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int number = sizeof(unsigned long int) * 8 - 1;
	int number_is = 0;
	unsigned long int bit;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while (number >= 0)
	{
		bit = (n >> number) & 1;
		if (bit == 1)
		{
			number_is = 1;
			_putchar('1');
		}
		else if (number_is == 1)
		{
			_putchar('0');
		}
		number--;
	}
}
