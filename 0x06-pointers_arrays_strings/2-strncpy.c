#include "main.h"

/**
 * _strncpy - function that copies a string
 * @dest: the frist string
 * @src: the secound string
 * @n: the number of character
 *
 * Return: the concatenates two strings
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; n > 0 && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
		n--;
	}
	while (n > 0)
	{
		dest[i] = '\0';
		i++;
		n--;
	}
	return (dest);
}
