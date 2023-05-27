#include "simple_shell.h"

/**
 * cd_func - Change directory.
 * @args: Command and its arguments.
 *
 * Return: 1 on success, 0 otherwise
 */

int cd_func(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Expected argument to \"cd\"\n");
		return (0);
	}
	if (chdir(args[1]) != 0)
	{
		perror("cd");
		return (0);
	}
	return (1);
}

