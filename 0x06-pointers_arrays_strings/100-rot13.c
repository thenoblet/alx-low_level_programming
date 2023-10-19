#include "main.h"

/**
 * rot13 - performs ROT13 encryption
 *
 * @str: string to encrypt
 *
 * Return: pointer to the encrypted string @s
 */

char *rot13(char *str)
{
	char c;
	int i;

	for (i = 0; (c = str[i]) != '\0'; i++)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
			{
				str[i] = c + 13;
			}
			else
			{
				str[i] = c - 13;
			}
		}
	}

	return (str);
}
