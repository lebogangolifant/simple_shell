#include "simple_shell.h"

/**
 * non_interactive_mode - Run the shell in non-interactive mode.
 *
 * Return: void
 */

void non_interactive_mode(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
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
