#include "function_pointers.h"

/**
 * print_name - Function that prints a name
 * @name: Pointer to the name to be printed
 * @f: unction pointer to a printing function
 *
 * Return: void
*/

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
