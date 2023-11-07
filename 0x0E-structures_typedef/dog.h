#ifndef DOG_H
#define DOG_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct dog - defines a struct for storing info. about dogs
 *
 * @name: name of dog
 * @owner: name of dog's owner
 * @age:  age of dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};


/* function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void print_dog(struct dog *d);

/* new variable definition */
typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
