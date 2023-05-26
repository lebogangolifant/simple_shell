#include "simple_shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Description: This function serves as the entry point for the shell program.
 * It checks if the standard input is a terminal, and based on the result,
 * either calls the interactive shell function or the non-interactive shell
 * function.
 *
 * Return: Always 0 (success)
*/

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	} else
	{
		non_interactive_mode();
	}
	return (0);
}

