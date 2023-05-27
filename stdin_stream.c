#include "simple_shell.h"

/**
 * read_stream - Reads a line from the input stream.
 *
 * Return: On success, returns a pointer to the read line. Otherwise, exits the
 *         program with an error code.
 */

char *read_stream(void)
{
        int bufsize = 1024;
        int i = 0;
        char *line = malloc(sizeof(char) * bufsize);
        int character;

        if (line == NULL)
        {
                fprintf(stderr, "allocation error in read_stream");
                exit(EXIT_FAILURE);
        }
        while (1)
        {
                character = getchar();
                if (character == EOF)
                {
                        free(line);
                        exit(EXIT_SUCCESS);
                }
                else if (character == '\n')
                {
                        line[i] = '\0';
                        return line;
                }
                else
                {
                        line[i] = character;
                }
                i++;
                if (i >= bufsize)
                {
                        bufsize += bufsize;
                        line = realloc(line, bufsize);

                        if (line == NULL)
                        {
                                fprintf(stderr, "reallocation error in read_stream");
                                exit(EXIT_FAILURE);
                        }
                }
        }
}
