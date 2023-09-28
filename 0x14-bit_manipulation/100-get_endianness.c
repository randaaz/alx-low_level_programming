#include "main.h"

/**
 * get_endianness - checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int ck = 1;
	char *ptr = (char *)&ck;

	return (*ptr == 1);
}
