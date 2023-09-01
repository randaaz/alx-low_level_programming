#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Description: This program will adds positive numbers.
 * the result of the multiplication, followed by a new line
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: 0 if it is Success or 1 does not receive two arguments
 */

int main(int argc, char *argv[])
{
	int i;
	int totalSum = 0;

	for (i = 1; i < argc; i++)
	{
		char *j = argv[i];

		for (; *j; j++)
		{
			if (*j < '0' || *j > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		totalSum += atoi(argv[i]);
	}

	printf("%d\n", totalSum);

	return (0);
}
