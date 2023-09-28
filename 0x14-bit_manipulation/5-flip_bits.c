#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
		{
			i++;
		}
		n >>= 1;
		m >>= 1;
	}
	return (i);
}
