#include "main.h"

/**
 * print_buffer -  prints a buffer
 * @b: The buffer
 * @size: The number of bytes to print
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	for (int i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (int j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x%s", (unsigned char)b[i + j], j % 2 == 1 ? " " : "");
			else
				printf("   ");
		}

		printf(" ");

		for (int j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%c", b[i + j] >= 32 && b[i + j] <= 126 ? b[i + j] : '.');
			else
				printf(" ");
		}

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
