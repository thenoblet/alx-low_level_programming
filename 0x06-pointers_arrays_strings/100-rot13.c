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
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		char c = str[i];

		if (c >= 'a' && c <= 'z')
		{
			str[i] = 'a' + ((c - 'a' + 13) % 26);
		}
		else if (c >= 'A' && c <= 'Z')
		{
			str[i] = 'A' + ((c - 'A' + 13) % 26);
		}
	}

	return (str);
}
