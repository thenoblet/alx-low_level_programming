#!/bin/bash
# generating object files
gcc -std=gnu89 -c *.c
# creates the static libary
ar rc liball.a *.o #OR ar rcs liball.a *.o
# indexing created library 
ranlib liball.a
