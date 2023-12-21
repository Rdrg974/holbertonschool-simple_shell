#include "main.h"

char input[MAX_INPUT_SIZE];

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
            /* Handle Ctrl+D (end of file or read error) condition */
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
        else if (strcmp(input, "pwd") == 0)
        {
            /* Execute the command "pwd" */
            pwd();
        }
        else
        {
            /* Execute other commands */
            char *args[] = {input, NULL};
            execute_command("/bin/ls", args);
        }
    }
}

void display_prompt(void)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s > ", cwd);
    else
        perror("getcwd() error");
    fflush(stdout);
}

void execute_command(char *command, char *args[])
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

































































