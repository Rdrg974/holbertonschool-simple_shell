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
	char *buffer = NULL, **args = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		nbr_command++;
		bytes_read = getline(&buffer, &len, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				fflush(stdout);
				break;
			}
			perror(argv[0]), free(buffer);
			continue;
		}
		buffer[bytes_read - 1] = '\0';
		if (strcmp(buffer, "exit") == 0)
			break;
		args = get_argument(buffer);
		if (args[0] == NULL)
		{
			free_args(args), free(buffer);
			buffer = NULL;
			continue;
		}
		execute_command(args, nbr_command);
		free_args(args);
	}
	free(buffer);
	return (0);
}
