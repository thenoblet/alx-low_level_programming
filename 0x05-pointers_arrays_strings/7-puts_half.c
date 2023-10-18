#include "main.h"

/**
 * puts_half -  prints half of a string
 *
 * @str: parameter
 *
 * Return: void
 */

void puts_half(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		i++;
	}

	for (i = (i + 1) / 2; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
