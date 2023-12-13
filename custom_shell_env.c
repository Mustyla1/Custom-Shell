#include "custom_shell.h"

/**
 * custom_shell_env - prints environment variables
 *
 * @arguments: arguments
 * Return: 1 on success, 0 otherwise
 */

int custom_shell_env(char **arguments)

{
int i = 0;
(void)(**arguments);

while (environ[i])
{
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
	write(STDOUT_FILENO, "\n", 1);
i++;
}
return (-1);
}

