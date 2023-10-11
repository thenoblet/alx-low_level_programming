#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 *
 * @x: parameter or argument
 *
 * Return: Abs value of the number.
 */

int _abs(int x)
{
	if (x < 0)
	{
		x *= -1;
		return (x);
	}

	return (x);
}

