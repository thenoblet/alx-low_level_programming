#include "main.h"

/* helper functions */
int countwords(const char *str);
char *copyword(const char *str, int start, int end);

/**
 * strtow - Split a string into words.
 * @str: The input string to split.
 *
i * Return: An array of words, terminated by a NULL pointer.
 */

char **strtow(char *str)
{
	char **words;
	int numwords, i, j;
	int start = 0, end = 0, index = 0, length;

	if (str == NULL || *str == '\0')
		return (NULL); /* Handle invalid input */

	numwords = countwords(str);
	if (numwords == 0)
		return (NULL); /* No words found in the string */

	words = (char **)malloc((numwords + 1) * sizeof(char *));
	if (words == NULL)
	{
		free(words);
		return (NULL); /* memory allocation failure */
	}

	length = strlen(str);

	for (i = 0; i < length; i++)
	{
		if (!isspace(str[i]) && (isspace(str[i + 1]) || str[i + 1] == '\0'))
		{
			end = i + 1;
			words[index] = copyword(str, start, end);
			if (words[index] == NULL)
			{
				for (j = 0; j < index; ++j)
					free(words[j]);
				free(words);
				return (NULL);
			}
			index++;
		}
		else if (!isspace(str[i]) && !isspace(str[i + 1]))
			continue;
		else
			start = i + 1;
	}
	words[index] = NULL;

	return (words);
}


/**
 * countwords - Count the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */

int countwords(const char *str)
{
	int wordcount = 0;
	bool isword = false; /* flag to keep track if we are inside a word */
	int i;

	for (i = 0; str[i] != '\0'; ++i)
	{
		if (isspace(str[i]))
		{
			isword = false;
		}
		else if (!isword)
		{
			isword = true;
			wordcount++;
		}
	}
	return (wordcount);
}


/**
 * copyword - Copy a word from a string.
 * @str: The input string.
 * @start: The start index of the word.
 * @end: The end index of the word.
 *
 * Return: A newly allocated string containing the word.
 */

char *copyword(const char *str, int start, int end)
{
	char *word;
	int length = end - start; /* Calc. length of the word */

	word = (char *)malloc((length + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	/* Copy chars of the word from input string */
	strncpy(word, str + start, length);
	word[length] = '\0'; /*  Null-terminate word */

	return (word);
}
