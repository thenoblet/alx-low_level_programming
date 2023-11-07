#include "dog.h"

/**
* init_dog - Initialises a variable of type struct dog.
*
* @d: Pointer to dog structure.
* @name: Name of the dog.
* @age: Age of the dog.
* @owner: Owner of the dog.
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}


