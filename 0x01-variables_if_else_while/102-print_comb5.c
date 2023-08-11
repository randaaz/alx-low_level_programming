#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all different two digits
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int ran1;
	int ran2;

	for (ran1 = 0; ran1 < 100; ran1++)
	{
		for (ran2 = ran1 + 1; ran2 < 100; ran2++)
		{
			putchar(ran1 / 10 + '0');
			putchar(ran1 % 10 + '0');
			putchar(' ');
			putchar(ran2 / 10 + '0');
			putchar(ran2 % 10 + '0');

			if (ran1 < 98 || ran2 < 99)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
