#include "simple_shell.h"

/**
 * parse_command - Parses the command line into individual arguments.
 *
 * @line: Command line to parse.
 *
 * @args: Array to store the parsed arguments.
 */

void parse_command(char *line, char **args)
{
	const char *delimiters = " \t\n";
	char *token;
	int i = 0;

	while ((token = strsep(&line, delimiters)) != NULL && i < BUFFER_SIZE)
	{
		if (*token != '\0')
		{
			args[i] = token;
			i++;
		}
	}

	args[i] = NULL;
}

/**
 * replace_variables - Replaces special variables in command arguments.
 *
 * @args: Array of command arguments to process.
 */

void replace_variables(char **args)
{
	char pid_str[16];
	char exit_status_str[16];
	pid_t pid = getpid();
	int exit_status = 0;
	int index = 0;

	while (args[index] != NULL)
	{
		if (strcmp(args[index], "$$") == 0)
		{
			sprintf(pid_str, "%d", pid);
			free(args[index]);
			args[index] = strdup(pid_str);
		}
		else if (strcmp(args[index], "$?") == 0)
		{
			sprintf(exit_status_str, "%d", exit_status);
			free(args[index]);
			args[index] = strdup(exit_status_str);
		}
		else if (args[index][0] == '$')
		{
			const char *var_name = args[index] + 1;
			char *var_value = getenv(var_name);

			if (var_value != NULL)
			{
				free(args[index]);
				args[index] = strdup(var_value);
			}
		}
		index++;
	}
}

/**
 * parse_line - Parses the input command line into multiple commands.
 *
 * @line: Input command line to parse.
 *
 * Return: Array of command arrays.
 */

char **parse_line(char *line)
{
	const char *delimiters = " \t\r\n";
	const char *comment_char = "#";
	char **args = malloc(BUFFER_SIZE * sizeof(char *));
	char *token;
	int arg_index = 0;

	if (args == NULL)
	{
		handle_error("malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delimiters);
	while (token != NULL)
	{
		if (strcmp(token, comment_char) == 0)
			break;

		args[arg_index] = strdup(token);
		arg_index++;
		token = strtok(NULL, delimiters);
	}
	args[arg_index] = NULL;
	replace_variables(args);
	return (args);
}

