#include "custom_shell.h"

/**
 * custom_shell_comment - checks for a comment in the command
 * @cmd: the command
 * Return: 1 if it is a comment, 0 otherwise
 */
int custom_shell_comment(char *cmd)
{
char *find = cmd;

while (*find == ' ' || *find == '\t')
find++;

if (strlen(find) == 0 || find[0] == '#')
return (1);

if (strcmp(find, " #") == 0)
return (1);

return (0);
}
