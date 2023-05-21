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

		if (strcmp(args[0], "exit") == 0)
			exit_shell();

		execute_command(args[0], args);
	}

	free(command);

	return (EXIT_SUCCESS);
}
