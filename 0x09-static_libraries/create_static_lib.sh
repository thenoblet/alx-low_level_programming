#!/bin/bash
# generating object files
gcc -c *.c
# creates the static libary
ar rc liball.a *.o
# indexing created library 
ranlib liball.a
