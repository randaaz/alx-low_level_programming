#include "main.h"
/**
 * _prime - Helper function for checking primality recursively
 * @n: The number to check
 * @x: The current divisor being checked
 * Return: 1 if prime, 0 otherwise
*/
int _prime(int n, int x);
/**
 * is_prime_number - Returns 1 if n is prime, 0 otherwise
 * @n: The number to check
 * Return: 1 if prime, 0 otherwise
*/
int is_prime_number(int n)
{
	return (_prime(n, 2));
}
int _prime(int n, int x)
{
	if (x == n && n > 1 && n % x == 0)
	{
		return (1);
	}
	if (n <= 1 || n % x == 0)
	{

		return (0);
	}
	return (_prime(n, x + 1));
}
