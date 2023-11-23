#ifndef MAIN_H
#define MAIN_H

#define is_binary(c) ((c) == '0' || (c) == '1')

#include <stdio.h>
#include <stdlib.h>

int _putchar(int c);
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);


#endif /* MAIN_H */
