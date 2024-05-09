#include "search_algos.h"

/**
* interpolation_search - Searches for a value in a sorted array of integers
*				using the Interpolation search algorithm.
* @array: Pointer to the first element of the array to search in.
* @size: Number of elements in array.
* @value: Value to search for.
* Return: First index where value is located or -1 if not.
*/

int interpolation_search(int *array, size_t size, int value)
{
	unsigned int low = 0, high = size - 1, pos;

	if (!array || size == 0)
		return (-1);
	while (1)
	{
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
			(value - array[low]));
		printf("Value checked array[%d] ", pos);
		if (pos >= size)
		{
			printf("is out of range\n");
			return (-1);
		}
		else
			printf("= [%d]\n", array[pos]);
		if (array[pos] == value)
			return (pos);
		if (low == high)
			return (-1);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
}

