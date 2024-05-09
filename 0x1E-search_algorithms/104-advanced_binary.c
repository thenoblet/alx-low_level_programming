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
	int left = 0, right = size - 1;

	if (!array || !size)
		return (-1);
	return (recursive_search(array, left, right, value));
}


/**
* recursive_search - Recursive version of binary search.
* @array: Pointer to the first element of the array to search in.
* @left: Index of first element of portion of array to search in.
* @right: Index of last element of portion of array to search in.
* @value: Value to search for.
* Return: First index where value is located or -1 if not.
*/
int recursive_search(int *array, int left, int right, int value)
{
	int i, mid;

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	mid = (right + left) / 2;
	if (array[mid] == value && (left == right || mid == left || array[mid - 1] <
					value))
		return (mid);
	if (left >= right)
		return (-1);
	if (array[mid] < value)
		return (recursive_search(array, mid + 1, right, value));
	if (array[mid] > value)
		return (recursive_search(array, left, mid - 1, value));
	else
		return (recursive_search(array, left, mid, value));
}
