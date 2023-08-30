#include "main.h"

/**
 * _strlen_recursion - function that returns the length of a string
 * @s: pointer to string
 *
 * Return: length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{

		return (0);
	}
	s++;
	return (1 + _strlen_recursion(s));
}
/**
 * _len - Helper function to check if a string is a palindrome
 * @s: The string to check
 * @len: The length of the string
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int _len(char *s, int len)
{

	if (len <= 1)
	{
		return (1);
	}
	if (s[0] != s[len - 1])
	{
		return (0);
	}
	return (_len(s + 1, len - 2));
}
/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */

int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (_len(s, len));
}
