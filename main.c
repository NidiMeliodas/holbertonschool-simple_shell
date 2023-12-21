#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void prompt() {
	printf("$ ");
	fflush(stdout);
}

void execute_cmd(char *command) {
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		/* Child process */
		execlp(command, command, (char *)NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	} else {
		/* Parent process */
		waitpid(pid, NULL, 0);
	}
}

int main() {
	char *command = NULL;
	size_t command_size = 0;
	size_t command_length;

		while (1) {
			prompt();

			/* Read the command from the user using getline */
			if (getline(&command, &command_size, stdin) == -1) {
				/* Handle end-of-file (Ctrl+D) */
				printf("\n");
				free(command);
				break;
			}

			/* Remove the newline character at the end */
			command_length = strlen(command);
			if (command_length > 0 && command[command_length - 1] == '\n') {
				command[command_length - 1] = '\0';
			}

			/* Check for "exit" command */
			if (strcmp(command, "exit") == 0) {
				printf("Exiting the shell.\n");
				free(command);
				break;
			}

			/* Execute the command */
			execute_cmd(command);
		}

	/* Free the dynamically allocated memory */
	free(command);

	return 0;
}

