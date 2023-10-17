#include "main.h"

/**
 * rev_string - reverses a string
 *
 * @s: parameter
 *
 * Return: void (nothing)
 */

void rev_string(char *s)
{
	int count = 0;
	int i;

	while (s[count] != '\0')
	{
		count++;

	}

	for (i = 0; i < count / 2; i++)
	{
		char temp = s[i];

		s[i] = s[count - i - 1];
		s[count - i - 1] = temp;
	}
}
