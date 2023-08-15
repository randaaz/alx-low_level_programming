#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the sum of all the multiples of 3 or 5 below 1024
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int The_sum = 0;

	for (int i = 0; i < 1024; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			The_sum += i;
		}
	}
	printf("%d\n", The_sum);
	return (0);
}
