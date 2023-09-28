#include "main.h"

/**
 * binary_to_uint - Convert a binary string to an unsigned int.
 * @b: A pointer to the binary string.
 *
 * Return: The Convert number, or 0 if an error occurs.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	while (*b)
	{
		if (*b != '0' && *b != '1')
		{
			return (0);
		}
		n = n * 2 + (*b - '0');
		b++;
	}
	return (n);
}
