#include "variadic_functions.h"


/**
 * sum_them_all - function that returns the sum of all its parameters
 * @n: Nmber of arguments
 *
 * Return: The sum of all its parameters
*/
int sum_them_all(const unsigned int n, ...)
{
        va_list args;
        int i = n, ts = 0;

        if (!n)
                return (0);

        va_start(args, n);
        while (i--)
                ts += va_arg(args, int);
        va_end(args);

        return (ts);
}
