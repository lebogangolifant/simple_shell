#include "simple_shell.h"

/**
 * interactive_mode - Run the shell in interactive mode.
 *
 * Return: void
 */

void interactive_mode(void)
{
	char *input;
	char **commands;
	int status = -1;
	char *prompt = "~ ";

	while (write(STDOUT_FILENO, prompt, strlen(prompt)) != -1)
	{
		line = read_stream_input();
		commands = split_line(input);
		status = execute_commands(commands);
		free(line);
		free(commands);

		if (status >= 0)
		{
			break;
		}
	}
}

/**
 * non_interactive_mode - Run the shell in non-interactive mode.
 *
 * Return: void
 */

void non_interactive_mode(void)
{
	char *input;
	char **commands;
	int status = -1;

	while ((line = read_stream_input()) != NULL)
	{
		commands = split_line(input);
		status = execute_commands(commands);
		free(line);
		free(commands);

		if (status >= 0)
		{
			break;
		}
	}
}
