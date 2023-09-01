#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - Checks if a character is a digit (0-9).
 * @c: The character to be checked.
 *
 * Return: 1 if @c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * main - Entry point
 *
 * Description: This program adds positive numbers.
 * If no number is passed, it prints 0.
 * If invalid input is detected, it prints Error.
 *
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 if successful, 1 if there are invalid inputs
*/
int main(int argc, char *argv[])
{
	int totalSum = 0;
	int i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!is_digit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		int num = atoi(argv[i]);

		if (num > 0)
		{
			totalSum += num;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", totalSum);

	return (0);
}

