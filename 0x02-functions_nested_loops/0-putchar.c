#include "main.h"
#include <string.h>

/**
 * main - Entry Point
 *
 * This program prints or outputs "_putchar"
 *
 * Return: Always 1 (Success)
 */

int main(void)
{
	char ch[] = "_putchar";
	int length = strlen(ch);

	int i;

	for (i = 0; i <= length; i++)
	{
		_putchar(ch[i]);
	}
	_putchar('\n');

	return (0);
}
