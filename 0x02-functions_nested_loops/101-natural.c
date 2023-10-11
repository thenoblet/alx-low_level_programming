#include <stdio.h>

/**
 * main - Entry point.
 * Return: always 0 (success).
 *
 */

int main(void)
{
	int sum, i;

	for (i = 0; i < 1024; i++)
	{
		if ((1 % 3 == 0) || (i % 5 == 0))
		sum += i;
	}
	printf("%d\n", sum);

	return (0);
}
