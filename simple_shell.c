#define _GNU_SOURCE
#include "simple_shell.h"

/**
 * main - write a UNIX command line interpreter
 * @argc: number of argument
 * @argv: contain the name of programm
 * Return: Always 0 (success)
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	int nbr_command = 0;
	char *line = NULL, **array_command = NULL;
	size_t length = 0;
	ssize_t bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		nbr_command++;
		bytes_read = getline(&line, &length, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				fflush(stdout);
				break;
			}
			perror(argv[0]), free(line);
			continue;
		}
		line[bytes_read - 1] = '\0';
		if (strcmp(line, "exit") == 0)
			break;
		array_command = get_argument(line);
		if (array_command[0] == NULL)
		{
			free_args(array_command), free(line);
			line = NULL;
			continue;
		}
		execute_command(array_command, nbr_command);
		free_args(array_command);
	}
	free(line);
	return (0);
}
