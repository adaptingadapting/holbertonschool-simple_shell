#include "main.h"

/**
 * main - Simple shell program
 * Return: Characters
 */

int main(void)
{
	char delim[] = {" \n\t"};
	char *userInput = NULL;
	char *string = NULL;
	char *token[80] = {0};
	size_t buffsize = 0;
	int olde = 0;
	int count = 0;
	int *pcount = &count;

	signal(SIGINT, sigintHandler);
loop:
	for (;;)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(0, "$ ", 2);
		if (getline(&userInput, &buffsize, stdin) == (-1))
		{
			if (userInput)
				free(userInput);
			exit(olde);
		}
		token[0] = strtok(userInput, delim);
		if (!token[0])
			goto loop;
		if (!_strcmp(token[0], "exit"))
		{
			free(userInput);
			exit(olde);
		}
		tokenize(token, delim);
		string = programStat(token[0]);
		olde = xcuteFunc(string, token, pcount);
	}
}
