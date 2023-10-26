#include "main.h"

int _sqrt(int number, int squareRoot);

/**
 * _sqrt_recursion - returns the square root of a number
 *
 * @n: number
 *
 * Return: square root of @n
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0 || n == 1)
	{
		return (n);
	}

	return (_sqrt(n, 2));
}

/**
 * _sqrt - gets the square of a number
 *
 * @number: number to calc. sqrt of.
 * @squareRoot: sqrt of @number
 *
 * Return: square root on @target else -1 if @target is not a natural
 * square root
 */

int _sqrt(int number, int squareRoot)
{
	if (squareRoot * squareRoot == number)
	{
		return (squareRoot); /* square root is found */
	}
	if (squareRoot * squareRoot > number)
	{
		return (-1); /* number doesn't have a natural square root */
	}

	return (_sqrt(number, squareRoot + 1)); /* Increment and continue recursion */
}
