#include "custom_shell.h"

#define BUFFER_SIZE 1024

/**
 * read_stream_input - reads a line from the stream
 *
 * Return: pointer that points to the read line
 */

char *read_stream_input(void);

int main(void)
{
char *input;

while (1)
{
input = read_stream_input();

if (input == NULL)
{
fprintf(stderr, "allocation error in main");
exit(EXIT_FAILURE);
}

/* Process the input or do something with it */
printf("Input: %s\n", input);

free(input);
}

return (0);
}

char *read_stream_input(void)
{
int buffer_size = BUFFER_SIZE;
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
return (NULL);
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
buffer_size += BUFFER_SIZE;
stream_input = realloc(stream_input, buffer_size);

if (stream_input == NULL)
{
fprintf(stderr, "reallocation error in read_stream_input");
exit(EXIT_FAILURE);
}
}
}
}
