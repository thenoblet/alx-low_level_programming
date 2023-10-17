#include "main.h"

/**
 * puts2 - prints every other char
 *
 * @str: parameter
 *
 * Return: void
 */

void puts2(char *str)
{
	int count = 0;
	int i;

	while (str[count] != '\0')
	{
		count++;
	}

	for (i = 0; i < count; i++)
	{
		if (str[i] % 2 == 0)
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
