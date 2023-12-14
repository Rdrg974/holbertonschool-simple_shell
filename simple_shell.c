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

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&buffer, &len, stdin);
		buffer[bytes_read - 1] = '\0';
		if (bytes_read == -1)
		{
			if (feof(stdin))
				printf("exit\n");
			else
				perror("./shell");
			break;
		}
		pid = fork();
		if (pid == -1)
			perror("fork"), exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			args = get_argument(buffer);
			if (execve(args[0], args, NULL) == -1)
				perror("./shell"), exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
	free(buffer);
	free(args);
	return (0);
}
