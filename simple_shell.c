#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	char *args[2], *envp[] = { NULL };

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
			continue;
		}
		if (buffer[0] == '\n')
			continue;
		buffer[bytes_read - 1] = '\0';
		args[0] = buffer;
		args[1] = NULL;
		if (access(buffer, X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, envp), exit(EXIT_FAILURE);
			else
				wait(NULL);
		}
		else
			printf("%s: command not found\n", buffer);
	}
	free(buffer);
	return (0);
}
