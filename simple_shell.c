#define _GNU_SOURCE
#include "simple_shell.h"

/**
 * main - write a UNIX command line interpreter
 * Return: Always 0 (Success)
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
				break;
			perror("./shell");
		}
		buffer[bytes_read - 1] = '\0';
		execute_command(buffer);
	}
	free(buffer);
	return (0);
}
