#include "main.h"

/**
 * prompt - Affiche un prompt de ligne de commande
 *
 * Cette fonction affiche un simple prompt en ligne de commande, en imprimant
 * "$ " suivi d'un espace. Elle utilise également fflush(stdout) pour vider
 * immédiatement le tampon de sortie, garantissant que le prompt est affiché
 * instantanément plutôt que d'attendre que le tampon se vide naturellement.
 */

void prompt(void)
{
	printf("$ ");
	/* Assure que le tampon de sortie est vidé directement */
	fflush(stdout);
}


/**
 * execute_cmd - Fonction pour exécuter une commande système
 * @command : La commande à exécuter
 */

void execute_cmd(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* processus enfant */
	{
		execlp(command, command, (char *)NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else /* processus parent */
	{
		/* Attend que le processus enfant se termine */
		waitpid(pid, NULL, 0);
	}
}
