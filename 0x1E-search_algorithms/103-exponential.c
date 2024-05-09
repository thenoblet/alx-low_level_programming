#include "search_algos.h"

/**
* exponential_search - Searches for a value in a sorted array of integers using
*		       the Exponential search algorithm.
* @array: Pointer to the first element of the array to search in.
* @size: Number of elements in array.
* @value: Value to search for.
* Return: First index where value is located or -1 if not.
*/
int exponential_search(int *array, size_t size, int value)
{
	unsigned int pow_of_2 = 1, size_for_bin, prev_pot = 0;
	int ret;

	if (!array || !size)
		return (-1);

	while (1)
	{
		if (array[pow_of_2] == value)
			return (pow_of_2);
		if (pow_of_2 == size - 1 || array[pow_of_2] > value)
		{
			printf("Value found between indexes [%d] and [%d]\n", prev_pot, pow_of_2);
			size_for_bin = pow_of_2 == 1 ? 2 : pow_of_2 - prev_pot + 1;
			ret = binary_search(&array[prev_pot], size_for_bin, value);
			if (ret != -1)
				ret += prev_pot;
			return (ret);
		}
		printf("Value checked array[%d] = [%d]\n", pow_of_2, array[pow_of_2]);
		prev_pot = pow_of_2;
		pow_of_2 *= 2;
		if (pow_of_2 >= size)
		{
			pow_of_2 = size - 1;
			prev_pot = size - prev_pot;
		}
	}
}


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
