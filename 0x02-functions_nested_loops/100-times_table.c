#include "main.h"

/**
 * print_times_table - Prints the times table from 0 to n.
 *
 * @n: parameter
 *
 */

void print_times_table(int n)
{
	if (n >= 0 && n <= 15)
	{
		int product, c, i;

		for (c = 0; c <= n; c++)
		{
			for (i = 0; i <= n; i++)
			{
				product = i * c;
				if (product > 99)
				{
					_putchar(product / 100 + '0');
					_putchar(product % 100 / 10 + '0');
					_putchar(product % 100 % 10 + '0');
				}
				else if (product > 9)
				{
					_putchar(' ');
					_putchar(product / 10 + '0');
					_putchar(product % 10 + '0');
				}
				else
				{
					if (i != 0)
					{
						_putchar(' ');
						_putchar(' ');
					}
					_putchar(product + '0');
				}
				if (i != n)
				{
					_putchar(',');
					_putchar(' ');
				}
			}
			_putchar('\n');
		}
	}
}
