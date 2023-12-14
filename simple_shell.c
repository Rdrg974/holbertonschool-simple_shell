#define _GNU_SOURCE
#include "simple_shell.h"

/**
 * main - write a UNIX command line interpreter
 * Return: Always 0 (Success)
 */

int main(void)
{
	int status;
	pid_t pid;
	char *buffer = NULL;
	char **args = malloc(sizeof(char *) * 10);
	size_t len = 0;
	ssize_t bytes_read;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("$ ");
			bytes_read = getline(&buffer, &len, stdin);
			if (bytes_read == -1)
			{
				if (feof(stdin))
					break;
				perror("./shell");
			}
			buffer[bytes_read - 1] = '\0';
			pid = fork();
			if (pid == -1)
				perror("fork"), exit(EXIT_FAILURE);
			else if (pid == 0)
			{
				args = get_argument(buffer);
				if (execve(args[0], args, environ) == -1)
					perror("./shell"), exit(EXIT_FAILURE);
				free(args[0]);
			}
			else
				wait(&status);
		}
	}
	free(buffer);
	free(args);
	return (0);
}
