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
	char **args = malloc(sizeof(char *) * 10);

	strcpy(tmp, buffer);
	token = strtok(tmp, " ");
	while (token)
	{
		args[i] = malloc(sizeof(char *) + 5);
		strcpy(args[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	free(tmp);
	return (args);
}
