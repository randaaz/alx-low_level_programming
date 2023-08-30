#include "main.h"
/**
 * _sqrt - Helper function for calculating square root recursively
 * @n: The number for which to calculate the square root
 * @x: Current guess for the square root
 *
 * Return: Square root if found, -1 otherwise
*/
int _sqrt(int n, int x);
/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number
 *
 * Return: The natural square root of n, or -1 if n doesn't have one
*/
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0 || n == 1)
	{

		return (n);
	}
	if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (_sqrt(n, 1));
	}
}
/**
 * _sqrt - Helper function for calculating square root recursively
 * @n: The number for which to calculate the square root
 * @x: Current guess for the square root
 *
 * Return: Square root if found, -1 otherwise
*/
int _sqrt(int n, int x)
{
	if ((x + 1) * (x + 1) == n)
	{
		return (x + 1);
	}
	else if ((x + 1) * (x + 1) < n)
	{
		return (_sqrt(n, x + 1));
	}
	else
	{
		return (-1);
	}
}
