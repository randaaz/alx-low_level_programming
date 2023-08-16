#include "main.h"

/**
 * length - Calculates the number of digits in an integer.
 *
 * @numb: The integer for which the number of digits is calculated.
 * Return: The number of digits in the integer.
*/

int length(int numb)
{
	int l = 0;

	if (!numb)
		return (1);
	while (numb)
	{
		numb = numb / 10;
		l += 1;
	}
	return (l);
}
/**
 * main - Entry point
 * Description: prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	int i, z;
	unsigned long int x = 1,
		      y = 2, sum, mx = 100000000,
		      f1 = 0, f2 = 0, sum1 = 0;

	for (i = 1; i <= 98; i++)
	{
		if (f1 > 0)
		{
			printf("%lu", f1);
		z = length(mx) - 1 - length(x);
		}

		while (f1 > 0 && z > 0)
		{
			printf("%d", 0);
			z--;
		}
		printf("%lu", x);

		sum = (x + y) % mx;
		sum1 = f1 + f2 + (x + y) / mx;
		x = y;
		f1 = f2;
		y = sum;
		f1 = sum1;


		if (i != 98)
			printf(", ");
		else
			printf("\n");
	}
	return (0);
}
