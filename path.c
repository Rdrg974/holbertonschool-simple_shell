#include "simple_shell.h"

char *get_path(char *buffer)
{
	char *path;
	int length_buffer = strlen(buffer);
	char *token, *tmp, *file_path;
	struct stat st;

	if (strstr(buffer, "/") == NULL)
	{
		path = "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin";
		tmp = malloc(strlen(path) + 1);
		strcpy(tmp, path);
		token = strtok(tmp, ":");
		while (token)
		{
			file_path = malloc(length_buffer + strlen(token) + 2);
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, buffer);
			if (stat(file_path, &st) == 0)
				return (file_path);
			free(file_path);
			token = strtok(NULL, ":");
		}
	}
	else
		return (buffer);
	return (NULL);
}
