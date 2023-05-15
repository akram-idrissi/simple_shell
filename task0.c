#include "task0.h"

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
	characters_read	= getline(commande, bufsize, stdin);
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
 */
void execute_command(const char *command)
{

	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(Exit_FAILURE);

	} else if (pid == 0)
	{
		if (execlp(command, args, NULL) == -1)
		{
			perror("exec");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(NULL);
	}
}
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
		command_read = read_command(&command, &bufsize);
		if (command_read == 0)
			break;

		if (access(command, X_OK) == 0)
			execute_command(command);
		else
			printf("No such file or directory %s\n", command);
	}

	free(command);

	return (EXIT_SUCCESS);
}
