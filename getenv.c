#include "main.h"

/**
 * _getenv - get and environment var
 * @str: string
 * Return: pointer to tring
 */

char *_getenv(char *str)
{
	int i;
	char *buffer = NULL;
	char *token[4] = {0};
	char *rturnString;

	for (i = 0; environ[i]; i++)
	{
		buffer = malloc(_strlen(environ[i]) + 1);
		if (environ[i])
		{
			_strcpy(buffer, environ[i]);
			token[0] = strtok(buffer, "=\n");
			if (!(_strcmp(token[0], str)))
			{
				token[1] = strtok(NULL, "=\n");
				if (token[1])
				{
					rturnString = malloc(_strlen(token[1]) + 1);
					_strcpy(rturnString, token[1]);
					free(buffer);
					return (rturnString);
				}
				else
				{
					free(buffer);
					return (NULL);
				}
			}
			free(buffer);
		}
	}
	return (NULL);
}
