#include "function_pointers.h"

/**
 * int_index - Search for an integer in an array
 * using a custom comparison function.
 *
 * @array: The integer array to search in.
 * @size: The number of elements in the array.
 * @cmp: A function pointer to the custom comparison function.
 *
 * This function searches for an integer in the given array using
 * the custom comparison function 'cmp'.
 * It returns the index of the first matching element.
 *
 * @note The function checks if 'size' is valid and whether 'array' and 'cmp'
 * are not NULL pointers. If 'size' is zero or less, or if 'array' or 'cmp'
 * is NULL, the function returns -1 to indicate no match was found.
 *
 * Return: The index of the first matching element,
 * or -1 if no match is found.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
	{
		return (-1);
	}

	if (array != NULL || cmp != NULL)
	{
		for (i = 0; i < size; ++i)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}

