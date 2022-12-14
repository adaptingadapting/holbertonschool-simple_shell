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
	{
		if ((stat(line, &st) == 0) && st.st_mode == 33261)
			return (line);
		return (NULL);
	}
	cp = malloc(_strlen(i) + 1);
	cp2 = malloc(_strlen(line) + 1);
	duptoken = malloc(_strlen(i) + _strlen(line) + 1);
	if ((stat(line, &st) == 0) && st.st_mode == 33261)
	{
		free4(cp, i, cp2, duptoken);
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
			free3(i, cp, cp2);
			return (duptoken);
		}
		token = strtok(NULL, ":");
	}
	free4(i, cp, cp2, duptoken);
	return (NULL);
}
