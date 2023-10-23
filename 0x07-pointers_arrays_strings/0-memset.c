#include "main.h"

/**
 * _memset - fills memory with a constant byte
 *
 * @s: string pointer (start of memory block)
 * @b: constant byte
 * @n: number of bytes
 *
 * Return: pointer to the string
 */


char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
