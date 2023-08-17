#include "main.h"

/**
 * more_numbers - Prints the numbers in lowercase 10 times
 *
 * Description: This function prints the  numbers from '0' to '9'
 * followed by a new line using the _putchar function 10 times.
 *
 * Return: Always void (no return value)
*/

void more_numbers(void)
{
	int num = 0;
	int i = 0;

	while (num < 10)
	{
		while (num < 14)
		{
			if (num <= 9)
			{
				_putchar(num / 10 + '0');
				_putchar(num % 10 + '0');
			}
			else
			{
				_putchar(num + '0');
			}
			num++;
		}
		_putchar('\n');
		i++;
	}
}
