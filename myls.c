#include "main.h"

/* +2 for the executable path and NULL at the end */
char *args[MAX_INPUT_SIZE + 2];

int myls_main(int argc, char *argv[])
{
    int i;

    /* Prepare arguments for execvp */
    args[0] = "/bin/ls";

    for (i = 1; i < argc; i++)
    {
        args[i] = argv[i];
    }

    args[argc] = NULL;

    /* Execute the "ls" command with the provided arguments */
    if (execvp("/bin/ls", args) == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}

