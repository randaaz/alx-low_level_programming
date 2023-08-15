#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Description: This function prints the 9 times table in a grid format.
 * Each cell contains the result of multiplying the row
 * number by the column number
 * The format should be aligned and properly formatted.
*/

void times_table(void)
{
	int row, column, result;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 9; column++)
		{
			result = row * column;
			if (column != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (result >= 10)
			{
				_putchar(result / 10 + '0');
				_putchar(result % 10 + '0');
			}
			else
			{
				if (column != 0)
				{
					_putchar(' ');
				}
				_putchar(result + '0');
			}
		}
		_putchar('\n');
	}
}
