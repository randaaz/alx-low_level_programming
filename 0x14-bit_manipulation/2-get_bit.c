#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index, starting from 0 of the bit you want to get.
 *
 * Return: The value of the bit at index index or -1 if an error occured.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int Modified_Version;
	int bit;

	if (index >= sizeof(unsigned int) * 8)
	{
		return (-1);
	}
	Modified_Version = 1UL << index;
	bit = (n & Modified_Version) ? 1 : 0;
	return (bit);
}
