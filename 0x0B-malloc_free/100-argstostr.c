#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: number of arguments
 * @av: array of argument strings
 *
 * Return: a pointer to a new string containing
 * concatenated arguments, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, l = 0, tl = 0;
	char *new;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			l++;
		}
		tl += l + 1;
		l = 0;
	}
	new = (char *)malloc(sizeof(char) * tl + 1);

	if (new == NULL)
		return (NULL);

	for (i = 0, tl = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			new[tl] = av[i][j];
			tl++;
		}
		new[tl] = '\n';
		tl++;
	}

	new[tl] = '\0';

	return (new);
}
