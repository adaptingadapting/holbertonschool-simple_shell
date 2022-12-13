#include "main.h"

/**
 * xcuteFunc - executea function
 * @string: string to compare
 * @array: array to compare
 * Return: 0
 */

int xcuteFunc(char *string, char **array)
{
	int rturnV;

	if (string)
	{
		if (!(_strcmp(array[0], string)))
			rturnV = executePathProgram(array);
		else
		{
			array[0] = string;
			rturnV = executePathProgram(array);
			free(string);
		}
	}
	else
	{
		fprintf(stderr, "%s: not found\n", array[0]);
		rturnV = 127;
	}
	return (rturnV);
}
