#include "function_pointers.h"


/**
 * array_iterator - Apply a function to each element of an integer array.
 *
 * @array: The integer array to iterate over.
 * @size: The number of elements in the array.
 * @action: A function pointer to the custom action
 * to be applied to each element.
 *
 * This function iterates over the given integer array and calls the custom
 * function pointed to by `action` on each element.
 *
 * @note The function checks for valid 'size', 'array', and 'action' pointers
 * before performing the iteration.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* Check if 'size', 'array', and 'action' are valid */
	if (!size || array == NULL || action == NULL)
	{
		return;
	}

	/* Iterate over the array and apply action to each element. */
	for (i = 0; i < size; ++i)
	{
		action(array[i]);
	}
}
