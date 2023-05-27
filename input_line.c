#include "simple_shell.h"

/**
 * read_line - Reads a line of input from stdin.
 *
 * Return: On success, returns a pointer to the read line. Otherwise, exits the
 *         program with an error code.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line); 
			exit(EXIT_SUCCESS);
		} else
		{
			free(line);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
