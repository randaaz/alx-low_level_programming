#include "main.h"

/**
 *  print_triangle - draws a straight line in the terminal
 * @size: The number of times the character '\' should be printed
*/

void print_triangle(int size)
{
	int i, j, h;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 1; i <= size; i++)
	{
		for (j = size - i; j > 0; j--)
		{
			_putchar(' ');
		}
		for (h = 1; h <= i; h++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
