#include "main.h"

/* +2 pour le chemin de l'exécutable et NULL à la fin */
char *args[MAX_INPUT_SIZE + 2];

int main(int argc, char *argv[])
{
    int i;  /* Déplacez la déclaration de la variable ici */

    /* Préparez les arguments pour execvp */
    args[0] = "/bin/ls";

    for (i = 1; i < argc; i++)
    {
        args[i] = argv[i];
    }

    args[argc] = NULL;

    /* Exécutez la commande "ls" avec les arguments fournis */
    if (execvp("/bin/ls", args) == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}

