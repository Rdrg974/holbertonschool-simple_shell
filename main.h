#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PATH_SIZE 1024

void display_prompt(void);
void execute_command(char *command, char *args[]);
void simple_shell(void);
char *get_path(void);

#endif
