#include "3-calc.h"

/**
 * get_op_func - Get a function pointer based on a given operator.
 *
 * @s: The operator string.
 *
 * This function takes an operator string and returns a function pointer to
 * the corresponding operation function. If the operator is not found in the
 * predefined list of operations, it returns NULL.
 *
 * Return: A function pointer to the operation function,
 * or NULL if not found.
 */

int (*get_op_func(char *s))(int, int)
{
	int i;

	/* An array of operations with their respective function pointers */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL} /* End of the array with NULL terminator */
	};

	i = 0;
	while (ops[i].op != NULL)
	{
		/* Compare the input string with each operator in the array */
		if (strcmp(s, ops[i].op) == 0)
		{
			return (ops[i].f); /* Return the corresponding function pointer */
		}
		++i;
	}

	return (NULL); /* Return NULL if the operator is not found */
}
