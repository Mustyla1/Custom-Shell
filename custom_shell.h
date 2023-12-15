#ifndef CUSTOM_SHELL_H
#define CUSTOM_SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*---Macros---*/
#define TOK_DELIMITER " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/
/* main.c */
void run_interactive_custom_shell(void);
void run_non_interactive_custom_shell(void);

/*---interactive_shell_module.c—*/
char *read_input_line(void);
char **tokenize_input_line(char *input_line);
int execute_command(char **arguments);

/*---execute_command—*/
int launch_and_execute(char **arguments);

/*---non_interactive_shell_module.c—*/
char *read_stream_input(void);

/*---builtin functions---*/
int custom_shell_cd(char **arguments);
int custom_shell_env(char **arguments);
int custom_shell_help(char **arguments);
int custom_shell_exit(char **arguments);
int custom_shell_comment(char *cmd);

#endif

