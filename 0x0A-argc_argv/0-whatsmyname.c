#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: This program will prints its name, followed by a new line.
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);
	(void)argc;
	return (0);
}
