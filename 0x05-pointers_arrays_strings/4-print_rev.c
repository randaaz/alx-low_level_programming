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
	 int i;

	while (s[l] != '\0')
	{
		l++;
	}
	for (i = l - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');

}
