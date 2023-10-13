#include "main.h"

/**
 * print_number - prints an integer
 *
 * @n: parameter
 *
 * Return: Void
 */


void print_number(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		i *= -1;
	}
	if (i / 10)
	{
		/* Recursively call the function with the integer part of i */
		print_number(i / 10);
	}
	_putchar(i % 10 + '0');
}
