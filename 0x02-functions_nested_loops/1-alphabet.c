#include "main.h"

/**
 * print_alphabet - This function prints the english alphabets in lowercase
 *
 * Return: Always 1 (Success)
 */

void print_alphabet(void)
{
	int lower;

	for (lower = 'a'; lower <= 'z'; lower++)
	{
		_putchar(lower);
	}
	_putchar('\n');

}
