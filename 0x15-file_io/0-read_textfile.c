#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Description:
 *   This function reads a specified number of letters from a text file
 *   and writes them to the standard output. It utilizes low-level file
 *   I/O operations using the open, read, and close functions to handle
 *   file operations. Memory is dynamically allocated to store the file
 *   content in a buffer. The content is then written to the standard
 *   output using the write function.
 *
 * Return: The actual number of letters read and printed, or 0 on error.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t bytes_read, bytes_written;

	 /* Check if filename is NULL */
	if (filename == NULL)
		return (0);

	/* Open the file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* Allocate memory for the buffer */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters); /* read file */
	close(fd);

	if (bytes_read == -1) /* Check for read errors */
	{
		free(buffer);
		return (0);
	}

	/* Write to the standard output */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	/* Check for write errors */
	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	free(buffer); /* Free the allocated memory */

	return (bytes_written);
}
