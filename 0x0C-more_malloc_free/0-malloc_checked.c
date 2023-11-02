#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 *
 * @b: size of memory 
 *
 * Return: pointer to allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void  *ptr = malloc(b); /* allocate memory */
	if (ptr == NULL)
	{
		exit(98); /* terminate program with status 98 if failed */
	}

	return (ptr);
}

