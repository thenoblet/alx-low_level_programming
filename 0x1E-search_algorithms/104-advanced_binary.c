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
* @low: Index of first element of portion of array to search in.
* @high: Index of last element of portion of array to search in.
* @value: Value to search for.
* Return: First index where value is located or -1 if not.
*/
int recursive_search(int *array, int value,
			    size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	mid = (low + high) / 2;
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mid] < value)
			return (binary_search_recursion(array, value,
							mid + 1, high));
		if (array[mid] >= value)
			return (binary_search_recursion(array, value,
							low, mid));
	}

	return (-1);
}
