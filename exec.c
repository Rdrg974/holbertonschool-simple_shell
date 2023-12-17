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

	args = get_argument(buffer);
	command_path = get_path(args[0]);
	if (command_path != NULL)
	{
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			execve(command_path, args, environ);
			perror("./shell"), exit(EXIT_FAILURE);
		}
		else
		{
			do {
				wait(&status);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
		}
	}
	else
		printf("%s: command not found\n", args[0]);
}
