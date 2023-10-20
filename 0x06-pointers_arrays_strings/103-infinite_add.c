#include "main.h"

int _strlen(char *s);

/**
 * infinite_add - adds two integers
 *
 * @n1: first int
 * @n2: second int
 * @r: result buffer
 * @size_r: buffer sizei
 *
 * Return: pointer to result
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = _strlen(n1);
	int len2 = _strlen(n2);
	int carry = 0;
	int start, end;
	int i, j;
	int k = 0;

	if (len1 + 1 > size_r || len2 + 1 > size_r)
	{
		return (0); /* Result cannot fit in r */
	}

	i = len1 - 1;
	j = len2 - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		int digit1 = (i >= 0) ? n1[i] - '0' : 0;
		int digit2 = (j >= 0) ? n2[j] - '0' : 0;
		int sum = digit1 + digit2 + carry;

		if (k + 1 < size_r)
		{
			r[k] = (sum % 10) + '0'; /* Convert sum to a character */
			k++;
		}
		else
		{
			return (0);
		}

		carry = sum / 10;

		i--;
		j--;
	}

	r[k] = '\0'; /* Terminate the result string */


	/* Reverse the result string in-place */
	end = k - 1;
	start = 0;

	while (start < end)
	{
		char temp = r[start];

		r[start] = r[end];
		r[end] = temp;
		start++;
		end--;
	}

	return (r);

}


/**
 * _strlen - returns the length of a string
 * @s: parameter
 * Return: length of a string
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}
