#include "simple_shell.h"

/**
 * change_directory - Change the current working directory
 * @args: Array of strings containing the arguments
 *
 * Return: 1 on success, 0 otherwise
 */

int change_directory(char **args)
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

/**
 * print_environment - Print the environment variables
 * @args: Array of strings containing the arguments
 *
 * Return: 1 on success, 0 otherwise
 */

int print_environment(char **args)
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

/**
 * display_help - Display help information
 * @args: Array of strings containing the arguments
 *
 * Return: 1 on success, 0 otherwise
 */

int display_help(char **args)
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

/**
 * exit_shell - Exit the shell
 * @args: Array of strings containing the arguments
 *
 * Return: 1 on success, 0 otherwise
 */

int exit_shell(char **args)
{
	(void)args;

	return (1);
}
