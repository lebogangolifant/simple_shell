#include "simple_shell.h"

/**
 * read_input - Read input from stdin.
 *
 * Return: Pointer to the input string.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		} else
		{
			free(input);
			perror("Error while reading input from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
/**
 * read_stream_input - Read input from stdin.
 *
 * Return: A pointer to the input string read from stdin.
 */
char *read_stream_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	int index = 0;
	int character;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		} else
		{
			free(input);
			perror("Error while reading input from stdin");
			exit(EXIT_FAILURE);
		}
	}
	while ((character = getchar()) != EOF && character != '\n')
	{
		input[index] = character;
		index++;

		if (index >= bufsize)
		{
			bufsize += 64;
			input = realloc(input, bufsize * sizeof(char));

			if (input == NULL)
			{
				fprintf(stderr, "Reallocation error in
						read_stream_input");
				exit(EXIT_FAILURE);
			}
		}
	}
	input[index] = '\0';
	return (input);
}

/**
 * split_input - Split input string into multiple commands.
 * @input: Input string.
 *
 * Return: Pointer to the array of commands.
 */
char **split_input(char *input)
{
	int bufsize = 64;
	int index = 0;
	char **commands = malloc(bufsize * sizeof(char *));
	char *command;

	if (!commands)
	{
		fprintf(stderr, "Allocation error in split_input: commands\n");
		exit(EXIT_FAILURE);
	}
	command = strtok(input, TOK_DELIM);
	while (command != NULL)
	{
		if (command[0] == '#')
		{
			break;
		}
		commands[index] = command;
		index++;

		if (index >= bufsize)
		{
			bufsize += bufsize;
			commands = realloc(commands, bufsize * sizeof(char *));
			if (!commands)
			{
				fprintf(stderr, "Reallocation error in
						split_input: commands\n");
				exit(EXIT_FAILURE);
			}
		}
		command = strtok(NULL, TOK_DELIM);
	}
	commands[index] = NULL;
	return (commands);
}
