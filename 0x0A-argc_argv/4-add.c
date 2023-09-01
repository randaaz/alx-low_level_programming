#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - Checks if a character is a digit (0-9).
 * @c: The character to be checked.
 *
 * This function determines whether the given character is a digit or not.
 * It returns 1 if the character is
 * a digit (between '0' and '9'), and 0 otherwise.
 *
 * Return: 1 if @c is a digit, 0 otherwise.
 */
int main(int argc, char *argv[])
{
        int i;

        int totalSum = 0;
	char *j = argv[argc];

        for (i = 1; i < argc; i++)
        {
                for (; *j; j++)
                {
                        if (*j < '0' || *j > '9')
                        {
                                printf("Error\n");
                                return (1);
                        }
                }

                totalSum += atoi(argv[i]);
        }

        printf("%d\n", totalSum);

        return (0);
}
