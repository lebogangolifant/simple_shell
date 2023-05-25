#include "simple_shell.h"

/**
 * handle_error - Displays an error message and terminates the program.
 *
 * @message: Error message to display.
 */

void handle_error(const char *message)
{
	write(STDERR_FILENO, message, strlen(message));
	write(STDERR_FILENO, "\n", 1);
}

