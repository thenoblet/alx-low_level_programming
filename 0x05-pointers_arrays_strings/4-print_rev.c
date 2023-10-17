#include "main.h"

/**
 * print_rev - prints a string in reverse
 *
 * @s: parameter
 *
 * Return: void
 */


void print_rev(char *s)
{
	int count = 0;
	int i;

	while (s[count] != '\0')
	{
		count++;
	}

	/* iterate through chars in reverse order */
	/* starting from the last char */
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
