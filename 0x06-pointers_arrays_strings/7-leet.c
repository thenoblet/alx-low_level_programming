#include "main.h"

/**
 * leet - encodes a given string
 *
 * @str: string to be encoded
 *
 * Return: pointer to a string
 */

char *leet(char *str)
{
	int i = 0;
	char map[128]; /* map to store char replacements */
	int c;

	for (c = 0; c < 128; c++)
	{
		map[c] = (char)c;
	}

	/* applying replacements */
	map['a'] = map['A'] = '4';
	map['e'] = map['E'] = '3';
	map['o'] = map['O'] = '0';
	map['t'] = map['T'] = '7';
	map['l'] = map['L'] = '1';

	while (str[i] != '\0')
	{
		str[i] = map[(int)str[i]];
		i++;
	}

	return (str);
}
