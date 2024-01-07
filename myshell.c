#include "main.h"

/**
 *execute_command - Execute a command with the provided arguments
 *@command: The command to execute
 *@status: The exit status
 *@program_name: The name of the program
 *@command_count: The command count
 *Return: Nothing
 */
void execute_command(char *command, int *status,
		char *program_name, int *command_count)
{
	char =args[2];
	pid_t pid = fork();

	if (pid < 0)
	{
		free(command);
		perror("Erreur de fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		(*command_count)++;
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, environ) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
					program_name *command_count, command);
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(status);
}

/**
 *display_prompt - Display a prompt
 *@interactive: 1 if the shell is interactive, 0 otherwhise
 *Return: Nothing
 */
void display_prompt(int interactive)
{
	if (interactive)
	{
		printf("Votre shell > ");
		fflush(stdout);
	};
}

/**
 * eof - Handle the EOF condition
 * @read: The return value of getline
 * @input: The input string
 * @status: The exit status
 * return: Nothing
 */
void eof(ssize_t read, char *input, int status)
{
	if (read == EOF)
	{
		free(input);
		/* Gère la condition CTRL+D */
		printf("\nFermeture du Shell. \n");
		exit(status);
	};
}

/**
 * simple_shell - A simple shell implementation
 * @argv: The arguments
 * Reurn: Nothing
 * */
void simple_shell(char *argv[])
{
	ssize_t read = 0;
	size_t len = 0;
	char *input = NULL;
	int interactive = isatty(STDIN_FILENO);
	char *program_name = argv[0];
	int command_count = 0;
	int status = EXIT_SUCCESS;

	while (read != EOF)
	{
		display_prompt(interactive);
		read = getline(&input, &len, stdin);
		eof(read, input, status);
		if (strcmp(input, "\n") == 0)
			continue;
		input[strlen(input) - 1] = '\0';
		if (is_custom_command(input, status))
			continue;
		else
			execute_command(input, &status, program_name, &command_count);
	}
}

/**
 * main - The entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 * Return: Always 0
 * */
int main(int argc, char *argv[])
{
	(void)argc;
	simple_shell(argv);
	return (0);
}
