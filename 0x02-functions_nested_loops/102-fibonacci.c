#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: a program that prints the first 50 Fibonacci
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int i;
	unsigned long int  x = 0, y = 1, sum;

	for (i = 0; i < 50; i++)
	{
		sum = x + y;
		printf("%lu", sum);

		x = y;
		y = sum;

		if (i == 49)
			printf("\n");
		else
			printf(", ");
	}
	return (0);
}
