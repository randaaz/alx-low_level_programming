#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @n: the input string
 *
 * Return: the encoded string
 */

char *rot13(char *n)
{
	char *rep = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *repw = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; rep[j] != '\0'; j++)
		{
			if (n[i] == rep[j])
			{
				n[i] = repw[j];
				break;

			}
		}
	}
	return (n);
}
