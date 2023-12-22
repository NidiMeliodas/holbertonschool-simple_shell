#include "main.h"


/**
 * _err - checks and handles errors
 * @args: arguments to check
 * Return: void
 */

void _err(char *args[])
{
	fprintf(stderr, "%s: command not found\n", args[0]);
	perror("");
	free(args[0]);
	exit(98);
}


/**
 * exec - executes the input received
 * @args: arguments
 * @input: input
 * Return: void
 */

void exec(char **args, char *input)
{

	int status, statusExit;
	pid_t childPid = 0;

	if (access(args[0], X_OK) != 0)
		_err(args);

	childPid = fork();

	if (childPid == -1)
	{
		perror("fork\n");
		free(input);
		exit(0);
	}
	else if (childPid == 0)
	{
		execve(args[0], args, environ);
		free(args[0]);
		exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			statusExit = WEXITSTATUS(status);
			if (statusExit != 0)
			{
				free(args[0]);
				free(input);
				exit(0);
			}
		}
	}
}

/**
 * printEnv - print the environment variables
 * Return: void
 */

void printEnv(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

/**
 * tokenize - function that splits a string into multiple ones
 * @input: users input
 * @args: arguments
 * Return: void
 */

void tokenize(char *input, char *args[])
{
	char *token;
	unsigned int i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] == NULL)
		exit(0);

	if (strcmp(input, "env") == 0)
	{
		printEnv();
		return;
	}

	if (strcmp(input, "exit") == 0 && args[1] == NULL)
	{
		free(args[0]);
		exit(0);
	}

	token = strdup(args[0]);
	args[0] = handle_path(args[0]);
	if (args[0] != NULL)
	{
		free(token);
		exec(args, input);
		free(args[0]);
		return;
	}
	free(token);
	fprintf(stderr, "%s: command not found\n", args[0]);
	exit(127);
}

