#ifndef __SIMPLE__SHELL__H__
#define __SIMPLE__SHELL__H__

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
void execute_command(char *buffer);

#endif
