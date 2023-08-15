#include "main.h"

/**
 * print_times_table - Prints the n times table
 * @n: The number up to which the times table should be printed
 *
 * Description: This function prints the n times table in a grid format.
 * Each cell contains the result of multiplying the row
 * number by the column number
 * The format should be aligned and properly formatted.
*/

void print_times_table(int n)
{
	int row, column, result;

	if (n >= 0 && n <= 15)
	{
		for (row = 0; row <= n; ++row)
		{
			_putchar('0');
			for (column = 1; column <= n; ++column)
			{
				_putchar(',');
				_putchar(' ');

				result = row * column;

				if (result <= 9)
				{
					_putchar(' ');
				}
				if (result <= 99)
				{
					_putchar(' ');
				}
				if (result >= 100)
				{
					_putchar(result / 100 + '0');
					_putchar((result / 10) % 10 + '0');
				}
				else if (reslut >= 10)
				{
					_putchar((result / 10) % 10 + '0');
					_putchar(result % 10 + '0');
				}
		}
			_putchar('\n');
	}
}
}
