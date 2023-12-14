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
	char *buffer = NULL, *command_path;
	char **args = malloc(sizeof(char *) * 10);
	size_t len = 0;
	ssize_t bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ "), fflush(stdout);
		bytes_read = getline(&buffer, &len, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
				break;
			perror("./shell");
		}
		buffer[bytes_read - 1] = '\0';
		args = get_argument(buffer);
		command_path = get_path(args[0]);
		if (command_path == NULL)
		{
			printf("%s: command not found\n", args[0]);
			continue;
		}
		pid = fork();
		if (pid == -1)
			perror("fork"), exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			execve(command_path, args, environ);
			perror("./shell"), exit(EXIT_FAILURE);
			free(args[0]);
		}
		else
			wait(&status);
	}
	free(buffer), free(args);
	return (0);
}
