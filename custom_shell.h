#ifndef CUSTOM_SHELL_H
#define CUSTOM_SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdbool.h>

/* STRUCTURE  */

/**
 * struct Node_env - structure that handles the env
 * @data: the env list
 * @number: to check the env list
 * @next: pointer to the next node
 */

typedef struct Node_env
{
	char *data;
	int number;
	struct Node_env *next;
} Node_env;

/* string functions */

int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
size_t _strcspn(const char *str, const char *charset);
char *_strdup(char *str);
void *_memcpy(void *dest, const void *src, size_t n);
size_t _strspn(const char *str, const char *charset);
char *_strchr(const char *str, int character);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *to, const char *from);
char *_strcat(char *to, const char *from);

/*---Macros---*/
#define TOK_DELIMITER " \t\r\n\a\""
extern char **environ;
extern int updated;
#define MAX_PATH_LENGTH 1024
#define MAX_ARGS 100 
static char *cmd __attribute__((unused));

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
int word_count(char *av, char ***args);
int custom_shell_help(char **arguments);
int custom_shell_exit(char **arguments);

#endif

