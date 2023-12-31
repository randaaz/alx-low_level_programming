#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees memory allocated for a struct dog.
 * @d: Pointer to a struct dog to be freed.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
