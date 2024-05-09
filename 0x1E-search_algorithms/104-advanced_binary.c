#include "search_algos.h"

/**
* advanced_binary - Searches for a value in a sorted array of integers using
*			the Binary search algorithm.
* @array: Pointer to the first element of the array to search in.
* @size: Number of elements in array.
* @value: Value to search for.
* Return: Index where value is located or -1 if not.
*/
int advanced_binary(int *array, size_t size, int value)
{
	/* Edge case: array is empty or NULL */
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	/* Call the recursive binary search function */
	return (recursive_binary_search(array, 0, size - 1, value));
}

/**
 * recursive_binary_search - Searches recursively for a target value in a
 * sorted array of integers using binary search.
 * @arr: A pointer to the first element of the [sub]array to search.
 * @start_index: The starting index of the [sub]array to search.
 * @end_index: The ending index of the [sub]array to search.
 * @target: The value to search for.
 *
 * Return: If the target value is not present, returns -1. Otherwise, returns
 * the index where the target value is located.
 */
int recursive_search(int *arr, size_t start_index, size_t end_index,
		int target)
{
	size_t middle_index;

	/* Base case: Should value not be found */
	if (end_index < start_index)
	{
		return (-1);
	}

	printf("Searching in array: ");
	for (middle_index = start_index; middle_index < end_index;
			middle_index++)
	{
		printf("%d, ", arr[middle_index]);
	}
	printf("%d\n", arr[middle_index]);

	/* Compute the index */
	middle_index = start_index + (end_index - start_index) / 2;

	/* Should the value be found, return it.. */
	if (arr[middle_index] == target && (middle_index == start_index ||
				arr[middle_index - 1] != target))
	{
		return (middle_index);
	}

	/* Search the left half */
	if (arr[middle_index] >= target)
	{
		return (recursive_search(arr, start_index, middle_index, target));
	}

	/* Search the right half */
	return (recursive_search(arr, middle_index + 1, end_index, target));
}
