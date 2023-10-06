#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 *
 * Return: Always 1 (Success)
 *
 * By: Patrick Noblet Appiah
 * Lower level programming - 0x01. C - Variables, if, else, while
 */

int main(void)
{
	int n;

	n = rand() - RAND_MAX / 2;

	if (n > 0)
	{
		printf("is positive\n");
	}
	else if (n == 0)
	{
		printf("is zero\n");
	}
	else if (n < 0)
	{
		printf("is negative\n");
	}

	return (0);
}
