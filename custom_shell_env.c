#include "custom_shell.h"

/**
 * custom_shell_env - prints environment variables
 *
 * @arguments: arguments
 * Return: 1 on success, 0 otherwise
 */

int custom_shell_env(char **arguments)
{
char **args;
int count, i;

count = word_count(arguments[0], &args);

if (count == -1)
{
perror("Error in word_count");
return (0);
}

for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}

for (i = 0; i < count; i++)
free(args[i]);
free(args);

return (1);
}
