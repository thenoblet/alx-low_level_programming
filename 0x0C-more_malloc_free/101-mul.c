#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* helper funnctions */
int is_positive_integer(const char *str);
int multiply(int num1, int num2);


/**
 * main - Program entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Error\n");
        return (98);
    }

    char *num1_str = argv[1];
    char *num2_str = argv[2];

    if (!is_positive_integer(num1_str) || !is_positive_integer(num2_str)) 
    {
        printf("Error\n");
        return 98;
    }

    int num1 = atoi(num1_str);
    int num2 = atoi(num2_str);

    int result = multiply(num1, num2);

    printf("%d\n", result);

    return 0;
}


/**
 * multiply - Multiply two integers.
 * @num1: The first integer.
 * @num2: The second integer.
 *
 * Return: The result of the multiplication.
 */

int multiply(int num1, int num2) 
{
    return (num1 * num2);
}


/**
 * is_positive_integer - Check if a string contains only positive integers.
 * @str: The string to check.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */

int is_positive_integer(const char *str) 
{
    while (*str) 
    {
        if (!isdigit(*str)) 
	    {
            return (0);
        }
        str++;
    }
    return (1);
}
