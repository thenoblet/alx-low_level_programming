#include <stdio.h>

/**
 * main - entry point
 *
 * Return: Always 1 (Success)
 *
 * Lower level programming - 0x01. C - Variables, if, else, while
 */

int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}

