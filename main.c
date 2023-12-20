#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - Fonction principale du programme shell basique
 *
 * Ce programme est un shell simple qui attend continuellement une entrée
 * utilisateur, l'exécute comme une commande système tant que l'utilisateur
 * ne tape pas "exit", et affiche un prompt de commande.
 *
 * Return: 0 en cas de succès, valeur d'échec autrement
 */

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	size_t command_length;

	while (1)
	{
		prompt();
		/* lis la command que l'utilisateur tape avec un getline */
		if (getline(&command, &command_size, stdin) == -1)
		{
			printf("\n");
			free(command);
			break;
		}
		/* Supprimez le caractère de saut de ligne à la fin */
		command_length = strlen(command);
		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}
		/* Verifi si la commande exit est la */
		if (strcmp(command, "exit") == 0)
		{
			printf("Exiting the shell.\n");
			free(command);
			break;
		}
		/* Execute la commande */
		execute_cmd(command);
	}
	/* Libére la mémoire dynamique allouée */
	free(command);

	return (0);
}
