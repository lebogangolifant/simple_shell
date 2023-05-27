#include "simple_shell.h"

/**
 * interactive_mode - Run the shell in interactive mode.
 *
 * Return: void
 */

void interactive_mode(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		write(STDOUT_FILENO, "~ ", 2);
		line = read_stream();
		args = split_line(line);
		status = execute_shell_command(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while
	(status == -1);
}
