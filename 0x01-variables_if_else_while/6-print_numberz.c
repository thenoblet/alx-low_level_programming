#include <stdio.h>

/**
 * main - entry point
 * Prints all single digit numbers of base 10 starting from
 * 0 using putchar.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
