#include "main.h"

/**
 * _len - Calculates the length of a string.
 * @c: The input string.
 *
 * Return: The length of the string.
 */

int _len(char *c)
{
	int j = 0;

	if (!c)
	{
		return (0);
	}
	while (*c++)
	{
		j++;
	}
	return (j);
}

/**
 * create_file - creates a file
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int ptr;
	ssize_t b = 0, l = _len(text_content);

	if (!filename || !text_content)
	{
		return (-1);
	}

	ptr = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (ptr == -1)
	{
		return (-1);
	}

	if (l)
	{
		b = write(ptr, text_content, l);
	}
	close(ptr);
	return ((b == l) ? 1 : -1);
}
