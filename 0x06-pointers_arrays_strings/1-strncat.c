#include "main.h"

/**
 * _strncat - function that concatenates two strings
 * @dest: the frist string
 * @src: the secound string
 * @n: the number of character
 *
 * Return: the concatenates two strings
 */

char *_strncat(char *dest, char *src, int n);
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; n > 0 && src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
		n--;

	}
	dest[i + j] = '\0';
	return (dest);
}
