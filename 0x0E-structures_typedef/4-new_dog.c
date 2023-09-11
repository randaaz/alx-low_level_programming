#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _len - Calculate the length of a string.
 * @ptr: The input string.
 *
 * Return: The length of the string.
 */
int _len(const char *ptr)
{
	int l = 0;

	while (ptr[l] != '\0')
	{
		l++;
	}
	return (l);
}

/**
 * new_dog - Creates a new struct dog and copies name and owner.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: Pointer to the newly created struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int i, nl, ol;

	dog_t *new = malloc(sizeof(dog_t));

	if (new == NULL)
	{
		return (NULL);
	}
	nl = _len(name);
	ol = _len(owner);
	new->name = malloc((nl + 1) * sizeof(char));
	new->owner = malloc((ol + 1) * sizeof(char));

	if (new->name == NULL || new->owner == NULL)
	{
		free(new->name);
		free(new);
		return (NULL);
	}

	for (i = 0; i <= nl; i++)
	{
		new->name[i] = name[i];
	}
	for (i = 0; i <= ol; i++)
	{
		new->owner[i] = owner[i];
	}

	new->age = age;

	return (new);
}
