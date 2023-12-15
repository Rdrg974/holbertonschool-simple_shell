#include "simple_shell.h"

/**
 * execute_command - allows a process to execute another program
 * @args: an array of argument command
 * @command_path: handle of path
 */
void execute_command(char **args, char *command_path)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		perror("fork"), exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		execve(command_path, args, environ);
		perror("./shell"), exit(EXIT_FAILURE);
		free(args[0]);
	}
	else
		wait(&status);
}
