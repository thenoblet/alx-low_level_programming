#include "dog.h"

/**
 * free_dog - free memory space allocated for dog struct
 *
 * @d: pointer to an instance of the dog structure
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}

	if (d != NULL)
	{
		free(d->name);
		free(d->owner);

		free(d);
	}
}
