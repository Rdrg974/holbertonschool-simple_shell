#include "simple_shell.h"

/**
 * free_args - free each element of array args
 * @args: an array of command
 */
void free_args(char **args)
{
	int i;

	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}

/**
 * execute_command - allows a process to execute another program
 * @array_argument: an array of argument
 * @nbr_command: number of the command typed
 */
void execute_command(char **array_argument, int nbr_command)
{
	pid_t pid;
	char *command_path;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		command_path = get_path(array_argument[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "./shell: %d: %s: not found\n",
					nbr_command, array_argument[0]);
			free_args(array_argument), exit(EXIT_FAILURE);
		}
		execve(command_path, array_argument, environ);
		perror("execve"), free_args(array_argument), exit(EXIT_FAILURE);
	}
	else
		wait(0);
}
