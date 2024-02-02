#include "hash_tables.h"
/**
* key_index - Returns hash as index of an array.
* @key: String to hash.
* @size: Size of the array.
* Return: Index of the array for the given key.
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
