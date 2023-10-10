#include "main.h"

/**
 * print_sign - prints the sign of a number
 *
 * @n: parameter or argument func value
 *
 * Return: 1 if the number is positive, 0 if the number is 0 and
 * return -1 if number is negative
 *
 */

int print_sign(int n)
{
	if (n > 0)
	{	_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
