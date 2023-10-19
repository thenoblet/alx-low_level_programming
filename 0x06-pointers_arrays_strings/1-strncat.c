#include "main.h"

/**
 * _strncat - concatenate two strings
 *
 * @dest: destination string
 * @src: source string
 * @n: no. of bytes to be copied
 *
 * Return: dest string
 */

char *_strncat(char *dest, char *src, int n)
{
	int destLen = 0;
	int i = 0;

	while (dest[destLen] != '\0')
	{
		destLen++;
	}

	while (i < n && src[i] != '\0')
	{
		dest[destLen] = src[i];
		destLen++;
		i++;
	}
	dest[destLen] = '\0';

	return (dest);
}
