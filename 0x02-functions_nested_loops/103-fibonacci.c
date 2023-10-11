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
	long int x = 1, y = 2, z, sum = 2;

	while (1)
	{
		z = x + y;
		if (z > 4000000)
			break;
		if (z % 2 == 0)
			sum += z;
		x = y;
		y = z;
	}
	printf("%ld\n", sum);

	return (0);
}
