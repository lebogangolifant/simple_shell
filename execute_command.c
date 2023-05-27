#include "simple_shell.h"

/**
 * execute_command - Executes a command in a new process.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: On success, returns -1. Otherwise, returns an error code.
 */

int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in execute_command: child process");
		}
		exit(EXIT_FAILURE);
	} else if
		(pid < 0)
		{
			perror("error in execute_command: forking");
		} else
		{
			do
			{
				waitpid(pid, &status, WUNTRACED);
			}
			while
				(!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		return (-1);
}
