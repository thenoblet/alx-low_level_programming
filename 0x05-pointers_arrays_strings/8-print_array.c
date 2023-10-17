#include "main.h"

/**
 * print_array - prints an array of integers.
 *
 * @n: parameter input
 * @a: parameter input
 *
 * Return: 0 is success
 */


void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", *(a + i));

		if (i != (n - 1))
		{
			printf(", ");
		}
	}
	printf("\n");
}
