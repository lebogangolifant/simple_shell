#include "simple_shell.h"

/**
 * execute_shell_command - Executes a command or calls a built-in function.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: On success, returns the return value of the executed command
 *         or the built-in function. Otherwise, returns an error code.
 */

int execute_shell_command(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit",
	};

	int (*builtin_func[])(char **) = {
		&cd_func,
		&env_func,
		&help_func,
		&exit_func
	};

	size_t index = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; index < sizeof(builtin_func_list) / sizeof(char *); index++)
	{
		if (strcmp(args[0], builtin_func_list[index]) == 0)
		{
			return ((*builtin_func[index])(args));
		}
	}
	return (execute_command(args));
}
