#include "main.h"

/**
 * array_range - creates an array of integers.
 *
 * @min: minimum value
 * @max: maximum value
 *
 * Description: The array_range() function creates an array of numbers
 * initialized with values @min through @max (inclusive). On error, it
 * returns NULL else a dynamically allocated 1D array containing the
 * values received. The memory is obtained through malloc() and should
 * be freed explicitly after use to avoid potential memory leaks. Also,
 * set the pointer to NULL to avoid dangling pointers.
 *
 * Return: a pointer to the newly created array, else NULL on error.
 */

int *array_range(int min, int max)
{
	int *newArray;
	unsigned int i, numElements;

	if (min > max)
	{
		return (NULL);
	}

	/* Calc. the number of elements in the array */
	numElements = max - min + 1;

	newArray = malloc(sizeof(int) * numElements);
	if (newArray == NULL)
	{
		return (NULL);
	}

	/* fill array with values from min to max */
	for (i = 0; i < numElements; ++i)
	{
		newArray[i] = min + i;
	}

	return (newArray);
}
