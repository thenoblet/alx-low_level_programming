#include "search_algos.h"
/**
* binary_search - Searches for a value in a sorted array of integers using the
*                 Binary search algorithm.
* @array: Pointer to the first element of the array to search in.
* @size: Number of elements in array.
* @value: Value to search for.
* Return: Index where value is located or -1 if not.
*/
int binary_search(int *array, size_t size, int value)
{
	unsigned int left = 0, right = size - 1, mid, i;

	if (!array || !size)
		return (-1);
	while (1)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		mid = (right + left) / 2;
		if (array[mid] == value)
			return (mid);
		else if (left == right)
			return (-1);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
		if (left > right)
			return (-1);
	}
}
