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
			/* Gère la condition Ctrl+D (fin de fichier) */
			printf("\nFermeture du Shell.\n");
			break;
		}

		/* Supprime le caratère de nouvelle ligne à la fin */
		input[strlen(input) - 1] = '\0';

		if (!input[0])
		{
			/* Gère la commande vide (simplement appuyer sur Entrée) */
			continue;
		}
		
		if (strcmp(input, "exit") == 0)
		{
			/*Quitter le shell si l'utilisateur tape 'exit' */
			printf("Fermeture du Shell. \n");
			break;
		}
		else if (strcmp(input, "ls") == 0)
		{
			/*Exécute la commande 'ls' */
			char *args[] = {"/bin/ls", NULL};
			execute_command("/bin/ls", args);
		}
		else if (strcmp(input, "pwd") == 0)
		{
			/*Execute la commande 'pwd' */
			char *args[] = {input, NULL};
			execute_command(input, args);
		}
	}
}

void display_prompt(void)

{
	printf("Votre Shell > ");
	fflush(stdout);
}

void execute_command(char *command, char *args[])
{
	/* Vérifier si la commande existe dans le PATH */
	if (access(command, X_OK) == -1)
	{
		perror("Erreur de fork");
		return;
	}

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Erreur de fork");
		exit(EXIT_FAILURE);
	}
	else if (pid ==0)
	{
     if (execvp(command, args) == -1)
     { 
perror("Erreur")
exit(EXIT_FAILURE);
     }
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
