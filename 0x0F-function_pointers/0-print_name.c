#include "function_pointers.h"


/**
 * print_name - Print a name using a custom print function.
 *
 * @name: The name to be printed.
 * @f: A function pointer to a custom print function.
 *
 * This function takes a name and a function pointer
 * to a custom print function.
 * It calls the custom print function to print the name.
 */

void print_name(char *name, void (*f)(char *))
{
	/* Check if 'name' and 'f' are not NULL */
	if (name && f != NULL)
	{
		/* call the custom print func. (pointed to by f) with name as argument */
		f(name);
	}
}
