#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the size of various types on the computer
 *
 * Return: Always 0 (Success)
 */
	int main(void)
	{

		printf("size of an char: %lu byte(s)\n", sizeof(char));
		printf("size of an int: %lu byte(s)\n", sizeof(int));
		printf("size of an long: %lu byte(s)\n", sizeof(long int));
		printf("size of an long long: %lu byte(s)\n", sizeof(long long));
		printf("size of a float: %lu byte(s)\n", sizeof(float));

		return (0);

	}
