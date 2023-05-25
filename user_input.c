#include "simple_shell.h"

/**
 * getline_wrapper - Reads a line of input from a stream.
 *
 * @lineptr: Pointer to the buffer storing the line.
 * @n: Pointer to the size of the buffer.
 * @stream: Stream to read from.
 *
 * Return: Number of bytes read.
 */

ssize_t getline_wrapper(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytesRead = getline(lineptr, n, stream);

	if (bytesRead == -1)
	{
		if (feof(stream))
		{
			exit(EXIT_SUCCESS);
		} else
		{
			handle_error("Error reading input");
			exit(EXIT_FAILURE);
		}
	}
	return (bytesRead);
}

