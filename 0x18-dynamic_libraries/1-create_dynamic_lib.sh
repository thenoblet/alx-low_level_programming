#!/bin/bash

gcc -c -fPIC *.c #Compile C source files to object files
gcc -shared -o liball.so *.c # Create shared library

