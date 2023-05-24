#include "simple_shell.h"

/**
 * execute_commands - Executes multiple commands.
 *
 * @commands: Array of commands to execute.
 *
 * Return: The exit status of the last executed command.
 */

int execute_commands(char **commands)
{
	int exit_status = 0;
	int status;
	pid_t pid;

	if (commands == NULL || commands[0] == NULL)
	{
		return (0);
	}
	if (strcmp(commands[0], "exit") == 0)
	{
		return (-1);
	}

	pid = fork();

	if (pid == -1)
	{
		handle_error("fork failed");
		return (EXIT_FAILURE);
	} else if
		(pid == 0)
		{
			if (execvp(commands[0], commands) == -1)
			{
				handle_error("execvp failed");
				exit(EXIT_FAILURE);
			}
		} else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				handle_error("waitpid failed");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
			}
		}
		return (exit_status);
}

/**
 * free_commands - Frees the memory allocated for the commands array.
 *
 * @commands: Pointer to the commands array.
 */

void free_commands(char ***commands)
{
	/*char **current_command = *commands;*/

	if (commands == NULL || *commands == NULL)
	{
		return;
	}

	char **current_command = *commands;

	while (*current_command != NULL)
	{
		free(*current_command);
		current_command++;
	}
	free(*commands);
	*commands = NULL;
}

