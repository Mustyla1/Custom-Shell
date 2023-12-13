#include "custom_shell.h"

/**
 * read_stream_input - reads a line from the stream
 *
 * Return: pointer that points to the read line
 */

char *read_stream_input(void)

{

int buffer_size = 1024;
int j = 0;

char *stream_input = malloc(sizeof(char) * buffer_size);
int c;


if (stream_input == NULL)

{
fprintf(stderr, "allocation error in read_stream_input");
exit(EXIT_FAILURE);
}

while (1)
{
c = getchar(); /* read the first character from the stream */

if (c == EOF)
{
free(stream_input);
exit(EXIT_SUCCESS);
}
else if (c == '\n')
{
stream_input[j] = '\0';
return (stream_input);
}
else
{
stream_input[j] = c;
}

j++;

if (j >= buffer_size)
{
buffer_size += buffer_size;
stream_input = realloc(stream_input, buffer_size);

if (stream_input == NULL)
{
fprintf(stderr, "reallocation error in read_stream_input");
exit(EXIT_FAILURE);
}
}
}
}

