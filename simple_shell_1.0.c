#include "simple_shell.h"

/**
 * main - Entry point of the simple_shell program.
 *
 * Description: This function serves as the entry point for the shell program.
 * It implements the main execution loop, where it repeatedly displays
 * the prompt, reads the user's input command, parses the command,
 * executes the commands, and handles any errors.
 *
 * Return: The exit status of the shell program.
 */

int main(void)
{
	char *line = NULL;
	size_t lineSize = 0;
	ssize_t bytesRead;
	int exit_status = 0;
	char **commands;

	const char prompt[] = "($)\n ";

	while (true)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		bytesRead = input_getline(&line, &lineSize, stdin);

		if (bytesRead == -1)
		{
			break;
		}

		/*char **commands;*/
		commands = parse_line(line);
		if (commands != NULL && commands[0] != NULL)
		{
			if (strcmp(commands[0], "exit") == 0)
			{
				free_commands(&commands);
				break;
			}
			exit_status = execute_commands(commands);
			free_commands(&commands);
		}
	}

	free(line);
	/*line = NULL;*/
	/*lineSize = 0;*/
	return (exit_status);
}
