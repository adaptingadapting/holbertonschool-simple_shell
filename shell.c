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
	char *userInput, *string, *token[80] = {0};
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
		tokenize(token, delim);
		string = programStat(token[0]);
		if (string)
		{
			token[0] = string;
			executePathProgram(token);
			free(string);
		}
		else
		{
			free(string);
			printf("Command not found\n");
		}
	}
	return (0);
}
