#include "simple_shell.h"

/**
 * execute_commands - Execute shell commands.
 *
 * @commands: Array of commands to execute.
 *
 * Return: void
 */

int execute_commands(char **commands)
{
	char *builtin_commands[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	int (*builtin_functions[])(char **) = {
		&change_directory,
		&print_environment,
		&display_help,
		&exit_shell
	};

	int builtin_index = 0;
	int num_builtins = sizeof(builtin_commands) / sizeof(char *);
	int status = -1;

	if (commands[0] == NULL)
	{
		return (-1);
	}
	while (builtin_index < num_builtins)
	{
		if (strcmp(commands[0], builtin_commands[builtin_index]) == 0)
		{
			status = (*builtin_functions[builtin_index])(commands);
			break;
		}
		builtin_index++;
	}
	if (status == -1)
	{
		status = execute_external_commands(commands);
	}
	return (status);
}

/**
 * execute_external_commands - Execute external commands.
 *
 * @commands: Array of commands to execute.
 *
 * Return: void
 */

int execute_external_commands(char **commands)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(commands[0], commands) == -1)
		{
			perror("Error in execute_external_commands: child process");
		}
		exit(EXIT_FAILURE);
	} else if
		(pid < 0)
		{
			perror("Error in execute_external_commands: forking");
		} else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while
			(!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		return (-1);
}
