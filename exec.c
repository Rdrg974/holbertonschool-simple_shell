#include "simple_shell.h"

/**
 * execute_command - allows a process to execute another program
 * @buffer: a string of command shell
 * @name_programm: the name of progammi
 * @nbr_command: number of the command typed
 */
void execute_command(char *buffer, char *name_programm, int nbr_command)
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
		fprintf(stderr, "%s: %d: %s: not found\n",
				name_programm, nbr_command, args[0]);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
