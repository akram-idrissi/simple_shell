#ifndef TASK1_H
#define TASK1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void display_prompt(void);
int parse_comand(const char *command, char **args);
int read_command(char **command, size_t *bufsize);
void execute_command(const char *command, char **args);
#endif
