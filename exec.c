#include "simple_shell.h"

/**
 * execute_command - allows a process to execute another program
 * @buffer: a string of command shell
 * @name_programm: the name of progamm
 */
void execute_command(char *buffer, char *name_programm)
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
		execve(command_path, args, environ);
		fprintf(stderr, "%s: %s: not found\n", name_programm, args[0]);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
