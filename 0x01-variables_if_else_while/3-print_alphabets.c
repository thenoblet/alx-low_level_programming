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
	char lower;
	char upper;

	for (lower = 'a'; lower <= 'z'; lower++)
	{
		putchar(lower);
	}

	for (upper = 'A'; upper <= 'Z'; upper++)
	{
		putchar(upper);
	}
	putchar('\n');

	return (0);
}


