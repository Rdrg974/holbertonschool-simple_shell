#include "simple_shell.h"

/**
 * execute_command - allows a process to execute another program
 * @buffer: a string of command
 */
void execute_command(char *buffer)
{
	int status;
	char *command_path;
	pid_t pid;
	char **args = malloc(sizeof(char *) * 10);

	pid = fork();
	if (pid == -1)
		perror("fork"), exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		args = get_argument(buffer);
		command_path = get_path(args[0]);
		execve(command_path, args, environ);
		perror("./shell"), exit(EXIT_FAILURE);
		free(args[0]);
	}
	else
		wait(&status);
	free(args);
}
