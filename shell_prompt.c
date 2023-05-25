#include "simple_shell.h"

/**
 * display_prompt - Displays the shell prompt.
 *
 * @interactive: Boolean flag indicating whether
 * the shell is running in interactive mode.
 */

void display_prompt(bool interactive)
{
	if (interactive)
	{
		write(STDOUT_FILENO, "~ ", 2);
	}
}

/**
 * read_command - Reads the user's input command.
 *
 * @buffer: Buffer to store the input command.
 *
 * @interactive: Boolean flag indicating whether the shell
 * is running in interactive mode.
 */

void read_command(char *buffer, bool interactive)
{
	if (interactive)
	{
		size_t bufferSize = BUFFER_SIZE;
		ssize_t bytesRead = getline(&buffer, &bufferSize, stdin);

		if (bytesRead == -1)
		{
			handle_error("getline");
			buffer[0] = '\0';
		} else
		{
			buffer[strcspn(buffer, "\n")] = '\0';
		}
	} else
	{
		ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);

		if (bytesRead == -1)
		{
			handle_error("read");
		} else if
			(bytesRead == 0)
			{
				buffer[0] = '\0';
			} else
			{
				buffer[bytesRead] = '\0';
			}
	}
}

