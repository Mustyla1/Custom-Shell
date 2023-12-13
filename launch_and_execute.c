#include "custom_shell.h"


/**
 * launch_and_execute - creates a new process and executes a command with its arguments
 *
 * this function forks a new process and uses execvp to execute the specified
 * command with its arguments. It waits for the child process to complete
 * before returning.
 *
 * @arguments: array of strings containing the command and its arguments
 * Return: 1 on success, -1 on failure
 */

int launch_and_execute(char **arguments)

{
pid_t pid;
int status;

pid = fork();

if (pid == -1)
{
/* error forking */
perror("error in launch_and_execute: forking");

return (-1);
}

if (pid == 0)
{
/* child process */
if (execvp(arguments[0], arguments) == -1)
{
perror("error in launch_and_execute: executing command");
exit(EXIT_FAILURE);
}
}
else
{
/* parent process */
do {

waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}

