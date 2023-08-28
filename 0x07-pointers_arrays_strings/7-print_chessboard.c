#include "main.h"

/**
 * print_chessboard - that prints the chessboard
 * @a: pointer to a string
 * @[8]: the number of value
 *
 * Return: pointer
 */
void print_chessboard(char (*a)[8])
{
	unsigned int i;
	unsigned int j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);

		}
		_putchar('\n');
	}

}
