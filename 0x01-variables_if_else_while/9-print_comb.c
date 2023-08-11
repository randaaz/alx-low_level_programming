#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: using while loop
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int numbers = 0;

	while (numbers <= 9)
	{
		putchar(numbers + '0');

		if (numbers < 9)
		{
			putchar(',');
			putchar(' ');
		}
		numbers++;
	}
}
