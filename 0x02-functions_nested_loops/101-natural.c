#include <stdio.h>

/**
 * sum - Calculates the sum of all the multiples of 3 or 5
 * below a given number.
 * @The_sum: The upper limit for which the sum is calculated.
 *
 * Return: The sum of the multiples of 3 or 5 below the given limit.
*/

int sum(int The_sum)
{
	 The_sum = 0;
	int i;

	for (i = 0; i < The_sum; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			The_sum += i;
		}
	}
	printf("%d\n", The_sum);
	return (The_sum);
}

/**
 *  main - Entry point
 *
 * Description: prints the sum of all the multiples of 3 or 5 below 1024
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int x = sum(1024);

	printf("%d\n", x);
	return (0);
}
