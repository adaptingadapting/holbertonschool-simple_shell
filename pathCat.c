#include "main.h"

/**
 * programStat - Checks for the existence of program
 * @line: starting string
 * Return: Return string
 */

char *programStat(char *line)
{
	char *token;
	char *i = _getenv("PATH");
	char *cp, *cp2, *duptoken;
	struct stat st;

	if (!(i))
		return (NULL);
	cp = malloc(_strlen(i) + 1);
	cp2 = malloc(_strlen(line) + 1);
	duptoken = malloc(_strlen(i) + _strlen(line) + 1);
	if ((stat(line, &st) == 0) && st.st_mode == 33261)
	{
		free(i);
		free(cp);
		free(cp2);
		free(duptoken);
		return (line);
	}
	_strcpy(cp, i);
	_strcpy(cp2, line);
	token = strtok(cp, ":");
	while (token)
	{
		_strcpy(duptoken, token);
		_strcat(duptoken, "/");
		_strcat(duptoken, cp2);
		if ((stat(duptoken, &st) == 0) && st.st_mode == 33261)
		{
			free(i);
			free(cp);
			free(cp2);
			return (duptoken);
		}
		token = strtok(NULL, ":");
	}
	free(cp);
	free(i);
	free(cp2);
	free(duptoken);
	return (NULL);
}
