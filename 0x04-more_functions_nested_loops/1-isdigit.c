#include "main.h"

/**
 * _isdigit - checks for digits from 0 to 9
 *
 * @c: parameter
 *
 * Return: return 1 if is digit, 0 if otherwise
 */


int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
