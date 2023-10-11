#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void (nothing)
 */

void times_table(void)
{
	int product, firstFactor, secondFactor;

	for (firstFactor = 0; firstFactor < 10; firstFactor++)
	{
		for (secondFactor = 0; secondFactor < 10; secondFactor++)
		{
			product = firstFactor * secondFactor;
			if (product > 9)
			{
				_putchar(product / 10 + '0');
				_putchar(product % 10 + '0');
			}
			else
			{
				if (secondFactor != 0)
				{
					_putchar(' ');
				}
				_putchar(product + '0');
			}
			if (secondFactor != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
