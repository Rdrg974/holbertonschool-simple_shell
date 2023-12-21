#include "main.h"

int cd_command(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: cd <directory>\n");
        return EXIT_FAILURE;
    }

    if (chdir(argv[1]) != 0) {
        perror("cd error");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
