#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

/**
 * struct dir_entry - representing a directory entry
 * @dir: Pointer to a string representing the directory path
 */
typedef struct dir_entry
{
	char *dir;
} dir_entry;

void display_prompt(void);
int read_command(char **command, size_t *bufsize);
int parse_command(const char *command, char **args);
void execute_command(const char *command, char **args);

#endif
