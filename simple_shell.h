#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""

/* Global variables declaration */
extern char **environ;

/* Funtion Prototypes declaration */
int execute_external_commands(char **commands);
int execute_commands(char **commands);
void interactive_mode(void);
void non_interactive_mode(void);
char *read_stream_input(void);
char **split_input(char *input);
char *read_input(void);
int change_directory(char **args);
int print_environment(char **args);
int display_help(char **args);
int exit_shell(char **args);

#endif /* SIMPLE_SHELL_H */

