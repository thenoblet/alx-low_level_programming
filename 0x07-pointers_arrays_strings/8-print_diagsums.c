#include "main.h"

/**
 * print_diagsums - prints the diagonal sum of a matrix
 * @a: array
 * @size: array size
 */

void print_diagsums(int *a, int size)
{
	int primary_diagsum = 0;
	int secondary_diagsum = 0;
	int i;

	for (i = 0; i < size; ++i)
	{
		/*  Add elements from the primary diagonal */
		primary_diagsum += a[i * size + i];

		/*  Add elements from the secondary diagonal */
		secondary_diagsum += a[i * size + (size - 1 - i)];
	}

	/* printing sums */
	printf("%d, %d\n", primary_diagsum, secondary_diagsum);
}
