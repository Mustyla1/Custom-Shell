#include "custom_shell.h"

/**
 * run_interactive_custom_shell - executes a simple UNIX command line interpreter in interactive mode
 *
 * this function continuously prompts the user for input, reads the input line
 * tokenizes it into arguments, and executes the corresponding command
 */

void run_interactive_custom_shell(void)

{
char *input_line;
char **arguments;
int execution_status = -1;

do {
printf("custom_shell$ "); /* display a custom shell prompt */
input_line = read_input_line(); /* read a line from stdin */

arguments = tokenize_input_line(input_line); /* tokenize the line into arguments */

execution_status = execute_command(arguments); /* execute the command with arguments */

/* free allocated memory to avoid leaks */
free(input_line);
free(arguments);

/* exit with status if needed */
if (execution_status >= 0)
{
exit(execution_status);
}

} while (execution_status == -1);
}


