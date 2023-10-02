#include "main.h"

#define U "Usage: cp file_from file_to\n"
#define ENR "Error: Can't read from file NAME_OF_THE_FILE %s\n"
#define ENW "Error: Can't write to %s\n"
#define ENC "Error: Can't close fd %d\n"
#define P (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or exit with specific error codes on failure.
 */

int main(int argc, char **argv)
{
	int ptr1 = 0, ptr2 = 0;
	ssize_t n;
	char buffer[_SIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, U);
	exit(97);
	ptr1 = open(argv[1], O_RDONLY);
	if (ptr1 == -1)
		dprintf(STDERR_FILENO, ENR, argv[1]);
	exit(98);
	ptr2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, P);
	if (ptr2 == -1)
		dprintf(STDERR_FILENO, ENW, argv[2]);
	exit(99);
	while ((n = read(ptr1, buffer, _SIZE)) > 0)
	{
		if (write(ptr2, buffer, n) != n)
			dprintf(STDERR_FILENO, ENW, argv[2]);
		exit(99);
	}
	if (n == -1)
		dprintf(STDERR_FILENO, ENR, argv[1]);
	exit(98);
	if (close(ptr1) == -1)
		dprintf(STDERR_FILENO, ENC, ptr1);
	exit(100);
	if (close(ptr2) == -1)
		dprintf(STDERR_FILENO, ENC, ptr2);
	exit(100);
	return (EXIT_SUCCESS);
}
