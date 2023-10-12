#include "main.h"

/**
 * print_triangle - prints a triangle
 *
 * Return: Void
 */

void print_triangle(int size)
{
	int height, width;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (height = 1; height <= size; height++)
		{
			for (width = 1; width <= size; width++)
			{
				if ((height + width) <= size)
				{
					_putchar(' ');
				}
				else
				{
					_putchar('#');
				}
			}
			_putchar('\n');
		}
	}
}
