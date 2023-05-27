#include "simple_shell.h"

/**
 * env_func - Print environment variables.
 * @args: Command and its arguments.
 *
 * Return: 1 on success, 0 otherwise
 */

int env_func(char **args)
{
	char **env = environ;
	(void)args;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
	return (1);
}

