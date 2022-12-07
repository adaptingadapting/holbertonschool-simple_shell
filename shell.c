#include<sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Simple shell program
 * Return: Characters
 */

int main(void)
{
	int i;
	char delim[] = {" \n:\t"};
	char *token[80] = {0};
	char *userInput = NULL;
	size_t buffsize = 0;

loop:
	for (;;)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(0, "$ ", 2);
		if (getline(&userInput, &buffsize, stdin) == (-1))
		{
			free(userInput);
			return (-1);
		}
		token[0] = strtok(userInput, delim);
		if (!token[0])
			goto loop;
		if (!strcmp(token[0], "exit"))
		{
			free(userInput);
			exit(0);
		}
		i = 0;
		while (token[i])
		{
			i++;
			token[i] = strtok(NULL, delim);
		}
		if (programStat(token[0]))
		{
			token[0] = programStat(token[0]);
			executePathProgram(token);
		}
		else
			printf("Command not found\n");
	}
	return (0);
}
