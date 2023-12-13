#include "custom_shell.h"


/**
 * tokenize_input_line - split a string into multiple strings
 *
 * @input_line: the string to be split
 * Return: a pointer to a dynamically allocated array of strings
 * this memory must be freed by the caller
 */

char **tokenize_input_line(char *input_line)

{
int buffer_size = 64;
int i = 0;
char **tokens = malloc(buffer_size * sizeof(char *));
char *token;

if (!tokens)
{
fprintf(stderr, "allocation error in tokenize_input_line: tokens\n");
exit(EXIT_FAILURE);
}

token = strtok(input_line, TOK_DELIMITER);

while (token != NULL)
{
/* handle comments */
if (token[0] == '#')
{
break;
}

tokens[i] = token;
i++;

if (i >= buffer_size)
{
buffer_size += buffer_size;
tokens = realloc(tokens, buffer_size *sizeof(char *));
if (!tokens)
{
fprintf(stderr, "reallocation error in tokenize_input_line: tokens");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOK_DELIMITER);

}

tokens[i] = NULL;
return (tokens);
}

