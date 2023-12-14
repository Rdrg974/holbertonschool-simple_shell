#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

extern char *args[];

void display_prompt(void);
void execute_command(char *command, char *args[]);
void simple_shell(void);

#endif
