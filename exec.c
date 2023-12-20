#include "simple_shell.h"

/**
 * free_args - free each element of array args
 * @args: an array of command
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}

/**
 * execute_command - allows a process to execute another program
 * @buffer: a string of command shell
 * @name_programm: the name of progammi
 * @nbr_command: number of the command typed
 */
void execute_command(char *buffer, char *name_programm, int nbr_command)
{
	pid_t pid;
	char *command_path, **args;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		args = get_argument(buffer);
		command_path = get_path(args[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
					name_programm, nbr_command, args[0]);
			free_args(args), exit(EXIT_FAILURE);
		}
		execve(command_path, args, environ);
		perror("execve"), free_args(args), exit(EXIT_FAILURE);
	}
	else
		wait(0);
}
