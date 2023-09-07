#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: The first string
 * @s2: The second steing
 * @n:first n bytes of s2
 *
 * Return: Pointer to the concatenated string or NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new;
	unsigned int i, j;
	int l1 = 0, l2 = 0, l3 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	for (i = 0; i < s1[i] != '\0'; i++)
		l1++;
	for (i = 0; i < s2[i] != '\0'; i++)
		l2++;
	for (i = 0; s2[i] <= n; i++)
		l3++;
	if (n >= l2)
		l3 = l2;
	else
		l3 = n;
	new = malloc(sizeof(char) * (l1 + l3 + 1));
	if (new == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		new[i] = s1[i];
	for (j = 0; j < l3; j++, i++)
		new[i] = s2[j];
	new[i] = '\0';
	return (new);
}
