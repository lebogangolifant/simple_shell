#include "simple_shell.h"

/**
 * find_command - Finds the full path of a command in the system's PATH.
 *
 * @command: The command to search for.
 *
 * Return: A pointer to a dynamically allocated string containing the full path
 */

char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		char *path = malloc(strlen(dir) + strlen(command) + 2);

		sprintf(path, "%s/%s", dir, command);
		if (access(path, X_OK) == 0)
		{
			return (path);
		}
		free(path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
