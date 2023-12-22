#ifndef __SIMPLE__SHELL__H__
#define __SIMPLE__SHELL__H__

#define MAX_ARGS 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **get_argument(char *line);
char *get_path(char *line);
void free_args(char **array_command);
void execute_command(char **array_command, int nbr_command);
char *_getenv(const char *name);

#endif
