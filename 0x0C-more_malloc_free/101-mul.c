#include "main.h"
#include <stdlib.h>

/**
 * print_error - print Error, followed by a new line
 */
void print_error()
{
	char *error_message = "Error\n";
	while (*error_message)
	{
		_putchar(*error_message);
		error_message++;
	}
}

/**
 * print_number - print numbers
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		print_number(n / 10);
	}
	_putchar((n % 10) + '0');
}

/**
 * is_digit - Check if a string contains only digits
 * Return: 1 if all characters are digits, 0 otherwise
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
 * main - Entry point
 * Description: multiplies two positive numbers
 * Return: the result, followed by a new line
 */
int main(int argc, char *argv[])
{
	int num1, num2, mul;
	if (argc != 3)
	{
		print_error();
		exit(98);
	}
	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	mul = num1 * num2;
	if (mul == 0)
	{
		_putchar('0');
	}
	print_number(mul);
	_putchar('\n');
	return 0;
}

