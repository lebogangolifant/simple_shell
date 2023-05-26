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
		exit(EXIT_FAILURE);
	} else if
		(pid == 0)
		{
			execute_child(commands);
		} else
		{
			execute_parent(pid);
		}
		return (exit_status);
}

/**
 * execute_child - Executes the child process.
 * @commands: Array of commands to execute.
 */

void execute_child(char **commands)
{
	if (execvp(commands[0], commands) == -1)
	{
		handle_error("execvp failed");
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_parent - Executes the parent process.
 * @pid: Process ID of the child process.
 */

void execute_parent(pid_t pid)
{
	int exit_status;
	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		handle_error("waitpid failed");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
	}
	if (isatty(STDIN_FILENO) && !isatty(STDOUT_FILENO))
	{
		write_newline();
	}
	exit_status = exit_status;
}

/**
 * write_newline - Writes a newline character to the standard output.
 */

void write_newline(void)
{
	const char newline = '\n';

	write(STDOUT_FILENO, &newline, 1);
}

/**
 * free_commands - Frees the memory allocated for the commands array.
 *
 * @commands: Pointer to the commands array.
 */

void free_commands(char ***commands)
{
	char **current_command = *commands;

	if (commands == NULL || *commands == NULL)
	{
		return;
	}

	while (*current_command != NULL)
	{
		free(*current_command);
		current_command++;
	}
	free(*commands);
	*commands = NULL;
}

