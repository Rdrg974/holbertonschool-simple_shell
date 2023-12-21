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

char **get_argument(char *buffer);
char *get_path(char *buffer);
void free_args(char **args);
void execute_command(char **array_argument, int nbr_command);
char *_getenv(const char *name);

#endif
