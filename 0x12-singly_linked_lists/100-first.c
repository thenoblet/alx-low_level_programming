#include "lists.h"

/**
 * before_main - Constructor function that prints messages before main
 *
 * This function is designated as a constructor using the __attribute__((constructor))
 * attribute, which means it will be automatically called before the main function
 * during program startup. It prints two lines of text to the standard output.
 */

void __attribute__((constructor)) before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
