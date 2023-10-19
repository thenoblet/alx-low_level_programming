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
		if ((c >= 'a' && c <= 'z'))
		{
			str[i] = ((c - 'a' + 13) % 26) + 'a';
		}
		else if ((c >= 'A' && c <= 'Z'))
		{
			str[i] = ((c - 'A' + 13) % 26) + 'A';
		}
	}

	return (str);
}
