#include "simple_shell.h"

/**
 * free_args - free each element of array args
 * @array_command: an array of command
 */
void free_args(char **array_command)
{
	int i;

	if (array_command == NULL)
		return;
	for (i = 0; array_command[i] != NULL; i++)
		free(array_command[i]);
	free(array_command);
}

/**
 * execute_command - allows a process to execute another program
 * @array_command: an array of command
 * @nbr_command: number of the command typed
 */
void execute_command(char **array_command, int nbr_command)
{
	pid_t pid;
	char *command_path;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		command_path = get_path(array_command[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "./shell: %d: %s: not found\n",
					nbr_command, array_command[0]);
			free_args(array_command), exit(EXIT_FAILURE);
		}
		execve(command_path, array_command, environ);
		perror("execve"), free_args(array_command), exit(EXIT_FAILURE);
	}
	else
		wait(0);
}
