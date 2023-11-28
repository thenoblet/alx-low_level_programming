#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Description:
 *   This function creates a file with the specified name and writes the given
 *   text content to it. If the file already exists, it truncates it. The file
 *   is created with read and write permissions only for the owner (0600).
 *
 * Return:
 *   1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t length;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1); /* file is empty, bounce */

	 /**
	  * Open the file with read-write permissions, create if not exists,
	  * truncate if exists
	  */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1); /* File creation failed */

	if (text_content != NULL)
	{
		length = strlen(text_content);

		/* Check for write errors or incomplete write */
		bytes_written = write(fd, text_content, length);
		if (bytes_written == -1 || (size_t)bytes_written != length)
		{
			close(fd);
			return (1); /* Failed to write content to the file */
		}
	}

	close(fd); /* Close the file */

	return (1);
}
