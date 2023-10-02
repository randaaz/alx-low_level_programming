#include "main.h"

/**
 * read_textfile - reads a text file and prints
 * it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. Returns 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int ptr;
	ssize_t b;
	char buffer[_SIZE * 8];

	if (!filename || !letters)
	{
		return (0);
	}
	ptr = open(filename, O_RDONLY);
	if (ptr == -1)
	{
		return (0);
	}
	b = read(ptr, &buffer[0], letters);
	b = write(STDOUT_FILENO, &buffer[0], b);
	close(ptr);
	return (b);
}
