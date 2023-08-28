#include "main.h"

/**
 * _memcpy - function that copies memory area
 * @src: source pointer
 * @dest: destination pointer
 * @n: number of bytes
 *
 * Return: pointer to the memory area
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	if (src == NULL || dest == NULL)
	{
		return (NULL);
	}
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
