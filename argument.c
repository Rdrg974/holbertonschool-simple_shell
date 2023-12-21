#include "simple_shell.h"

/**
 * get_argument - handle command lines with arguments
 * @line: path + argument
 * Return: an array of each element of path
 */

char **get_argument(char *line)
{
	int i = 0;
	char *tmp = malloc(strlen(line) + 1);
	char *token;
	char **array_command = malloc(sizeof(char *) * MAX_ARGS);

	if (tmp == NULL || array_command == NULL)
		perror("malloc"), exit(EXIT_FAILURE);
	strcpy(tmp, line);
	token = strtok(line, " \t\r\n\a");
	while (token)
	{
		array_command[i] = malloc(strlen(token) + 1);
		if (array_command[i] == NULL)
			perror("malloc"), exit(EXIT_FAILURE);
		strcpy(array_command[i], token);
		token = strtok(NULL, " \t\r\n\a");
		i++;
	}
	array_command[i] = NULL;
	free(tmp);
	return (array_command);
}
