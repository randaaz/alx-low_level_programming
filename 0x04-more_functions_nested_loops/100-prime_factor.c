#include "stdio.h"
/**
 * squareRoot - Calculate the square root of a number using the
 * Babylonian method
 * @b: The number for which the square root is to be calculated
 *
 * Return: The calculated square root of the number 'b'
*/

double squareRoot(double b)
{
	double c = 0;
	double d = b / 2;

	while (d != c)
	{
		c = d;
		d = (b / c + c) / 2;
	}
	return (d);
}
/**
 * The_largest_prime_factors - the largest prime factor
 * of the number 612852475143, followed by a new line
 * @numb: the largest prime factor of the number 612852475143
 *
*/
void  The_largest_prime_factors(long int numb)
{
	int pn, large;

	while (numb % 2 == 0)
	{
		numb = numb / 2;
	}
	for (pn = 3; pn <= squareRoot(numb); pn += 2)
	{
		while (numb % 3 == 0)
		{
			numb = numb / pn;
			large = pn;
		}
	}
	if (numb > 2)
	{
		large = numb;
		printf("%d", large);
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	The_largest_prime_factors(612852475143);
	return (0);
}
