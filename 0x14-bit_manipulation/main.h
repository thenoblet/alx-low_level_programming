#ifndef MAIN_H
#define MAIN_H

#define is_binary(c) ((c) == '0' || (c) == '1')

#include <stdio.h>
#include <stdlib.h>

unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);

#endif /* MAIN_H */
