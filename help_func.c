#include "simple_shell.h"

/**
 * help_func - Display help information.
 * @args: Command and its arguments.
 *
 * Return: 1 on success, 0 otherwise
 */

int help_func(char **args)
{
	char *help_info =
		"Help information:\n"
		" - cd: Change directory\n"
		" - env: Print environment variables\n"
		" - help: Display help information\n"
		" - exit: Exit the shell\n";

	(void)args;

	write(STDOUT_FILENO, help_info, strlen(help_info));
	return (1);
}

