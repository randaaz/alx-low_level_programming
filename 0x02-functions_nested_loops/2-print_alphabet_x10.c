#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase 10 times
 *
 * Description: This function prints the lowercase alphabet from 'a' to 'z'
 * followed by a new line using the _putchar function 10 times.
 *
 * Return: Always void (no return value)
*/

void print_alphabet_x10(void)
{
	char alphabet = 'a';
	int num = 0;

	while (num < 10)
	{
		while (alphabet <= 'z')
		{
			_putchar(alphabet);
			alphabet++;
		}
		num++;
	}
	_putchar('\n');
}
