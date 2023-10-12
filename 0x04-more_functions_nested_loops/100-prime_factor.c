#include "main.h"
#include <math.h>

/**
* main - Entry point.
*
* program finds and prints the largest prime factor of
* the number 612852475143
*
* Return: Always 0 (success).
*/


int main(void)
{
	long x, y = 612852475143;

	for (x = 2; x < sqrt(y); x++)
	{
		if ((y % x) == 0)
		{
			y /= x;
			x = 1;
		}
	}
	printf("%ld\n", y);

	return (0);
}
