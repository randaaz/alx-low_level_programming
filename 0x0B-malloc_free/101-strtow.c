#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * count_words - Counts the number of words in a string.
 * @str: The input string
 *
 * Return: The number of words in the string.
 */
static int count_words(const char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (*str != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ' && in_word)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}
/**
 * is_space - Checks if a character is a space-like character.
 * @c: The character to check
 *
 * Return: 1 if the character is a space-like character, 0 otherwise.
 */
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
	int num_words, word_index, word_length, i;
	char **result;

	if (str == NULL || *str == '\0')
		return (NULL);
	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);
	result = (char **)malloc((num_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	word_index = 0, word_length = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_space(str[i]))
			word_length++;
		else if (word_length > 0)
		{
			result[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
			if (result[word_index] == NULL)
				return (NULL);
			strncpy(result[word_index], &str[i - word_length], word_length);
			result[word_index][word_length] = '\0';
			word_index++;
			word_length = 0;
		}
	}
	if (word_length > 0)
	{
		result[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
		if (result[word_index] == NULL)
			return (NULL);
		strncpy(result[word_index], &str[strlen(str) - word_length], word_length);
		result[word_index][word_length] = '\0';
		word_index++;
	}
	result[word_index] = NULL;

	return (result);
}
