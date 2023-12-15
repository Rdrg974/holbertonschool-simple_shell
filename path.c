#include "simple_shell.h"

/**
 * get_path - handle the path
 * @buffer: a string of command
 * Return: the handle the path
 */

char *get_path(char *buffer)
{
	char *path;
	int length_buffer = strlen(buffer);
	char *token, *tmp, *file_path;

	if (strstr(buffer, "/") == NULL)
	{
		path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
		tmp = malloc(strlen(path) + 1);
		strcpy(tmp, path);
		token = strtok(tmp, ":");
		while (token)
		{
			file_path = malloc(length_buffer + strlen(token) + 2);
			if (file_path == NULL)
				perror("malloc"), exit(EXIT_FAILURE);
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, buffer);
			if (access(file_path, X_OK) == 0)
				return (file_path);
			free(file_path);
			token = strtok(NULL, ":");
		}
		return (NULL);
	}
	return (buffer);
}
