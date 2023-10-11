#include <stdio.h>

#include "main.h"

/**
 * main - entry point
 *
 * Program finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 *
 * Return: Always 0 (success)
 */


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
