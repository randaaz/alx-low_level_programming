#include <stdio.h>
#include <stdlib.h>
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
	int len1 = str_len(num1);
	int len2 = str_len(num2);
	int *result;
	int i, j, carry, product;

	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
			carry = product / 10;
			result[i + j + 1] = product % 10;
		}
		result[i + j + 1] = carry;
	}

	for (i = 0; i < len1 + len2; i++)
	{
		if (result[i] != 0)
		{
			break;
		}
	}

	for (; i < len1 + len2; i++)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');

	free(result);
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
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

