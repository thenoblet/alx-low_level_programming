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
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}
