#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase
 *
 * Return: no return value
 */

void print_alphabet_x10(void)
{
	int i;
	char lower;

	for (i = 0; i < 10; i++)
	{
		lower = 'a';
		while (lower <= 'z')
		{
			_putchar(lower++);
		}
		_putchar('\n');
	}
}
