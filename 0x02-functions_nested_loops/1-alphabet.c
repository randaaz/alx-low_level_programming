#include "main.h"
/**
 * print_alphabet - Prints the alphabet in lowercase, followed by a new line
 *
 * Description: This function prints the lowercase alphabet from 'a' to 'z'
 * followed by a new line using the _putchar function.
 *
 * Return: Always void (no return value)
*/

void print_alphabet(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		_putchar(alphabet);
		alphabet++;
	}
	_putchar('\n');
}
