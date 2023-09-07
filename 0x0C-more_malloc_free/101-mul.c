#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * print_error - prints Error, followed by a new line
 */
void print_error(void)
{
	char *error_message = "Error\n";

	while (*error_message)
		_putchar(*error_message++);
}

/**
 * print_number - prints numbers
 * @n: The number as a string
 */
void print_number(char *n)
{
	while (*n == '0' && *(n + 1) != '\0')
		n++;
	while (*n)
		_putchar(*n++);
}

/**
 * multiply - multiplies two strings representing numbers
 * @num1: First number as a string
 * @num2: Second number as a string
 * Return: Result of the multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_mul = len1 + len2;
	char *result = malloc(len_mul * sizeof(char));
	int i, j, n1, n2, sum;

	if (!result)
		return (NULL);

	for (i = 0; i < len_mul; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + (result[i + j + 1] - '0');
			result[i + j + 1] = (sum % 10) + '0';
			result[i + j] += sum / 10;
		}
	}

	if (result[0] == '0')
		result++;

	return (result);
}
/**
 * main - Entry point
 * Description: Multiplies two positive numbers
 * @argc: The number of arguments
 * @argv: The array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		print_error();
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];

	while (*num1 == '0' && *(num1 + 1) != '\0')
		num1++;
	while (*num2 == '0' && *(num2 + 1) != '\0')
		num2++;

	if (*num1 == '\0' || *num2 == '\0')
		_putchar('0');
	else
	{
		result = multiply(num1, num2);
		if (!result)
		{
			print_error();
			exit(98);
		}
		print_number(result);
		free(result);
	}

	_putchar('\n');

	return (0);
}
