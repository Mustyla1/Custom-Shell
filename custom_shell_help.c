#include "custom_shell.h"

/**
 * custom_shell_help - print help information for the custom shell
 *
 * @arguments: arguments (unused)
 * Return: 1 on success, 0 otherwise.
 */

int custom_shell_help(char **arguments)
{

char *builtin_function_list[] = {
"cd",
"env",
"help",
"exit"
};
size_t j = 0;
(void)(**arguments);

printf("\n--- help for custom shell ---\n");
printf("type a command and its arguments, then hit enter.\n");
printf("built-in commands:\n");
for (; j < sizeof(builtin_function_list) / sizeof(char *); j++)
{
printf("  -> %s\n", builtin_function_list[j]);
}
printf("use the man command for information on other programs.\n\n");
return (-1);
}

