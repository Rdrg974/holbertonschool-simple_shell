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
	int nbr_command = 1;
	char *buffer = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
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
			perror(argv[0]);
			continue;
		}
		if (strcmp(buffer, "\n") == 0)
			continue;
		buffer[bytes_read - 1] = '\0';
		if (strcmp(buffer, "exit") == 0)
			break;
		execute_command(buffer, argv[0], nbr_command);
		nbr_command++;
	}
	free(buffer);
	return (0);
}
