#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The starting number
 *
 * Description: This function takes an integer @n as input and prints
 * all natural numbers from @n up to 98, inclusive. If @n is greater
 * than 98, the numbers are printed in decreasing order. The output is
 * formatted with commas and spaces between numbers
*/

void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i != 98)
			{
				_putchar(i / 10 + '0');
				_putchar(i % 10 + '0');
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar(i / 10 + '0');
				_putchar(i % 10 + '0');
				_putchar('\n');
			}
		}
	}
	else
	{
		for (i = n; i >= 98; i--)
		{
			if (i != 98)
			{
				_putchar(i / 10 + '0');
				_putchar(i % 10 + '0');
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar(i / 10 + '0');
				_putchar(i % 10 + '0');
				_putchar('\n');
			}
		}
	}
}
