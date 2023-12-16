#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

/**
 * custom_shell_cd - changes the working directory
 * of the current shell execution environment
 *
 * @arguments: target directory
 * Return: 1 on success, 0 otherwise
 */
int custom_shell_cd(char **arguments)
{
char *target_directory;

if (arguments[1] == NULL)
{

target_directory = getenv("HOME");
if (target_directory == NULL)
{
fprintf(stderr, "cd: HOME not set\n");
return (0);
}
}
else if (strcmp(arguments[1], "-") == 0)
{

target_directory = getenv("OLDPWD");
if (target_directory == NULL)
{
fprintf(stderr, "cd: OLDPWD not set\n");
return (0);
}
printf("%s\n", target_directory);
}
else
{
target_directory = arguments[1];
}

char current_directory[MAX_PATH_LENGTH];
if (getcwd(current_directory, sizeof(current_directory)) == NULL)
{
perror("getcwd");
return (0);
}

if (setenv("OLDPWD", current_directory, 1) != 0)
{
perror("setenv");
return (0);
}

if (chdir(target_directory) != 0)
{
perror("chdir");
return (0);
}

if (setenv("PWD", target_directory, 1) != 0)
{
perror("setenv");
return (0);
}

return (1);
}

int main(void)
{
char *args[] = {"cd", "path/to/directory", NULL};
custom_shell_cd(args);

return (0);
}
