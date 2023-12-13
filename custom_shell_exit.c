#include "custom_shell.h"

/**
 * custom_shell_exit - causes normal process termination
 *
 * @arguments: arguments (unused)
 * Return: 0 to terminate the process
 */

int custom_shell_exit(char **arguments)

{

/* exit with status */
if (arguments[1])
{
return (atoi(arguments[1]));
}
/* exit success */
else
{
return (0);
}
}

