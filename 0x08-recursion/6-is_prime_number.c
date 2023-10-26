#include "main.h"

int _isprime(int number, int divisor);

/**
 * is_prime_number - Check if a number is prime.
 *
 * @n: Number to be checked
 *
 * Return: 1 if the number @n is prime, 0 otherwise.
 */

int is_prime_number(int n)
{
	return (_isprime(n, n - 1)); /* Start with the largest possible divisor */
}


/**
 * _isprime - checks if a number is prime
 *
 * @number: number to check
 * @divisor: current divisor
 *
 * Return: 1 if the number @n is prime, 0 otherwise.
 */

int _isprime(int number, int divisor)
{
	if (number <= 1)
	{
		return (0); /* negs(-), 0 and 1 are not prime numbers */
	}
	if (divisor <= 2)
	{
		return (1); /* 2 is a prime number */
	}
	if (!(number % divisor))
	{
		return (0); /* If number is !divisible by divisor, it's prime */
	}

	return (_isprime(number, divisor - 1)); /* check with the next value of i */
}

