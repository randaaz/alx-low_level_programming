#include "lists.h"

void __attribute__((constructor)) print_m();

/**
 * print_m - Print message before main function is executed
 */

void print_m(void)
{
	printf("You're beat! and yet, you must allow,\n
			I bore my house upon my back!\n");
}
