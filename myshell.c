#include "main.h"

char input[MAX_INPUT_SIZE];
char *args[MAX_INPUT_SIZE + 2];

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
        else if (strcmp(input, "env") == 0)
        {
            /* Execute the 'env' command */
            char *args_env[] = {"env", NULL};
            execute_command("/usr/bin/env", args_env);
        else if (strcmp(input, "pwd") == 0)
        {
            /* Execute the command "pwd" */
            pwd();
        }
        else
        {
            /* Execute other commands */
            args[0] = input;
            args[1] = NULL;
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
        char *path = get_path();
        char *token;
        char path_copy[MAX_PATH_SIZE];
        char full_path[MAX_PATH_SIZE];

        if (path == NULL)
        {
            perror("Error getting PATH");
            exit(EXIT_FAILURE);
        }

        /* Copy the PATH for tokenization */
        strcpy(path_copy, path);

        /* Tokenize the PATH to find the executable */
        token = strtok(path_copy, ":");

        while (token != NULL)
        {
            /* Construct the full path to the executable */
            snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

            /* Execute the command if found */
            if (access(full_path, X_OK) == 0)
            {
                if (execvp(full_path, args) == -1)
                {
                    perror("Error");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            /* Move to the next directory in PATH */
            token = strtok(NULL, ":");
        }

        /* If the command is not found in any directory */
        fprintf(stderr, "Command not found: %s\n", command);
        exit(EXIT_FAILURE);
    }
    else /* Parent process */
    {
        /* Wait for the child process to complete */
        waitpid(pid, NULL, 0);
    }
}

char *get_path(void)
{
    char **env;
    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            return *env + 5;
        }
    }
    return NULL;
}































































>>>>>>> ae718ac63e3fbcee56ef5dc8344c8a6c3c3f128b

