#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description: The main function checks the number of command-line arguments,
 * opens the source and destination files, calls the copy function,
 * and closes the files.
 *
 * Return: 0 on success, or the corresponding error code on failure
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];

	 /* Check the number of command-line arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY); /* Open the source file for reading */
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open or create the destination file for writing, truncate if it exists */
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	/* Copy the content from file_from to file_to */
	copy(fd_from, fd_to, buffer, argv[1], argv[2]);

	/* Close the file descriptors */
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(100);
	}

	return (0);
}


/**
 * copy - Copies the content of one file to another.
 *
 * @fd_from: The file descriptor for the source file.
 * @fd_to: The file descriptor for the destination file.
 * @buffer: A buffer used for reading from the source file and
 * writing to the destination file.
 * @src: The name of the source file (for error messages).
 * @dest: The name of the destination file (for error messages).
 *
 * Description: The copy function reads from the source file and
 * writes to the destination file, handling errors and providing
 * appropriate error messages.
 */
void copy(int fd_from, int fd_to, char *buffer, const char *src,
		const char *dest)
{
	ssize_t bytes_read, bytes_written;

	/* Continue reading from the source file until no more data is available */
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		/*  Write the read data to the destination file */
		bytes_written = write(fd_to, buffer, bytes_read);

		/* Check for a write error */
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			/* write operation fails, print an error message */
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest);
			exit(99); /* exit with an appropriate error code */
		}
	}

	/* Check for read error */
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

}
