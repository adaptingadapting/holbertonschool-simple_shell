#include "main.h"

/**
 * tokenize - toeknizes a string
 * @token: token
 * @delim: delimitator
 * Return: string
 */

void tokenize(char **token, char *delim)
{
	int i;

	i = 0;
	while (token[i])
	{
		i++;
		token[i] = strtok(NULL, delim);
	}
}
