#include "main.h"

/**
 * leet - encodes a string into 1337
 * @n: the input string
 *
 * Return: the encoded string
 */

char *leet(char *n)
{
	char *rep = "AEOTL";
	char *repw = "43071";
	int i, j;

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; rep[j] != '\0'; j++)
		{
			if (n[i] == rep[j] || n[i] == rep[j] + 32)
			{
				n[i] = repw[j];
				break;

			}
		}
	}
	return (n);
}
