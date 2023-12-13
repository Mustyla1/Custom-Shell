#include "custom_shell.h"


/**
 * execute_command - execute a command, either as a built-in or external command
 *
 * @arguments: the array of command and its arguments
 * Return: 1 on success, 0 otherwise
 */

int execute_command(char **arguments)

{

char *builtin_func_list[] = {
"cd",
"env",
"help",
"exit"
};

int (*builtin_func[])(char **) = {
&custom_shell_cd,
&custom_shell_env,
&custom_shell_help,
&custom_shell_exit
};
size_t i = 0;

if (arguments[0] == NULL)
{
/* empty command was entered */
return (-1);
}

/* find if the command is a built-in */

for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)

{
/* If there is a match, execute the built-in command */
if (strcmp(arguments[0], builtin_func_list[i]) == 0)
{
return ((*builtin_func[i])(arguments));
}
}

/* create a new process for external commands */

return (launch_and_execute(arguments));
}

