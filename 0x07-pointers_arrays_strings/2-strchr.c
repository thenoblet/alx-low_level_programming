#include "main.h"

/**
 * _strchr - locates a char in a string
 *
 * @s: string
 * @c: char to be located
 *
 * Return: pointer to @s
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
		i++;
	}

	return (NULL);
}
