#include "main.h"

/**
 *exit_shell - Exit the shell
 *@input The input string
 *@status; The exit status
 *Return: void
 */

void exit_shell(char *input, int status)
{
	free(input);
	exit(status):
}

/**
 *is_custom_command _ Check if the input is a custom command
 *@input: The input string
 *@status: The exit status
 *Return: 1 if the input is a custom commad, 0 otherwise
 */

int is_custom_command(char *input, int status)
{
	custom_cmd_t commands[] = {
		{"exit", exit_shell},
		/* {"env", print_env}, */
		{NULL, NULL}
	};
	int i = 0;

	while (commands[i].name)
	{
		if (strcmp(input, command[i].name) == 0)
		{
			commands[i].func(input, status);
			return (1);
		};
		i++;
	}
	return(0);
}
