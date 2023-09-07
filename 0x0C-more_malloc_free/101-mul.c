#include "main.h"
#include <stdlib.h>

/**
 * print_error - print Error, followed by a new line
 *
 * Return: void
 */
void print_error(void)
{
	int i;
	char *error_message = "Error\n";

	for (i = 0; i < 5; i++)
	{
		_putchar(error_message[i]);
	}
}

/**
 * print_number - print numbers
 * @n: The number
 *
 * Return: void
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
 * main - Entry point
 * Description: multiplies two positive numbers
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: the result, followed by a new line
 */
int main(int argc, char *argv[])
{
	char *p1, *p2;
	long num1, num2, mul;

	if (argc != 3)
	{
		print_error();
		exit(98);
	}
	num1 = strtol(argv[1], &p1, 10);
	num2 = strtol(argv[2], &p2, 10);
	if (*p1 != '\0' || *p2 != '\0')
	{
		print_error();
		exit(98);
	}
	mul = num1 * num2;
	if (mul == 0)
	{
		_putchar('0');
	} else
	{
		print_number(mul);
	}
	_putchar('\n');
	return (0);
}
