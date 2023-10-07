#include <stdio.h>

/**
 * main - entry point
 *
 * program that prints all the numbers of base 16 in lowercasee
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char alpha;
	int num;

	for (num = 48; num < 58; num++)
	{
		putchar(num);
	}
	for (alpha = 'a'; alpha <= 'f'; alpha++)
	{
		putchar(alpha);
	}
	putchar('\n');

	return (0);
}
