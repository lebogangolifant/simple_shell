#include "simple_shell.h"

/**
 * builtin_exit - Handles the built-in exit command.
 *
 * @args: Arguments for the exit command.
 */

void builtin_exit(char **args)
{
	if (args[1] != NULL)
	{
		int exit_status = atoi(args[1]);

		exit(exit_status);
	} else
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * builtin_env - Handles the built-in env command.
 */

void builtin_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * builtin_setenv - Handles the built-in setenv command.
 *
 * @args: Arguments for the setenv command.
 */

void builtin_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}
}

/**
 * builtin_unsetenv - Handles the built-in unsetenv command.
 *
 * @args: Arguments for the unsetenv command.
 */

void builtin_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}
	if (unsetenv(args[1]) == -1)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}
}

/**
 * builtin_cd - Handles the built-in cd command.
 *
 * @args: Arguments for the cd command.
 */

void builtin_cd(char **args)
{
	const char *home_dir = getenv("HOME");
	const char *oldpwd_dir = getenv("OLDPWD");
	const char *target_dir = args[1];
	char cwd[PATH_MAX];

	if (target_dir == NULL || strcmp(target_dir, "~") == 0)
	{
		target_dir = home_dir;
	} else if
		(strcmp(target_dir, "-") == 0)
		{
			target_dir = oldpwd_dir;
		}
	if (target_dir == NULL || chdir(target_dir) == -1)
	{
		fprintf(stderr, "Failed to change directory\n");
		return;
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		fprintf(stderr, "Failed to get current working directory\n");
		return;
	}
	setenv("PWD", cwd, 1);
}

