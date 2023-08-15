#include <stdio.h>

/**
 * main - Entry point
 *
 * Description:  finds and prints the sum of the even-valued
 * terms, followed by a new line
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	unsigned long int x = 0, y = 1, sum;
	float sum1;

	while (1)
	{
		sum = x + y;

		if (sum > 4000000)
			break;
		if ((sum % 2) == 0)
			sum1 += sum;
		x = y;
		y = sum;

	}
	printf("%.0f\n", sum1);
	return (0);
}
