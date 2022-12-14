#include "main.h"

/**
 * xcuteFunc - executea function
 * @string: string to compare
 * @array: array to compare
 * @pcount: pointer to counter
 * Return: 0
 */

int xcuteFunc(char *string, char **array, int *pcount)
{
	int rturnV;
	int pcount2;

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
		pcount2 = *pcount;
		pcount2++;
		*pcount = pcount2;
	}
	else
	{
		pcount2 = *pcount;
		pcount2++;
		*pcount = pcount2;
		fprintf(stderr, "./hsh: %d: %s: not found\n", pcount2, array[0]);
		rturnV = 127;
	}
	return (rturnV);
}
