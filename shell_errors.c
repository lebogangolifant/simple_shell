#include "simple_shell.h"

/**
 * handle_error - Displays an error message and terminates the program.
 *
 * @message: Error message to display.
 */

void handle_error(const char *message)
{
	fprintf(stderr, "%s: %s\n", simpleshell, message);
}

