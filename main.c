#include "custom_shell.h"

/**
* main - function that checks if our shell is called
*
* Return: always returns 0 on success
*/

int main(void)

{
/* checks if the standard input is coming from a terminal */
if (isatty(STDIN_FILENO) == 1)
{
run_interactive_custom_shell();
}
else
{
run_non_interactive_custom_shell();
}
return (0);
}

