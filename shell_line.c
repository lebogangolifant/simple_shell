#include "simple_shell.h"

/**
 * split_line - Splits a line into an array of tokens.
 * @line: The line to be split.
 *
 * Return: On success, returns a pointer to the array of tokens. Otherwise,
 *         exits the program with an error code.
 */

char **split_line(char *line)
{
        int bufsize = 64;
        int index_line = 0;
        char **tokens = malloc(bufsize * sizeof(char *));
        char *token;

        if (!tokens)
        {
                fprintf(stderr, "allocation error in split_line: tokens\n");
                exit(EXIT_FAILURE);
        }
        token = strtok(line, TOK_DELIM);
        while (token != NULL)
        {
                if (token[0] == '#')
                {
                        break;
                }
                tokens[index_line] = token;
                index_line++;
                if (index_line >= bufsize)
                {
                        bufsize += bufsize;
                        tokens = realloc(tokens, bufsize * sizeof(char *));
                        if (!tokens)
                        {
                                fprintf(stderr, "reallocation error in split_line: tokens");
                                exit(EXIT_FAILURE);
                        }
                }
                token = strtok(NULL, TOK_DELIM);
        }
        tokens[index_line] = NULL;
        return tokens;
}

