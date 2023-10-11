#include <stdio.h>

#include "main.h"

/**
 * main - entry point
 *
 * Program finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * 
 * @n: parameter
 *
 * Return: Always 0 (success)
 */

void print_fibonacci_sequence(int n);

int main(void)
{
	int n = 99;

	if (n < 1)
	{
		printf("\n");
	}
	else if (n == 1)
	{
		printf("1\n");
	}
	else if (n == 2)
	{
		printf("1, 2\n");
	}
	else
	{
		print_fibonacci_sequence(n - 2);
	}

	return (0);
}


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
