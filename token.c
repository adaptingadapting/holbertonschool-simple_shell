#include "main.h"

/**
 * programStat - Checks for the existence of program
 * @line: starting string
 * Return: Return string
 */

char *programStat(char *line)
{
	char *token, *freeCp, *freeCp2;
	char *i = getenv("PATH");
	char *cp = freeCp = malloc(200);
	char *cp2 = freeCp2 = malloc(200);
	char *duptoken = malloc(300);
	struct stat st;

	if (stat(line, &st) == 0)
		return (line);
	strcpy(cp, i);
	strcpy(cp2, line);
	token = strtok(cp, ":");
	while (token)
	{
		strcpy(duptoken, token);
		strcat(duptoken, "/");
		strcat(duptoken, cp2);
		if (stat(duptoken, &st) == 0)
		{
			return (duptoken);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
