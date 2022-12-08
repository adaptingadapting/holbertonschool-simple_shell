#include "main.h"

/**
 * xcuteFunc - executea function
 * @string: string to compare
 * @array: array to compare
 * Retrun: 0
 */

void xcuteFunc(char *string, char **array)
{
	if (string)
	{
		if (!(strcmp(array[0], string)))
			executePathProgram(array);
		else
		{
			array[0] = string;
			executePathProgram(array);
			free(string);
		}
	}
	else
		printf("Command not found\n");
}
