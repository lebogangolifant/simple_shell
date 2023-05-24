#include "simple_shell.h"

/**
 * execute_shell - Execute the shell program.
 *
 * Return: The shell program's exit status.
 */

int execute_shell(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t characters_read;
	char *command;
	char **commands;
	int exit_status = 0;

	while ((characters_read = getline(&line, &line_size, stdin)) != -1)
	{
		line[characters_read - 1] = '\0';

		if (strcmp(line, "exit") == 0)
		{
			break;
		}
		command = strdup(line);
		commands = malloc(2 * sizeof(char *));
		commands[0] = command;
		commands[1] = NULL;
		replace_variables(commands);
		exit_status = execute_commands(commands);
		free(command);
		free(commands);

		write(STDOUT_FILENO, "~ ", PROMPT_LENGTH);
	}
	free(line);
	return (exit_status);
}

/**
 * main - Entry point of the shell program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: The shell program's exit status.
 */

int main(void)
{
	if (!isatty(STDIN_FILENO))
	{
		return (execute_shell());
	}
	else
	{

		write(STDOUT_FILENO, "~ ", PROMPT_LENGTH);
		return (execute_shell());
	}
}
