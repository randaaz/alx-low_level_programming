#include <stdio.h>
#nclude <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * Description: Multiplies two positive numbers
 * @argc: The number of arguments
 * @argv: The array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int i;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i] != '\0'; i++)
	{
		if (!is_valid_digit(num1[i]))
		{
			printf("Error\n");
			return (98);
		}
	}

	for (i = 0; num2[i] != '\0'; i++)
	{
		if (!is_valid_digit(num2[i]))
		{
			printf("Error\n");
			return (98);
		}
	}

	if (num1[0] == '0' || num2[0] == '0')
	{
		printf("0\n");
		return (0);
	}

	multiply(num1, num2);

	return (0);
}
/**
 * is_valid_digit - Check if a character is a valid digit
 * @c: The character to check
 * Return: 1 if valid, 0 if not
 */

int is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}
/**
 * multiply - Multiply two positive numbers
 * @num1: The first number as a string
 * @num2: The second number as a string
 */
void multiply(char *num1, char *num2)
{
	int l1 = str_len(num1);
	int l2 = str_len(num2);
	int *res;
	int i, j, cy, pro;

	res = calloc(l1 + l2, sizeof(int));
	if (res == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = l1 - 1; i >= 0; i--)
	{
		cy = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			pro = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1] + cy;
			cy = pro / 10;
			res[i + j + 1] = pro % 10;
		}
		res[i + j + 1] = cy;
	}

	for (i = 0; i < l1 + l2; i++)
	{
		if (res[i] != 0)
		{
			break;
		}
	}

	for (; i < l1 + l2; i++)
	{
		_putchar(res[i] + '0');
	}
	_putchar('\n');

	free(res);
}
/**
 * str_len - Calculate the length of a string.
 * @str: The string to calculate the length of.
 *
 * Description: This function takes a pointer to a character array (string) as
 * input and calculates the length of the string by iterating through it until
 * the null terminator ('\0') is encountered. It counts each character until
 * the end of the string is reached, and the count represents the length of the
 * string.
 *
 * Return: The length of the string (number of characters) excluding the null
 * terminator.
 */
int str_len(char *str)
{
	int l = 0;

	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}
