#include <stdio.h>

/**
 * main - Entry point
 *
 * prints the first 50 Fibonacci numbers,
 * starting with 1 and 2
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	long int i, x, y, z;

	x = 1;
	y = 2;

	printf("1, 2, ");
	for (i = 0; i < 48; i++)
	{
		z = x + y;

		printf("%ld", z);

		x = y;
		y = z;

		if (i != 47)
		{
			printf(", ");
		}
	}
	putchar('\n');

	return (0);
}
