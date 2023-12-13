#include "custom_shell.h"

/**
 * custom_shell_cd - changes the working directory
 * of the current shell execution environment
 *
 * @arguments: target directory
 * Return: 1 on success, 0 otherwise
 */

int custom_shell_cd(char **arguments)

{

if (arguments[1] == NULL)

{
fprintf(stderr, "expected argument to \"cd\"\n");

}

else
{
if (chdir(arguments[1]) != 0)
{
perror("error in custom_shell_cd.c: changing directory\n");
}
}
return (-1);
}

