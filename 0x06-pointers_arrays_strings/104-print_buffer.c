#include "main.h"

/**
 * ACCII - Checks if an ASCII character is printable
 * @a: The ASCII character code to check
 *
 * Return: 1 if the character is printable, 0 otherwise
 */

int ACCII(int a)
{
	return (a >= 32 && a <= 126);
}

/**
 * hexa - Prints hexadecimal representation of buffer
 * @b: The buffer
 * @st: Start index
 * @en: End index
 *
 * Return: void
 */

void hexa(char *b, int st, int en)
{
	int i = 0;

	while (i < 10)
	{
		if (i < en)
			printf("%02x", *(b + st + i));
		else
			printf("  ");
		if (i % 2)
			printf(" ");
		i++;
	}

}

/**
 * p_ACCII - Prints printable ASCII representation of buffer
 * @b: The buffer
 * @st: Start index
 * @en: End index
 *
 * Return: void
 */

void p_ACCII(char *b, int st, int en)
{
	int c, i = 0;

	while (i < en)
	{
		c = *(b + i + st);
		if (!ACCII(c))
		c = 46;
		printf("%c", c);
		i++;
	}
}

/**
 * print_buffer - Prints a buffer with hexadecimal and printable ASCII
 * @b: The buffer
 * @size: The number of bytes to print
 *
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int st, en;

	if (size > 0)
	{
		for (st = 0; st < size; st += 10)
		{
			en = (size - st < 10) ? size - st : 10;
			printf("%08x: ", st);
			hexa(b, st, en);
			p_ACCII(b, st, en);
			printf("\n");

		}
	}
	else
		printf("\n");
}
