#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * count_words - Counts the number of words in a string.
 * @str: The input string
 *
 * Return: The number of words in the string.
 */
static int count_words(const char *str);
static int count_words(const char *str)
{
	int co = 0, iw = 0;

	while (*str)
	{
		if (*str != ' ' && !iw)
		{
			iw = 1;
			co++;
		}
		else if (*str == ' ' && iw)
		{
			iw = 0;
		}
		str++;
	}
	return (co);
}
/**
 * is_space - Checks if a character is a space-like character.
 * @c: The character to check
 *
 * Return: 1 if the character is a space-like character, 0 otherwise.
 */
static int is_space(char c);
static int is_space(char c)
{
	return (c == ' ');
}
/**
 * strtow - Splits a string into words based on spaces, tabs, and newlines.
 * @str: The input string
 *
 * Return: A pointer to an array of strings (words) or NULL on failure.
 */
char **strtow(char *str)
{
	int nw, wi, wl, i;
	char **r;

	if (str == NULL || *str == '\0')
		return (NULL);
	nw = count_words(str);
	if (nw == 0)
		return (NULL);
	r = (char **)malloc((nw + 1) * sizeof(char *));
	if (r == NULL)
		return (NULL);
	wi = 0, wl = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_space(str[i]))
			wl++;
		else if (wl > 0)
		{
			r[wi] = (char *)malloc((wl + 1) * sizeof(char));
			if (r[wi] == NULL)
				return (NULL);
			strncpy(r[wi], &str[i - wl], wl);
			r[wi][wl] = '\0';
			wi++;
			wl = 0;
		}
	}
	if (wl > 0)
	{
		r[wi] = (char *)malloc((wl + 1) * sizeof(char));
		if (r[wi] == NULL)
			return (NULL);
		strncpy(r[wi], &str[strlen(str) - wl], wl);
		r[wi][wl] = '\0';
		wi++;
	}
	r[wi] = NULL;

	return (r);
}
