#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index..
 * @n: A pointer to the number where the bit will be cleared.
 * @index: The index, starting from 0, of the bit to clear.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int Modified_Version;

	if (index >= sizeof(unsigned int) * 8)
	{
		return (-1);
	}
	Modified_Version = 1UL << index;
	*n &= ~Modified_Version;
	return (1);
}
