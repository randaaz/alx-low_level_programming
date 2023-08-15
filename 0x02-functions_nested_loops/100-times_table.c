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
	if (n < 0 || n > 15)
	{
		int row, column, result;

		for (row = 0; row <= n; row++)
		{
			for (column = 0; column <= n; column++)
			{
				result = row * column;

				if (column != 0)
				{
					_putchar(',');
					_putchar(' ');
				}
				if (result >= 100)
				{
					_putchar(result / 100 + '0');
					_putchar((result / 10) % 10 + '0');
					_putchar(result % 10 + '0');
				}
				else if (result >= 10)
				{
					_putchar(result / 10 + '0');
					_putchar(result % 10 + '0');
				}
				else
				{
					if (column != 0)
					{
						_putchar(' ');
						_putchar(' ');
					}
					_putchar(result + '0');
				}
			}
			_putchar('\n');
		}
	}
}
