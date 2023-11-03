#include "main.h"

/* helper functions */
char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * _realloc - reallocate dynamic memory
 *
 * @ptr: pointer to the old memory block
 * @old_size: size of the old memory block
 * @new_size: size of the new memory block
 *
 * Description: The _realloc() function changes the size of the memory block
 * pointed to by @old_mem_blk to @new_size bytes. The contents will be
 * unchanged in the range from the start of the region up to the minimum of the
 * old and new sizes. If the @new_size is larger than the @old_size, the added
 * memory will not be initialized. If @old_mem_blk is NULL, then the call is
 * equivalent to @malloc(@new_size), for all values of @old_size and @new_size;
 * if @new_size is equal to zero, and @old_mem_blk ptr is not NULL, then the
 * call is equivalent to free(@old_mem_blk).
 *
 * Return: a pointer to the newly allocated memory,
 * or NULL if the request failed
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newMemBlock;
	unsigned int copySize;

	/* Handle the case when ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	/* Handle the case when new_size is zero, equivalent to free(ptr) */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* new_size is equal to old_size, return ptr */
	if (new_size == old_size)
	{
		return (ptr);
	}

	/* copy size based on minimum of old_size and new_size.*/
	copySize = (old_size < new_size) ? old_size : new_size;

	newMemBlock = malloc(new_size); /* Allocate memory for new block */
	if (newMemBlock == NULL)
	{
		return (NULL);
	}

	/* Copy contents from old block to new block */
	_memcpy(newMemBlock, ptr, copySize);

	free(ptr); /* Free old memory block */

	return (newMemBlock);

}


/**
 * _memcpy - copies memory area
 *
 * @dest: destination in memory
 * @src: source
 * @n: number of bytes to copy
 *
 * Return: Pointer to @dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
