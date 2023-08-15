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
	int row, column;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (column = 0; column <= n; column++)
		{
			int result = row * column;

			if (column == 0)
			{
				printf("%d", result);
			}
			else
			{
				printf(", %3d", result);
			}
		}
		printf("\n");
	}
}
