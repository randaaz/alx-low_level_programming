#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 if successful, otherwise an error code
 */

int main(int argc, char *argv[])
{
	int num1, num2, res;
	int (*p)(int, int);
	char *ptr;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	ptr = argv[2];

	p = get_op_func(ptr);

	if (p == NULL)
	{
		printf("Error\n");
		return (99);
	}
	if ((*ptr == '/' || *ptr == '%') && num2 == 0)
	{
		printf("Error\n");
		return (100);
	}

	res = (*p)(num1, num2);
	printf("%d\n", res);

	return (0);
}
