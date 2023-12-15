#include "simple_shell.h"

/**
 * get_argument - handle command lines with arguments
 * @buffer: path + argument
 * Return: an array of each element of path
 */

char **get_argument(char *buffer)
{
	int i = 0;
	char *tmp = malloc(strlen(buffer) + 1);
	char *token;
	char **args = malloc(sizeof(char *) * MAX_ARGS);

	if (tmp == NULL || args == NULL)
		perror("malloc"), exit(EXIT_FAILURE);
	strcpy(tmp, buffer);
	token = strtok(tmp, " ");
	while (token && i < MAX_ARGS - 1)
	{
		args[i] = malloc(sizeof(char *) + 5);
		if (args[i] == NULL)
			perror("malloc"), exit(EXIT_FAILURE);
		strcpy(args[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	free(tmp);
	return (args);
}
