#include "simple_shell.h"

/**
 * execute_command - allows a process to execute another program
 * @buffer: a string of command shell
 */
void execute_command(char *buffer)
{
	pid_t pid;
	int status;
	char *command_path, **args;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		args = get_argument(buffer);
		command_path = get_path(args[0]);
		if (execve(command_path, args, environ) == -1)
		{
			fprintf(stderr, "./shell: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			wait(&status);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
}
