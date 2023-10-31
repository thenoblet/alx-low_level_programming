#include "main.h"

/* helper function */
int totalLength(int ac, char **av);

/**
 *  argstostr - concatenates all the arguments of your program.
 *
 *  @ac: Number of command line arguments
 *  @av: CLI arguments
 *
 *  Return: A pointer to a new string, NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	char *newString;
	int i, j;
	int length, position;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calc. total length needed for concatenated string */
	length = totalLength(ac, av);

	/* allocate memory for the concatenated string */
	newString = (char *)malloc(length + 1); /* +1 for the sentinel char */
	if (newString == NULL)
		return (NULL);

	position = 0; /* keep track of the current position within new string */

	for (i = 0; i < ac; ++i)
	{
		if (av[i] != NULL)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				newString[position] = av[i][j];
				position++;
				j++;
			}
			newString[position] = '\n'; /* add newline to separate arguments */
			position++;
		}
	}
	newString[position] = '\0'; /* Null-terminate concatenated string */
	return (newString);
}


/**
 * totalLength - calc. the length of a CLI arg
 *
 * @ac: Number of command line arguments
 * @av: CLI arguments
 *
 * Return: length of CLI args
 */

int totalLength(int ac, char **av)
{
	int length = 0;
	int i, j;

	/* calc. total length needed for concatenated string */
	for (i = 0; i < ac; i++)
	{
		if (av != NULL)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				length++;
				j++;
			}
			length++; /* Add 1 for the newline character */
		}
	}
	return (length);
}
