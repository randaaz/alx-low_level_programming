#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * print_error - print Error, followed by a new line
 *
 * Return: void
 */
void print_error()
{
	int i;
	char *error_message = "Error\n";

	for (i = 0; i < 5; i++)
	{
		_putchar(error_message[i]);
	}
}

/**
 * is_digit - check if a string is composed of digits
 * @str: The string to check
 *
 * Return: 1 if composed of digits, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return 0;
		}
		str++;
	}
	return 1;
}

/**
 * multiply_strings - multiply two strings representing numbers
 * @str1: The first number as a string
 * @str2: The second number as a string
 *
 * Return: The result as a string
 */
char *multiply_strings(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int *result = calloc(len1 + len2, sizeof(int));

	if (result == NULL)
	{
		return (NULL);
	}

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int product = (str1[i] - '0') * (str2[j] - '0');
			int sum = product + result[i + j + 1];
			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}

	char *res_str = malloc((len1 + len2 + 1) * sizeof(char));

	if (res_str == NULL)
	{
		free(result);
		return NULL;
	}

	int i = 0;

	while (i < len1 + len2 && result[i] == 0)
	{
		i++;
	}

	if (i == len1 + len2)
	{
		res_str[0] = '0';
		res_str[1] = '\0';
	}
	else
	{
		int j = 0;

		while (i < len1 + len2)
		{
			res_str[j++] = result[i++] + '0';
		}
		res_str[j] = '\0';
	}

	free(result);
	return res_str;
}

int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
		exit(98);
	}

	char *num1 = argv[1];
	char *num2 = argv[2];

	char *result_str = multiply_strings(num1, num2);
	if (result_str == NULL)
	{
		// Handle memory allocation error
		print_error();
		exit(98);
	}

	if (strcmp(result_str, "0") == 0)
	{
		_putchar('0');
	}
	else
	{
		for (int i = 0; result_str[i] != '\0'; i++)
		{
			_putchar(result_str[i]);
		}
	}

	_putchar('\n');
	free(result_str);
	return (0);
}
