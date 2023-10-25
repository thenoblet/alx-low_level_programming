#include "main.h"

/**
 * _puts_recursion - prints a string recursively
 *
 * @s: string to be printed
 *
 * Return: void
 */

void _puts_recursion(char *s)
{

	if (*s == '\0')
	{
		_putchar('\n'); /* Print a newline char */
		return;
	}
	_putchar(*s); /* Print the current character */
	_puts_recursion((s + 1)); /* move to the next char */
}
