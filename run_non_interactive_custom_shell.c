#include "custom_shell.h"

/**
 *run_non_interactive_custom_shell - runs the custom shell in non-interactive mode
 *
 * this function reads input from the stream, tokenizes it into arguments,
 * and executes the corresponding command. It continues this process until
 * an exit status is received
 */

void run_non_interactive_custom_shell(void)

{
char *stream_input;
char **arguments;
int execution_status = -1;

do {
stream_input = read_stream_input();
arguments = tokenize_input_line(stream_input);

execution_status = execute_command(arguments);

/* free allocated memory to avoid leaks */

free(stream_input);
free(arguments);

/* exit with status if needed */
if (execution_status >= 0)
{
exit(execution_status);
}

} while (execution_status == -1);
}

