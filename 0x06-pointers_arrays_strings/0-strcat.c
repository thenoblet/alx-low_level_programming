#include "main.h"

/**
 * _strcat - concatenate strins
 *
 * @dest: destination string
 * @src: string to append (source string)
 *
 * Return: destination string
 */


char *_strcat(char *dest, char *src)
{
	int destLen = 0;
	int i = 0;

	while (dest[destLen] != '\0')
	{
		destLen++;
	}

	while (src[i] != '\0')
	{
		dest[destLen] = src[i];
		destLen++;
		i++;
	}
	dest[destLen] = '\0';

	return (dest);

}
