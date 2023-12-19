#include "main.h"

char input[MAX_INPUT_SIZE];
char *args[MAX_INPUT_SIZE + 1]; /* +1 for NULL at the end */

int main(void)
{
    simple_shell();
    return 0;
}

void simple_shell(void)
{
    while (1)
    {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            /* Handle Ctrl+D (end of file) condition */
            printf("\nExiting shell.\n");
            break;
        }

        /* Remove the newline character at the end */
        input[strlen(input) - 1] = '\0';

        if (!input[0])
        {
            /* Handle empty command (just pressing Enter) */
            continue;
        }

        if (strcmp(input, "exit") == 0)
        {
            /* Exit the shell if the user types 'exit' */
            break;
        }
        else
        {
            /* Execute other commands */
<<<<<<< HEAD
            args[0] = input;
            args[1] = NULL;
            execute_command("/bin/ls");
=======
            char *args[] = {input, NULL};
            execute_command("/bin/ls", args);
>>>>>>> 7fbbdad0521103aa68909135769d9f06a28b4a76
        }
    }
}

void display_prompt(void)
{
    printf("Your Shell > ");
    fflush(stdout);
}

void execute_command(char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) /* Child process */
    {
        if (execvp(command, args) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        /* Wait for the child process to complete */
        waitpid(pid, NULL, 0);
    }
}

