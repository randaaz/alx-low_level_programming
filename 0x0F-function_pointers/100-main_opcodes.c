#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints opcodes of its own main function.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int num_b, i;
	unsigned char *p;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	num_b = atoi(argv[1]);
	if (num_b < 0)
	{
		printf("Error\n");
		exit(2);
	}
	p = (unsigned char *)main;
	for (i = 0; i < num_b; i++)
	{
		printf("%02hhx%s", p[i]);

		if (i < num_b - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
