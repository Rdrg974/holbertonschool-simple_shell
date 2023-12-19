#define _GNU_SOURCE
#include "simple_shell.h"

/**
 * main - write a UNIX command line interpreter
 * Return: Always 0 (success)
 */

int main(void)
{
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
				printf("exit\n");
				break;
			}
			perror("./shell");
			continue;
		}
		if (strcmp(buffer, "\n") == 0)
			continue;
		buffer[bytes_read - 1] = '\0';
		if (strcmp(buffer, "exit") == 0)
			break;
		execute_command(buffer);
	}
	free(buffer);
	return (0);
}
