#include "simple_shell.h"

/**
 * _getenv - searches for the environment string pointed
 * @name: containing the name of the requested variable
 * Return: the associated value to the string
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	if (name == NULL || environ == NULL)
		return (NULL);
	for (env = environ; *env != NULL; env++)
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (*env + name_len + 1);
	return (NULL);
}
