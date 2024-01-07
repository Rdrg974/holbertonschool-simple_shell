#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PATH_SIZE 1024
extern char **environ;

/**
 * struct custom_cmd - A custom command
 * @name: The name of the command
 * @func: The function to execute
 */

typedef struct custom_cmd
{
	char *name;
	void (*func)(char *input, int status);
} custom_cmd_t;

/* char *get_path(void); */
int is_custom_command(char *input, int status);

#endif
