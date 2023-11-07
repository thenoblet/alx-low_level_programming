#include "dog.h"

/* helper functions */
char *_strdup(char *str);

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the dog's owner
 *
 * Return: A pointer to the newly created dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	/* allocate mem. for new dog */
	dog_t *newDog = malloc(sizeof(dog_t));

	if (newDog == NULL)
	{
		return (NULL); /* Memory allocation failed, return NULL */
	}

	/* Duplicate the name and owner strings */
	newDog->name = _strdup(name);
	newDog->owner = _strdup(owner);

	/* Check for memory allocation failures */
	if (newDog->name == NULL || newDog->owner == NULL)
	{
		/* free all allocated memory and return NULL */
		free(newDog->name);
		free(newDog->owner);
		free(newDog);

		return (NULL);
	}

	newDog->age = age;

	return (newDog);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: string
 *
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	size_t size = 0;
	size_t i;
	char *s;

	/* Create a temporary pointer to keep original string unchanged */
	char *temp = str;

	if (str == NULL)
		return (NULL);

	while (*temp)
	{
		temp++;
		size++;
	}
	size += 1; /* Add 1 for the null terminator */

	s = (char *)malloc(size * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		s[i] = str[i];
	}

	return (s); /* return pointer to duplicated string */
}
