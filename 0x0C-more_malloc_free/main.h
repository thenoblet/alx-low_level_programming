#ifndef MAIN_H
#define MAIN_H

#define _atoi(c) (c - '0')
/* #define _isdigit(c) ((c >= '0' && c <= '9') ? 1 : 0) */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* MAIN_H */
