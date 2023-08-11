#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: using for loop
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int ran;

	for (ran = 0; ran <= 9; ran++)
	{
		putchar(ran + '0');
	}

	putchar('\n');
	return (0);
}
