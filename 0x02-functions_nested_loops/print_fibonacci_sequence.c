#include <stdio.h>

/**
 * print_fibonacci_sequence - prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 *
 * @n: parameter
 *
 * Return: Always 0 (success)
 */

void print_fibonacci_sequence(int n)
{
	unsigned long int a = 1, b = 2;
	unsigned long int tmp;

	int i;

	for (i = 1; i < n; i++)
	{
		printf("%lu, ", a);
		tmp = a;
		a = b;
		b = tmp + b;
	}

	printf("%lu\n", a);
}
