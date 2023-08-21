#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: The string to be printed
 *
 * Return: void.
*/

void print_rev(char *s)
{
	int l = 0;

	while (s[l] != '\0')
	{
		l++;
	}
	int i;

	for (i = l - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');

}
