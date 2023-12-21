#include "main.h"

void pwd(void)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "%s\n", cwd);
    else
        perror("getcwd() error");
}

