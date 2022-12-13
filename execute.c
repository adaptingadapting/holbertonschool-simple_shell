
#include "main.h"

/**
 * executePathProgram - executes a program
 * @token: an array of pointers to strings
 * Return: status
 */

int executePathProgram(char **token)
{
	int status;
	pid_t pid;
	int exit_status;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid > 0)
	{
		wait(&status);
		exit_status = WEXITSTATUS(status);
	}
	else
	{
		if (execve(token[0], token, environ) == -1)
		{
			exit(EXIT_FAILURE);
		}

	}
	return (exit_status);
}

