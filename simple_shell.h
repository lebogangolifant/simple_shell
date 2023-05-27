#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""

/* Global variables declaration */
extern char **environ;

/* Funtion Prototypes declaration */
void interactive_mode(void);
void non_interactive_mode(void);
char *read_stream(void);
char **split_line(char *line);
int execute_command(char **args);
int execute_shell_command(char **args);
char *read_stream(void);
int cd_func(char **args);
int env_func(char **args);
int help_func(char **args);
int exit_func(char **args);

#endif  /* SIMPLE_SHELL_H */
