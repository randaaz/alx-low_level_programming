#include "main.h"
/**
 * print_number -  prints an integer
 * @n: The number
*/

void print_number(int n)
{
	unsigned int numb = n;

	if (n < 0)
	{
		_putchar('-');
		numb = -numb;
	}
	if ((numb / 10) > 0)
	{
		print_number(numb / 10);
	}
	_putchar((numb % 10) + '0');

}
