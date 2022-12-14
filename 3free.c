#include "main.h"

/**
 * free3 - frees 3 strings
 * @str1: string
 * @str2: string2
 * @str3: string3
 */

void free3(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
}
