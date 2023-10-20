#include "main.h"

/**
 * rot13 - performs ROT13 encryption
 *
 * @str: string to encrypt
 *
 * Return: pointer to string
 */

char *rot13(char *str)
{
	char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i;
	int j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				/* Replace the character with its ROT13 counterpart */
				str[i] = rot13[j];

				/* Break out of the inner loop once a match is found */
				break;
			}
		}
	}

	return (str);
}
