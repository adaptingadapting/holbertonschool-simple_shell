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
	char delim[] = {" \n:\t"};
	char *userInput = NULL;
	char *string = NULL;
	char *token[80] = {0};
	size_t buffsize = 0;

loop:
	for (;;)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(0, "$ ", 2);
		if (getline(&userInput, &buffsize, stdin) == (-1))
		{
			if (userInput)
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
		xcuteFunc(string, token);
	}
	return (0);
}
