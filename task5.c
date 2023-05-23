#include "tasks.h"

/**
 * print_environment - Print the current environment variables.
 */
void print_environment(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
