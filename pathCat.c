#include "main.h"

/**
 * programStat - Checks for the existence of program
 * @line: starting string
 * Return: Return string
 */

char *programStat(char *line)
{
	char *token, *i;
	char *cp, *cp2, *duptoken;
	struct stat st;

	if (!_strcmp(line, "env"))
		return ("/usr/bin/env");
	i =  _getenv("PATH");
	if (!(i))
	{
	if ((stat(line, &st) == 0) && st.st_mode == 33261)
		return (line);
	else
		return (NULL);
	}
	else
	{
		cp = malloc(_strlen(i) + 1), cp2 = malloc(_strlen(line) + 1);
		duptoken = malloc(_strlen(i) + _strlen(line) + 1);
	}
	if ((stat(line, &st) == 0) && st.st_mode == 33261)
	{
		free4(cp, i, cp2, duptoken);
		return (line);
	}
	if (i)
		_strcpy(cp, i);
	_strcpy(cp2, line), token = strtok(cp, ":");
	while (token)
	{
		_strcpy(duptoken, token);
		_strcat(duptoken, "/"), _strcat(duptoken, cp2);
		if ((stat(duptoken, &st) == 0) && st.st_mode == 33261)
		{
			free3(i, cp, cp2);
			return (duptoken);
		}
		token = strtok(NULL, ":");
	}
	free4(i, cp, cp2, duptoken);
	return (NULL);
}
