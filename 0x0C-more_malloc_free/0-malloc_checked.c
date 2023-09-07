#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked -  allocates memory using malloc
 * @b: the number of bytes of memory
 *
 * Return: a pointer to the allocated memory block if malloc successfully
 * and 98 if malloc fails
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		exit(98);

	}
	return (ptr);
}
