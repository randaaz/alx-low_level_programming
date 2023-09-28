#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: A pointer to the number where the bit will be set.
 * @index: The index, starting from 0, of the bit to set.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int Modified_Version;
	int bit;

	if (index >= sizeof(unsigned int) * 8)
	{
		return (-1);
	}
	Modified_Version = 1UL << index;
	*n |= Modified_Version;
	return (1);
}
