#include "tasks.h"

/**
 * main - Entry point of the shell program
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	int command_read;

	while (1)
	{
		char *token;
		char *args[100];
		int num_args = 0;

		command_read = read_command(&command, &bufsize);
		if (command_read == 0)
			break;

		token = strtok(command, " ");

		while (token != NULL)
		{
			args[num_args] = token;
			num_args++;

			token = strtok(NULL, " ");
		}

		args[num_args] = NULL;

		if (access(args[0], X_OK) == 0)
			execute_command(args[0], args);
		else
			printf("No such file or directory: %s\n", args[0]);
	}

	free(command);

	return (EXIT_SUCCESS);
}
