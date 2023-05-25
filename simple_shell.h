#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define MAX_TOKENS 128

/* Declare external variables */
extern char **environ;

/* Declare function prototypes*/
void display_prompt(bool interactive);
void read_command(char *buffer, bool interactive);
void parse_command(char *line, char **args);
int execute_commands(char **commands);
void handle_error(const char *message);
void builtin_exit(char **args);
void builtin_env(void);
void builtin_setenv(char **args);
void builtin_unsetenv(char **args);
void builtin_cd(char **args);
void replace_variables(char **args);
char **parse_line(char *line);
void free_commands(char ***commands);

/* Declare custom function prototypes */
ssize_t getline_wrapper(char **lineptr, size_t *n, FILE *stream);

#endif /* SIMPLE_SHELL_H */

