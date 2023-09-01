#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_digit - Checks if a character is a digit (0-9).
 * @c: The character to be checked.
 *
 * This function determines whether the given character is a digit or not.
 * It returns 1 if the character is
 * a digit (between '0' and '9'), and 0 otherwise.
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
 * Description: This program will adds positive numbers.
 * the result of the multiplication, followed by a new line
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: 0 if it is Success or 1 does not receive two arguments
 */

int main(int argc, char *argv[])
{
	int totalSum = 0;

	for (int i = 1; i < argc; i++)
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

		totalSum += num;
	}

	printf("%d\n", totalSum);

	return (0);
}
