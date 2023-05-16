#include "tasks.h"

/**
 * display_prompt - displays the shell prompt
 */
void display_prompt(void)
{
	printf("Shell> ");
}

/**
 * read_command - reads a command from the user
 * @command: A pointer to store the user input
 * @bufsize: A pointer to store the size of the buffer
 * Return: The number of characters read
 */
int read_command(char **command, size_t *bufsize)
{
	ssize_t characters_read;

	*command = NULL;
	*bufsize = 0;

	display_prompt();
	characters_read = getline(command, bufsize, stdin);
	if (characters_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			return (0);
		} else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	} else
	{
		(*command)[characters_read - 1] = '\0';
		return (1);
	}
}
/**
 * execute_command - Executes a command by forking a child process
 * @command: The command to execute
 * @args: The command argument
 */
void execute_command(const char *command, char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execvp(command, args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(NULL);
	}
}
