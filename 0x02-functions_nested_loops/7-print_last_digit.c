#include "main.h"
#include <stdlib.h>

/**
 * print_last_digit - prints the last digit of a number
 *
 * @x: parameter
 *
 * Return: returns value of last digit
 */

int print_last_digit(int x)
{
	int y;

	y = abs(x % 10);
	_putchar(y + '0');
	return (y);
}
