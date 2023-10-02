#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int ptr;
	ssize_t b = 0, l = _len(text_content);

	if (!filename)
	{
		return (-1);
	}
	ptr = open(filename, O_WRONLY | O_APPEND);
	if (ptr == -1)
	{
		return (-1);
	}
	if (l)
	{
		b = write(ptr, text_content, l);
	}
	close(ptr);
	return (b == l ? 1 : -1);
}
