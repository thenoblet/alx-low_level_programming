#include "dog.h"

/**
 * print_dog - Prints details of a dog structure.
 * @d: Pointer to the dog structure to print.
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		/* If the dog pointer is NULL, return without printing. */
		return;
	}

	/* Print the element of d, or "(nil)" if it's NULL. */
	printf("Name: %s\n", ((d->name) ? d->name : "(nil)"));
	printf("Age: %f\n", ((d->age) ? d->age : 0));
	printf("Owner: %s\n", ((d->owner) ? d->owner : "(nil)"));
}
