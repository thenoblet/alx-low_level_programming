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
	int count = 0;
	int index, i;

	while (str[count] != '\0')
	{
		count++;
	}

	if (count % 2 == 0)
	{
		index = count / 2;
	}
	else
	{
		index = (count - 1) / 2;
	}

	for (i = index; i < count - 1; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
