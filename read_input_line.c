#include "custom_shell.h"

/**
* read_input_line - reads a line from stdin
*
* Return: a pointer to a dynamically allocated string containing the line content
* this memory must be freed by the caller
*/

char *read_input_line(void)

{
char *input_line = NULL;
size_t read_size = 0;

if (getline(&input_line, &read_size, stdin) == -1)
/* if getline fails */
{
if (feof(stdin))
/* test for the eof */
{		 free(input_line);
/* avoid memory leaks when ctrl + d */
exit(EXIT_SUCCESS);
/* we recieved an eof */
}
else
{
free(input_line);
/* avoid memory leaks when getline fails */

perror("error while reading the line from stdin");
exit(EXIT_FAILURE);
}
}
return (input_line);
}


