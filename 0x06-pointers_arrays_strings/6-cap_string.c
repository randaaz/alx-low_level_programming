#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @sr: the string
 *
 * Return: string in capital words
 */

char *cap_string(char *sr)
{
	int i;
	int symbols = 1;

	for (i = 0; sr[i] != '\0'; i++)
	{
		if (sr[i] == ',' || sr[i] == ';' || sr[i] == '.' ||
				sr[i] == '!' || sr[i] == '?' || sr[i] == '"' || sr[i] == '('
				|| sr[i] == ')' || sr[i] == '{' || sr[i] == '}')
		{
			symbols = 1;
		}
		else if (symbols && sr[i] >= 'a' && sr[i] <= 'z')
		{
			sr[i] -= 32;
			symbols = 0;
		}
		else
		{
			symbols = 0;
		}
	}
	return (sr);
}
