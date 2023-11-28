#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append to the file.
 *
 * Description:
 *   This function appends the specified text content to the end of a file.
 *   The file is opened with write-only permissions, and the content is added
 *   at the end of the file. If the file does not exist or if there are
 *   permission issues, the function returns -1. If the text_content is NULL,
 *   the function returns 1 without modifying the file. The function returns
 *   1 on success after appending the text to the file.
 *
 * Return:
 *   1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t length;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1); /* invalid file name */

	/* Check if text_content is NULL, do not add anything to the file */
	if (text_content == NULL)
		return (1);

	/* Open the file with write-only permissions, append to the end */
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1); /* Failed to open the file */

	length = strlen(text_content);
	bytes_written = write(fd, text_content, length);

	/* Check for write errors or incomplete write */
	if (bytes_written == -1 || (size_t)bytes_written != length)
	{
		close(fd);
		return (-1); /* Failed to append content to the file */
	}

	 /* Close the file */
	close(fd);

	return (1);
}
