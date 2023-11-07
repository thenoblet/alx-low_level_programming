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

#endif /* DOG_H */
