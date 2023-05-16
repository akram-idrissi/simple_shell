#include "tasks.h"

/**
 * parse_command - Parses a command into separate arguments
 * @command: The command to parse
 * @args: An array to store the parsed arguments
 * Return: The number of parsed arguments
 */
int parse_command(const char *command, char **args)
{
	int num_args = 0;
	char *token;
	char *command_copy = strdup(command);

	token = strtok(command_copy, " ");

	while (token != NULL)
	{
		args[num_args] = strdup(token);
		num_args++;

		token = strtok(NULL, " ");
	}

	args[num_args] = NULL;

	free(command_copy);

	return (num_args);
}
