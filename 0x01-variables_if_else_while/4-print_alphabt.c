#include <stdio.h>

/**
 * main - entry point
 * Program that prints the alphabet in lowercase, and then in uppercase,
 * followed by a new line.
 *
 * Return: Always 1 (Success)
 *
 * Lower level programming - 0x01. C - Variables, if, else, while
 */

int main(void)
{
	char alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		if (alpha != 'q' && alpha != 'e')
		{
			putchar(alpha);
		}
	}
	putchar('\n');

	return (0);
}
