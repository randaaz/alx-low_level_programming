#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: This program will prints all arguments it receives.
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
